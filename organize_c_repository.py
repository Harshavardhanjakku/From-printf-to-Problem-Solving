#!/usr/bin/env python3
"""
Analyze C source files locally, rename, categorize, and migrate into Organized_C_Programs/.
"""
from __future__ import annotations

import csv
import hashlib
import os
import re
import shutil
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(r"D:\personal\From printf() to Problem Solving")
ORG_ROOT = ROOT / "Organized_C_Programs"
PREVIEW_CSV = ROOT / "preview_20_files.csv"
MIGRATION_CSV = ROOT / "migration_report.csv"

CATEGORIES = [
    "Basics", "Patterns", "Functions", "Arrays", "Strings", "Pointers",
    "Recursion", "Structures", "Dynamic_Memory", "Searching", "Sorting",
    "Linked_Lists", "Trees", "Graphs", "Greedy", "Mini_Projects",
    "Mathematics", "Miscellaneous",
]

BANNED_NAMES = {
    "program.c", "example.c", "practice.c", "solution.c", "calculator.c",
    "series.c", "test.c", "temp.c", "experiment.c", "code.c",
    "series_sum.c", "math_program.c", "number_problem.c",
}


@dataclass
class Classification:
    category: str
    filename: str
    confidence: int = 0


def read_code(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8", errors="ignore")
    except OSError:
        return ""


def normalize_code(code: str) -> str:
    code = re.sub(r"/\*.*?\*/", "", code, flags=re.S)
    code = re.sub(r"//.*?$", "", code, flags=re.M)
    code = re.sub(r"\s+", "", code)
    return code.lower()


def content_hash(code: str) -> str:
    return hashlib.md5(normalize_code(code).encode()).hexdigest()[:4]


def canonical_stem(filename: str, code: str | None = None) -> str:
    """Return the base repository stem (no duplicate-resolution suffixes)."""
    if code:
        filename = classify(code).filename
    stem = filename[:-2] if filename.lower().endswith(".c") else filename
    parts = stem.split("_")
    cleaned: list[str] = []
    for part in parts:
        if re.fullmatch(r"[a-f0-9]{4}", part):
            continue
        if re.fullmatch(r"v\d+", part):
            continue
        cleaned.append(part)
    return "_".join(cleaned) if cleaned else stem


def count_functions(code: str) -> int:
    return len(
        re.findall(
            r"^\s*(?:void|int|float|double|char|long|short|unsigned)\s+\w+\s*\(",
            code,
            re.M | re.I,
        )
    )


def collect_implementation_traits(code: str, stem: str) -> list[str]:
    """Ordered trait tags for semantic duplicate suffixes (Steps 1–4)."""
    lower = code.lower()
    traits: list[str] = []
    rec = count_recursive_functions(code)

    # Step 1 — algorithm differences
    if rec > 0:
        if "factorial" in lower:
            traits.append("recursive")
        elif "fibonacci" in lower or "fibanocci" in lower:
            traits.append("recursive")
        elif "binary" in lower and ("decimal" in lower or "base" in lower):
            traits.append("recursive")
        elif "digit" in lower:
            traits.append("recursive")
        elif "gcd" in lower or "hcf" in lower:
            traits.append("recursive")
        elif "hanoi" in lower:
            traits.append("recursive")
        elif "maze" in lower or "rat" in lower:
            traits.append("backtracking")
        else:
            traits.append("recursive")
    if "mid" in lower and "low" in lower and "high" in lower and rec == 0:
        traits.append("iterative")
    if "monthcode" in lower and "daycode" in lower:
        traits.append("zeller_algorithm")
    elif re.search(r"getdayofweek|t\[month\s*-\s*1\]", lower):
        traits.append("formula_based")
    if "bubble" in lower:
        traits.append("descending" if "descend" in lower else "ascending")
    elif re.search(r"a\[i-1\]\s*>\s*a\[i\]", lower) or re.search(
        r"a\[j\]\s*>\s*a\[j\+1\]", lower
    ):
        traits.append("descending" if "descend" in lower else "ascending")
    if "selection" in lower or "slection" in lower:
        traits.append("selection_sort")
    if "merge" in lower and "sort" in lower:
        traits.append("merge_sort")
    if "quick" in lower and "sort" in lower:
        traits.append("quick_sort")
    if "radix" in lower:
        traits.append("radix_sort")
    if "dijkstra" in lower or "dijstra" in lower:
        traits.append("dijkstra")
    if "kruskal" in lower:
        traits.append("kruskal")
    if re.search(r"\bprim(?:s|_)?\b", lower) and ("mst" in lower or "spanning" in lower):
        traits.append("prims")
    if "warshall" in lower or "warshal" in lower or "floyd" in lower:
        traits.append("floyd_warshall")
    if "sieve" in lower:
        traits.append("sieve")
    elif "prime" in stem and rec == 0 and "divisor" in lower:
        traits.append("trial_division")

    # Step 2 — data structure differences
    if re.search(r"struct\s+\w+[^;{]*\bnext\b", lower):
        traits.append("linked_list")
    elif "circular" in lower and ("next" in lower or "link" in lower):
        traits.append("circular_linked_list")
    if "malloc" in lower or "calloc" in lower:
        if "linked" not in traits:
            traits.append("dynamic_memory")
    if re.search(r"\w+\[\s*\d+\s*\]", code) and "struct" in lower:
        if "student" in stem or "management" in stem:
            traits.append("array_based")
    if "struct" in lower and ("management" in stem or "registration" in stem):
        if "linked_list" not in traits:
            traits.append("structure_based")
    if ("left" in lower and "right" in lower) and ("bst" in lower or "tree" in stem):
        traits.append("binary_tree")
    if "avl" in lower:
        traits.append("avl_tree")

    # Step 3 — program style
    if re.search(r"\bmenu\b", lower) or (
        "switch" in lower and lower.count("case") >= 4 and "scanf" in lower
    ):
        traits.append("menu_driven")
    if count_functions(code) >= 7:
        traits.append("modular")
    if "goto" in lower and re.search(r"\w+\s*:", code):
        traits.append("goto_based")
    if "clrscr" in lower or "#include<conio.h>" in lower.replace(" ", ""):
        traits.append("turboc_console")
    if len(re.findall(r"%[-+]?\d*d", code)) >= 4:
        traits.append("formatted_output")
    if "windows.h" in lower or "gotoxy" in lower:
        traits.append("enhanced_console")

    # Step 4 — features
    if "fopen" in lower or "fprintf" in lower or "fread" in lower:
        traits.append("file_storage")
    if "leap" in lower and "monthcode" not in lower and "daycode" not in lower:
        traits.append("leap_year_support")
    if re.search(r"for\s*\(\s*\w+\s*=\s*1\s*;\s*\w+\s*<=\s*12", lower):
        traits.append("full_year")
    elif "calendar" in stem and re.search(r"month\s*=\s*1\s*;\s*month\s*<=\s*12", lower):
        traits.append("full_year")
    if ("calendar" in stem or "calender" in stem) and "monthcode" in lower:
        if re.search(r"\bcalendar\s*:", lower):
            traits.append("interactive_loop")
        elif "goto" in lower:
            traits.append("goto_based")
        else:
            traits.append("single_run")
    if "event" in lower and "calendar" in stem:
        traits.append("event_management")
    if "search" in lower and "event" in lower:
        traits.append("event_search")
    if "comp" in lower and "board" in lower:
        traits.append("ai_opponent")
    if "matrix" in stem:
        if "mul" in lower and "add" not in lower:
            traits.append("multiplication_only")
        elif "add" in lower and "mul" not in lower:
            traits.append("addition_only")
        elif lower.count("case") >= 3:
            traits.append("full_suite")
    if "duplicate" in lower:
        traits.append("duplicate_detection")
    if "insert" in lower and "array" in stem:
        traits.append("insertion")

    lines = len([ln for ln in code.splitlines() if ln.strip()])
    if lines > 280:
        traits.append("enhanced")
    elif lines < 70 and "enhanced" not in traits:
        traits.append("basic")

    # De-duplicate while preserving order
    seen: set[str] = set()
    ordered: list[str] = []
    for t in traits:
        if t not in seen:
            seen.add(t)
            ordered.append(t)
    return ordered


SUFFIX_PRIORITY: list[str] = [
    "zeller_algorithm", "formula_based", "interactive_loop", "goto_based", "single_run",
    "recursive", "iterative", "backtracking",
    "dijkstra", "kruskal", "prims", "floyd_warshall", "sieve", "trial_division",
    "merge_sort", "quick_sort", "radix_sort", "selection_sort", "ascending", "descending",
    "avl_tree", "binary_tree", "circular_linked_list", "linked_list",
    "array_based", "structure_based", "dynamic_memory",
    "event_management", "event_search", "file_storage", "full_year", "monthwise",
    "leap_year_support", "duplicate_detection", "insertion",
    "multiplication_only", "addition_only", "full_suite",
    "menu_driven", "modular", "turboc_console", "formatted_output",
    "enhanced_console", "ai_opponent", "enhanced", "compact", "basic",
    "full_year", "monthwise", "leap_year_support",
]


def pick_semantic_suffix(
    traits: list[str],
    used_suffixes: set[str],
    code: str,
    stem: str,
) -> str | None:
    trait_set = set(traits)
    for candidate in SUFFIX_PRIORITY:
        if candidate in trait_set and candidate not in used_suffixes:
            return candidate
    for candidate in traits:
        if candidate not in used_suffixes:
            return candidate
    return None


def fingerprint_suffix(code: str, stem: str) -> str | None:
    """
    Build a composite suffix from implementation fingerprints when
    single-trait suffixes are exhausted (common for near-duplicate calendars).
    """
    lower = code.lower()
    parts: list[str] = []

    if "calendar" in stem or "calender" in stem:
        if "monthcode" in lower and "daycode" in lower:
            parts.append("zeller_algorithm")
        elif re.search(r"getdayofweek|t\[month", lower):
            parts.append("formula_based")
        if re.search(r"\bcalendar\s*:", lower):
            parts.append("interactive_loop")
        elif "goto" in lower:
            parts.append("goto_based")
        else:
            parts.append("single_run")
        if "clrscr" in lower:
            parts.append("turboc_console")
        if "welcome" in lower and "calendar" in lower:
            parts.append("welcome_screen")
        if "~~" in code:
            parts.append("formatted_header")
        if re.search(r"\bexit\b", lower) and "yes" in lower:
            parts.append("repeat_until_exit")
        lines = len([ln for ln in code.splitlines() if ln.strip()])
        if lines > 300:
            parts.append("extended")
        elif lines < 200:
            parts.append("compact")
    elif "management" in stem or "registration" in stem:
        if "fopen" in lower:
            parts.append("file_storage")
        if re.search(r"\bmenu\b", lower) or lower.count("case") >= 5:
            parts.append("menu_driven")
        if re.search(r"struct\s+\w+[^;{]*\bnext\b", lower):
            parts.append("linked_list")
        elif re.search(r"\[\s*\d+\s*\]", code):
            parts.append("array_based")
    elif "sort" in stem:
        if re.search(r"a\[i-1\]\s*>\s*a\[i\]", lower):
            parts.append("ascending" if "descend" not in lower else "descending")
        if "bubble" in lower:
            parts.append("bubble_sort")

    if not parts:
        return None
    unique: list[str] = []
    seen: set[str] = set()
    for part in parts:
        if part not in seen:
            seen.add(part)
            unique.append(part)
    composite = "_".join(unique[:4])
    return composite if composite else None


def build_filename(stem: str, suffix: str | None) -> str:
    if suffix:
        return sanitize_filename(f"{stem}_{suffix}.c")
    return sanitize_filename(f"{stem}.c")


def _allocate_unique_filename(
    category: str,
    stem: str,
    path: Path,
    code: str,
    used_targets: set[str],
    used_suffixes: set[str],
    *,
    force_suffix: bool,
    version_counter: list[int],
) -> str:
    """Pick a unique filename; hash only when semantics are exhausted."""
    traits = collect_implementation_traits(code, stem)
    suffix = pick_semantic_suffix(traits, used_suffixes, code, stem)
    composite = fingerprint_suffix(code, stem)
    if composite:
        for token in composite.split("_"):
            if token in used_suffixes:
                composite = None
                break

    if force_suffix and suffix is None:
        if composite and composite not in used_suffixes:
            suffix = composite
        else:
            version_counter[0] += 1
            suffix = f"v{version_counter[0]}"

    candidates: list[str | None] = []
    if not force_suffix:
        candidates.append(None)
    if suffix:
        candidates.append(suffix)
    if composite and composite not in candidates:
        candidates.append(composite)
    version_counter[0] += 1
    candidates.append(f"v{version_counter[0]}")
    candidates.append(content_hash(code))

    n_hash = 2
    for candidate in candidates:
        if candidate and candidate in used_suffixes and candidate not in (None,):
            continue
        fname = build_filename(stem, candidate)
        target = f"{category}/{fname}"
        if target not in used_targets:
            if candidate:
                used_suffixes.add(candidate)
            return fname
    while True:
        fname = build_filename(stem, f"{content_hash(code)}_{n_hash}")
        target = f"{category}/{fname}"
        if target not in used_targets:
            return fname
        n_hash += 1


def resolve_duplicates(
    assignments: list[tuple[Path, Classification, str]],
    codes: dict[Path, str] | None = None,
) -> list[tuple[Path, Classification, str]]:
    """
    Assign unique, human-readable filenames to colliding implementations.
    Hash suffixes are used only when no semantic distinction can be inferred.
    """
    if codes is None:
        codes = {p: read_code(p) for p, _, _ in assignments}

    groups: dict[tuple[str, str], list[tuple[Path, Classification, str]]] = defaultdict(list)
    for path, cls, h in assignments:
        stem = canonical_stem(cls.filename, codes[path])
        groups[(cls.category, stem)].append((path, cls, h))

    resolved: list[tuple[Path, Classification, str]] = []
    used_targets: set[str] = set()

    for (category, stem), items in sorted(groups.items()):
        by_hash: dict[str, list[tuple[Path, Classification, str]]] = defaultdict(list)
        for item in sorted(items, key=lambda x: x[2]):
            by_hash[item[2]].append(item)

        force_suffix = len(items) > 1
        used_suffixes: set[str] = set()
        version_counter = [0]

        for bucket in by_hash.values():
            for idx, (path, cls, file_h) in enumerate(bucket):
                code = codes[path]
                is_duplicate_copy = len(bucket) > 1 and idx > 0
                fname = _allocate_unique_filename(
                    category,
                    stem,
                    path,
                    code,
                    used_targets,
                    used_suffixes,
                    force_suffix=force_suffix or is_duplicate_copy,
                    version_counter=version_counter,
                )
                if is_duplicate_copy and not fname.endswith("_v2.c"):
                    # True duplicate — prefer explicit version labels
                    version_counter[0] += 1
                    ver = f"v{version_counter[0]}"
                    while ver in used_suffixes:
                        version_counter[0] += 1
                        ver = f"v{version_counter[0]}"
                    used_suffixes.add(ver)
                    fname = build_filename(stem, ver)
                    target = f"{category}/{fname}"
                    while target in used_targets:
                        version_counter[0] += 1
                        fname = build_filename(stem, f"v{version_counter[0]}")
                        target = f"{category}/{fname}"

                target = f"{category}/{fname}"
                while target in used_targets:
                    version_counter[0] += 1
                    fname = build_filename(stem, f"v{version_counter[0]}")
                    target = f"{category}/{fname}"
                used_targets.add(target)
                resolved.append(
                    (path, Classification(category, fname, cls.confidence), file_h)
                )

    return resolved


def sanitize_filename(name: str) -> str:
    name = name.strip().lower().replace("-", "_").replace(" ", "_")
    name = re.sub(r"[^a-z0-9_.]", "", name)
    if not name.endswith(".c"):
        name += ".c" if not name.endswith("c") else ".c"
    if not name.endswith(".c"):
        name = name.rstrip(".") + ".c"
    name = re.sub(r"_+", "_", name)
    if name in BANNED_NAMES or name in {"calculator.c", "series_sum.c"}:
        name = "misc_" + name
    return name


def load_preview() -> dict[str, tuple[str, str]]:
    """basename -> (category, filename)"""
    out: dict[str, tuple[str, str]] = {}
    if not PREVIEW_CSV.exists():
        return out
    with PREVIEW_CSV.open(encoding="utf-8", newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            if row.get("category") == "ERROR":
                continue
            fn = row.get("new_filename", "").strip()
            cat = row.get("category", "").strip()
            if fn and cat in CATEGORIES:
                out[row["original_name"].strip()] = (cat, sanitize_filename(fn))
    return out


def count_recursive_functions(code: str) -> int:
    lower = code.lower()
    names = re.findall(r"\b([a-z_][a-z0-9_]*)\s*\([^)]*\)\s*\{", lower, re.I)
    rec = 0
    for n in set(names):
        if n in {"if", "while", "for", "switch", "main"}:
            continue
        body_pat = rf"\b{re.escape(n)}\s*\("
        if len(re.findall(body_pat, lower)) >= 2:
            rec += 1
    return rec


def extract_printfs(code: str) -> str:
    return " ".join(re.findall(r'printf\s*\(\s*"([^"]*)"', code, re.I)).lower()


def classify(code: str) -> Classification:
    lower = code.lower()
    norm = normalize_code(code)
    prints = extract_printfs(code)
    rec_count = count_recursive_functions(code)

    rules: list[tuple[int, str, str, bool]] = []

    def add(score: int, cat: str, fname: str, cond: bool):
        if cond:
            rules.append((score, cat, fname, True))

    # --- Mini projects & games ---
    add(100, "Mini_Projects", "tic_tac_toe_game.c",
        "board[" in lower and ("tic" in lower or "x-o" in prints or "play with" in prints))
    add(98, "Mini_Projects", "atm_simulation.c",
        "atm" in lower or "withdraw" in prints and "balance" in prints)
    add(98, "Mini_Projects", "student_management_system.c",
        "student" in lower and ("struct" in lower) and ("menu" in lower or "record" in lower))
    add(98, "Mini_Projects", "student_registration_system.c",
        "registration" in lower or ("register" in prints and "student" in lower))
    add(97, "Mini_Projects", "university_management_system.c",
        "university" in lower or ("admission" in lower and "library" in lower))
    add(96, "Mini_Projects", "calendar_event_manager.c",
        "event" in lower and "calendar" in lower and ("linked" in lower or "list" in lower))
    add(95, "Mini_Projects", "yearly_calendar_generator.c",
        "calendar" in lower or "calender" in lower)
    add(94, "Mini_Projects", "cricket_score_management.c", "cricket" in lower)
    add(93, "Mini_Projects", "contact_management_system.c",
        "contact" in lower and "struct" in lower)

    # --- Graphs ---
    add(100, "Graphs", "kruskal_minimum_spanning_tree.c", "kruskal" in lower)
    add(100, "Graphs", "prims_minimum_spanning_tree.c",
        re.search(r"\bprim(?:s|_)?\b", lower) and ("mst" in lower or "spanning" in lower))
    add(100, "Graphs", "dijkstra_shortest_path.c", "dijkstra" in lower or "dijstra" in lower)
    add(100, "Graphs", "warshall_transitive_closure.c",
        "warshall" in lower or "warshal" in lower)
    add(99, "Graphs", "floyd_warshall_all_pairs_shortest_path.c",
        "floyd" in lower or "all_pair" in lower or "allpair" in lower)
    add(98, "Graphs", "adjacency_matrix_graph.c",
        "adjacen" in lower and "matrix" in lower)

    # --- Greedy ---
    add(100, "Greedy", "activity_selection_problem.c",
        "activit" in lower or "printmaxactivities" in lower
        or ("finish" in lower and re.search(r"\bf\[\]", lower)))
    add(100, "Greedy", "fractional_knapsack.c", "knapsack" in lower)
    add(99, "Greedy", "fractional_knapsack_greedy.c", "fractional" in lower)

    # --- Trees ---
    add(100, "Trees", "avl_tree_operations.c", "avl" in lower)
    add(104, "Trees", "binary_search_tree_operations.c",
        ("bst" in lower or "binarysearch" in lower or "binary search tree" in lower)
        and ("struct" in lower or "node" in lower))
    add(103, "Trees", "binary_tree_traversal.c",
        ("left" in lower and "right" in lower) and ("struct" in lower or "node" in lower))

    # --- Linked lists ---
    add(100, "Linked_Lists", "circular_linked_list.c",
        "circular" in lower and ("linked" in lower or "list" in lower))
    add(105, "Linked_Lists", "singly_linked_list_operations.c",
        ("struct" in lower and "next" in lower) and "binary" not in lower)
    add(98, "Linked_Lists", "linked_list_project.c", "linked list" in lower or "linkedlist" in lower)

    # --- Sorting ---
    add(100, "Sorting", "bubble_sort_descending.c",
        "bubble" in lower and ("descend" in lower or ">" in norm and "j+1" in norm))
    add(100, "Sorting", "bubble_sort_ascending.c",
        ("bubble" in lower)
        or re.search(r"a\[i-1\]\s*>\s*a\[i\]", lower)
        or re.search(r"a\[j\]\s*>\s*a\[j\+1\]", lower)
        or re.search(r"a\[i\]\s*>\s*a\[i\+1\]", lower))
    add(100, "Sorting", "selection_sort_ascending.c", "selection" in lower or "slection" in lower)
    add(100, "Sorting", "merge_sort.c", "merge" in lower and "sort" in lower)
    add(100, "Sorting", "quick_sort.c", "quick" in lower and "sort" in lower)
    add(100, "Sorting", "radix_sort.c", "radix" in lower)
    add(99, "Sorting", "row_wise_matrix_sort.c", "row" in lower and "sort" in lower)

    # --- Searching ---
    add(100, "Searching", "binary_search_iterative.c",
        "mid" in lower and "low" in lower and "high" in lower)
    add(99, "Searching", "linear_search.c", "linear" in lower and "search" in lower)

    # --- Recursion ---
    add(100, "Recursion", "factorial_recursive.c",
        rec_count > 0 and "factorial" in lower)
    add(100, "Recursion", "fibonacci_recursive.c", "fibonacci" in lower or "fib(" in lower)
    add(99, "Recursion", "binary_to_decimal_recursive.c",
        "binary" in lower and "decimal" in lower and rec_count > 0)
    add(99, "Recursion", "sum_of_digits_recursive.c",
        "digit" in lower and rec_count > 0 and "sum" in lower)
    add(98, "Recursion", "count_digits_recursive.c",
        "digit" in lower and rec_count > 0 and "count" in lower)
    add(98, "Recursion", "odd_even_indirect_recursion.c",
        "odd" in lower and "even" in lower and rec_count >= 2)
    add(97, "Recursion", "gcd_recursive.c", ("gcd" in lower or "hcf" in lower) and rec_count > 0)
    add(96, "Recursion", "recursive_array_sum.c", "recursive" in lower and "sum" in lower)
    add(95, "Recursion", "tower_of_hanoi.c", "hanoi" in lower)

    # --- Dynamic memory ---
    add(100, "Dynamic_Memory", "dynamic_array_multiplication.c",
        "malloc" in lower and "matrix" in lower)
    add(99, "Dynamic_Memory", "dynamic_name_storage.c", "malloc" in lower and "name" in lower)
    add(98, "Dynamic_Memory", "realloc_memory_demo.c", "realloc" in lower)
    add(97, "Dynamic_Memory", "malloc_calloc_demo.c", "malloc" in lower or "calloc" in lower)

    # --- Pointers ---
    add(110, "Pointers", "pointer_menu_operations_demo.c",
        ("pointer" in prints or re.search(r"\bpointers\b", lower))
        and len(re.findall(r"\bstruct\s+\w+", lower)) < 3)
    add(99, "Pointers", "pointer_arithmetic_operations.c",
        re.search(r"\*\s*\w+", lower) and ("arithmetic" in lower or "addition" in lower))
    add(99, "Pointers", "matrix_multiplication_pointers.c",
        "pointer" in lower and "matrix" in lower and "mul" in lower)
    add(98, "Pointers", "string_reversal_pointers.c",
        "pointer" in lower and ("reverse" in lower or "revers" in lower) and "char" in lower)
    add(97, "Pointers", "pointer_assignment_demo.c", "assignment" in lower and "pointer" in lower)

    # --- Strings ---
    add(100, "Strings", "string_palindrome_check.c",
        ("palindrome" in lower or "palin" in lower) and ("char" in lower or "string" in lower))
    add(99, "Strings", "string_pattern_matching.c", "pattern" in lower and "string" in lower)
    add(98, "Strings", "string_input_output.c", "gets" in lower or "fgets" in lower)

    # --- Structures ---
    add(108, "Structures", "nested_structure_demonstration.c",
        len(re.findall(r"\bstruct\s+\w+", lower)) >= 3
        and "next" not in lower
        and "left" not in lower
        and "right" not in lower)
    add(100, "Structures", "structure_demonstration.c",
        "struct" in lower and ("demonstrat" in lower or "admission" in lower))
    add(99, "Structures", "student_record_structure.c",
        "struct" in lower and "student" in lower and "menu" not in lower)

    # --- Mathematics ---
    add(100, "Mathematics", "repeated_digit_series.c",
        re.search(r"pow\s*\(\s*10", lower) or ("111" in prints and "series" in prints))
    add(100, "Mathematics", "alternating_harmonic_series.c",
        (re.search(r"1\s*/\s*\(?\s*i\s*\)?", lower) and re.search(r"-\s*1\s*/", lower))
        or (re.search(r"1\s*/\s*i", lower) and re.search(r"i\s*%\s*2", lower)))
    add(100, "Mathematics", "inverse_square_series.c",
        re.search(r"1\s*/\s*\(?\s*i\s*\*\s*i", lower) or re.search(r"1\s*/\s*pow\s*\(\s*i\s*,\s*2", lower))
    add(100, "Mathematics", "inverse_cube_series.c",
        re.search(r"1\s*/\s*pow\s*\(\s*i\s*,\s*3", lower) or re.search(r"i\s*\*\s*i\s*\*\s*i", lower))
    add(99, "Mathematics", "reciprocal_power_series.c",
        re.search(r"1\s*/\s*pow\s*\(\s*i\s*,\s*i\s*\)", lower))
    add(99, "Mathematics", "sum_of_squares_series.c",
        ("square" in prints and "sum" in lower)
        or re.search(r"sum\s*\+\s*=\s*i\s*\*\s*i", lower)
        or re.search(r"sum\s*=\s*sum\s*\+\s*i\s*\*\s*i", lower))
    add(99, "Mathematics", "sum_of_natural_numbers.c",
        re.search(r"n\s*\*\s*\(\s*n\s*\+\s*1\s*\)\s*/\s*2", lower))
    add(99, "Mathematics", "triangular_number_summation.c", "triangular" in lower)
    add(98, "Mathematics", "perfect_number_checker.c",
        ("perfect" in lower and "divisor" in lower)
        or (re.search(r"sum\s*=\s*0", lower) and re.search(r"i\s*<\s*n", lower) and re.search(r"n\s*%\s*i\s*==\s*0", lower)))
    add(98, "Mathematics", "armstrong_number_checker.c", "armstrong" in lower)
    add(98, "Mathematics", "strong_number_checker.c", "strong" in lower and "factorial" in lower)
    add(98, "Mathematics", "primality_test.c", "prime" in lower and ("divisor" in lower or "flag" in lower))
    add(97, "Mathematics", "prime_sum_decomposition.c", "prime" in lower and "sum" in lower)
    add(96, "Mathematics", "pascals_triangle.c", "pascal" in lower)
    add(96, "Mathematics", "grains_on_chessboard.c", "grain" in lower)
    add(95, "Mathematics", "lcm_two_numbers.c", "lcm" in lower)
    add(96, "Mathematics", "taylor_series_expansion.c",
        "pow(-1" in lower.replace(" ", "") and ("fact" in lower or "factorial" in lower))
    add(95, "Mathematics", "divisible_by_3_and_5_summation.c",
        re.search(r"3\s*\*", lower) and re.search(r"5\s*\*", lower) and re.search(r"15\s*\*", lower))
    add(95, "Mathematics", "gcd_two_numbers.c", ("gcd" in lower or "hcf" in lower) and rec_count == 0)
    add(94, "Mathematics", "factorial_iterative.c", "factorial" in lower and rec_count == 0)
    add(93, "Mathematics", "square_root_table_generation.c", "sqrt" in lower)
    add(92, "Mathematics", "rounding_numbers.c", "round" in lower)
    add(91, "Mathematics", "multiple_mathematical_concepts_demo.c",
        len(re.findall(r"case\s+\d+", lower)) >= 5 or lower.count("printf") > 15)

    # --- Arrays ---
    add(100, "Arrays", "matrix_addition.c",
        ("addition" in lower and "matrix" in lower)
        or re.search(
            r"\[\s*i\s*\]\s*\[\s*j\s*\]\s*=\s*\w+\[\s*i\s*\]\s*\[\s*j\s*\]\s*\+\s*\w+\[\s*i\s*\]\s*\[\s*j\s*\]",
            lower,
        ))
    add(99, "Arrays", "matrix_multiplication.c",
        "matrix" in lower and "mul" in lower and "malloc" not in lower)
    add(99, "Arrays", "matrix_equality_comparison.c",
        "matrix" in lower and ("equal" in lower or "comparison" in prints))
    add(98, "Arrays", "matrix_transpose.c", "transpose" in lower)
    add(98, "Arrays", "symmetric_matrix_check.c", "symmetric" in lower or "skew" in lower)
    add(97, "Arrays", "array_insertion.c", "insert" in lower and "array" in lower)
    add(97, "Arrays", "array_duplicate_finder.c", "duplicate" in lower)
    add(96, "Arrays", "second_largest_number_finder.c",
        "second" in lower and "largest" in lower or "sln" in lower)
    add(95, "Arrays", "array_subset_check.c", "subset" in lower)

    # --- Patterns ---
    add(100, "Patterns", "diamond_number_pattern.c",
        "diamond" in lower or ("pyramid" in lower and "space" in lower))
    add(50, "Patterns", "number_triangle_pattern.c",
        re.search(r"for\s*\([^)]*\)\s*\{[^}]*for\s*\([^)]*\)\s*\{[^}]*printf", lower, re.S)
        and "sort" not in lower and "matrix" not in lower and "search" not in lower
        and "pow" not in lower)
    add(98, "Patterns", "pascal_triangle_pattern.c", "pascal" in lower and "for" in lower)
    add(97, "Patterns", "equilateral_triangle_pattern.c", "equi" in lower and "triangle" in lower)

    # --- Functions ---
    add(95, "Functions", "ordered_list_functions.c", "orderlist" in lower or "ordered list" in lower)
    add(94, "Functions", "function_multiplication_table.c", "multiplication" in lower and "function" in lower)

    # --- Basics ---
    add(100, "Basics", "hello_world.c", "hello" in lower and "world" in lower)
    add(99, "Basics", "multiplication_table_generator.c",
        "multiplication table" in prints or ("table" in prints and "*" in prints))
    add(98, "Basics", "integer_palindrome_checker.c",
        "palindrome" in lower and "char" not in lower)
    add(98, "Basics", "integer_reversal.c", ("reverse" in lower or "revers" in lower) and "char" not in lower)
    add(97, "Basics", "finding_greatest_number.c", "greatest" in lower or ("max" in lower and "min" not in lower))
    add(97, "Basics", "smallest_number_finder.c", "smallest" in lower or "minimum" in lower)
    add(96, "Basics", "numbers_divisibility_pattern.c",
        ("divisible" in lower and "remainder" in lower)
        or (re.search(r"%\s*4\s*==\s*0", lower) and re.search(r"%\s*5", lower)))
    add(95, "Basics", "box_shape_printer.c", "box" in lower or ("+" in code and "---" in code))

    # --- Misc named algorithms ---
    add(100, "Miscellaneous", "strassen_matrix_multiplication.c", "strassen" in lower)
    add(99, "Miscellaneous", "rat_in_maze_backtracking.c", "maze" in lower or "rat" in lower)
    add(98, "Miscellaneous", "fcfs_cpu_scheduling.c", "fcfs" in lower)
    add(97, "Miscellaneous", "storage_classes_demo.c", "storage class" in lower or "auto" in prints and "extern" in lower)
    add(96, "Miscellaneous", "min_max_finder.c", "min_max" in lower or ("min" in lower and "max" in lower and "array" in lower))
    add(95, "Miscellaneous", "hackerrank_pattern_printing.c", "hackerrank" in lower)

    if not rules:
        # Heuristic fallbacks by dominant feature
        if "malloc" in lower:
            return Classification("Dynamic_Memory", "dynamic_memory_program.c", 10)
        if rec_count > 0:
            return Classification("Recursion", "recursive_function_demo.c", 10)
        if "struct" in lower:
            return Classification("Structures", "structure_program.c", 10)
        if re.search(r"for\s*\([^)]*\)\s*\{[^}]*for", lower):
            return Classification("Patterns", "nested_loop_pattern.c", 10)
        if re.search(r"for\s*\(", lower) and re.search(r"sum", lower):
            return Classification("Mathematics", "numeric_series_summation.c", 5)
        if "printf" in lower:
            return Classification("Basics", "basic_io_program.c", 5)
        h = content_hash(code)
        return Classification("Miscellaneous", f"c_program_{h}.c", 1)

    rules.sort(key=lambda x: -x[0])
    score, cat, fname, _ = rules[0]
    return Classification(cat, sanitize_filename(fname), score)


def find_c_files(refine: bool = False) -> list[Path]:
    files = []
    for root, dirs, filenames in os.walk(ROOT):
        rp = root.replace("\\", "/")
        if not refine and "Organized_C_Programs" in rp:
            continue
        if refine and "Organized_C_Programs" not in rp:
            continue
        for fn in filenames:
            if fn.lower().endswith(".c"):
                files.append(Path(root) / fn)
    return sorted(files)


def load_migration_origins() -> dict[str, str]:
    """current relative new_path -> original_path"""
    out: dict[str, str] = {}
    if not MIGRATION_CSV.exists():
        return out
    with MIGRATION_CSV.open(encoding="utf-8", newline="") as f:
        for row in csv.DictReader(f):
            out[row["new_path"].replace("/", "\\")] = row["original_path"]
    return out


def main(refine: bool = False, dedupe_only: bool = False) -> None:
    preview = load_preview() if not refine and not dedupe_only else {}
    origins = load_migration_origins() if refine or dedupe_only else {}
    c_files = find_c_files(refine=refine or dedupe_only)
    print(f"Found {len(c_files)} C files")

    # Create category folders
    for cat in CATEGORIES:
        (ORG_ROOT / cat).mkdir(parents=True, exist_ok=True)

    assignments: list[tuple[Path, Classification, str]] = []
    codes: dict[Path, str] = {}
    for path in c_files:
        code = read_code(path)
        codes[path] = code
        h = content_hash(code)

        if dedupe_only:
            base_cls = classify(code)
            cat = path.parent.name
            cls = Classification(
                cat, sanitize_filename(f"{canonical_stem(base_cls.filename, code)}.c")
            )
        elif path.name in preview:
            cat, fname = preview[path.name]
            cls = Classification(cat, fname)
        else:
            cls = classify(code)

        assignments.append((path, cls, h))

    resolved = resolve_duplicates(assignments, codes)

    used_targets: set[str] = set()
    used_suffixes_global: dict[tuple[str, str], set[str]] = defaultdict(set)
    migration_rows = []

    for path, cls, h in resolved:
        dest_dir = ORG_ROOT / cls.category
        dest_name = cls.filename
        dest = dest_dir / dest_name
        stem = canonical_stem(dest_name, codes[path])

        while True:
            key = str(dest)
            if key not in used_targets and (
                not dest.exists() or dest.resolve() == path.resolve()
            ):
                break
            version_counter = [0]
            dest_name = _allocate_unique_filename(
                cls.category,
                stem,
                path,
                codes[path],
                used_targets,
                used_suffixes_global[(cls.category, stem)],
                force_suffix=True,
                version_counter=version_counter,
            )
            dest = dest_dir / dest_name
            stem = canonical_stem(dest_name, codes[path])
        used_targets.add(str(dest))

        # Move file
        dest.parent.mkdir(parents=True, exist_ok=True)
        if dest.resolve() != path.resolve():
            shutil.move(str(path), str(dest))

        rel = str(path.relative_to(ROOT)).replace("/", "\\")
        if refine or dedupe_only:
            original = origins.get(rel, rel)
        else:
            original = rel

        migration_rows.append({
            "original_path": original,
            "new_path": str(dest.relative_to(ROOT)),
            "category": cls.category,
            "new_filename": dest_name,
        })

    # Write migration report
    with MIGRATION_CSV.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(
            f,
            fieldnames=["original_path", "new_path", "category", "new_filename"],
        )
        writer.writeheader()
        writer.writerows(sorted(migration_rows, key=lambda r: r["original_path"]))

    print(f"Migration complete: {len(migration_rows)} files")
    print(f"Report: {MIGRATION_CSV}")

    # Verify counts
    remaining = find_c_files()
    root_loose = [p for p in remaining if p.parent == ROOT]
    print(f"Files in Organized_C_Programs: {len(remaining) - len(root_loose)}")
    print(f"Loose .c files still at root: {len(root_loose)}")


if __name__ == "__main__":
    import sys
    argv = sys.argv[1:]
    main(
        refine="--refine" in argv,
        dedupe_only="--dedupe-only" in argv,
    )
