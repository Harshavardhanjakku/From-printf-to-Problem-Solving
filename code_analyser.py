import os
import json
import csv
from groq import Groq

# ======================================
# CONFIG
# ======================================

ROOT_DIR = r"D:\personal\From printf() to Problem Solving"

OUTPUT_CSV = os.path.join(
    ROOT_DIR,
    "preview_20_files.csv"
)

MAX_FILES = None

current_key_index = 0


def get_client():
    return Groq(
        api_key=API_KEYS[current_key_index]
    )


client = get_client()

# ======================================
# API KEY ROTATION
# ======================================

def call_groq(prompt):

    global current_key_index
    global client

    last_error = None

    for _ in range(len(API_KEYS)):

        try:

            response = client.chat.completions.create(
                model="llama-3.3-70b-versatile",
                temperature=0,
                messages=[
                    {
                        "role": "user",
                        "content": prompt
                    }
                ]
            )

            return response

        except Exception as e:

            last_error = e

            print(
                f"\nAPI Key {current_key_index + 1} failed:"
            )
            print(str(e))

            current_key_index += 1

            if current_key_index >= len(API_KEYS):
                break

            print(
                f"Switching to API Key {current_key_index + 1}"
            )

            client = get_client()

    raise last_error


# ======================================
# PROMPT
# ======================================

PROMPT_TEMPLATE = """
You are an expert software reverse engineer, computer science educator, and code archivist.

Your task is to analyze a C program and generate metadata suitable for building a professional programming repository.

IMPORTANT:

Do NOT use the existing filename.

Analyze only the source code.

Focus on what the program actually does, not variable names or comments.

---

## CLASSIFICATION RULES

Identify:

1. Main algorithm or concept
2. Development stage
3. Purpose
4. Category
5. Professional filename
6. Short description

---

## FILENAME RULES (VERY IMPORTANT)

The filename must:

* be lowercase
* use snake_case
* end with .c
* be highly specific
* describe the exact problem solved
* describe the actual algorithm, mathematical concept, data structure, or application
* be suitable for a GitHub repository
* avoid vague words

Avoid filenames such as:

program.c
example.c
practice.c
experiment.c
code.c
solution.c
calculator.c
series.c
series_sum.c
test.c
temp.c

Bad examples:

series_sum.c
calculator.c
math_program.c
number_problem.c

Good examples:

alternating_harmonic_series.c
inverse_square_series.c
inverse_cube_series.c
student_management_system.c
binary_search_recursive.c
selection_sort_descending.c
matrix_multiplication.c
tower_of_hanoi_recursive.c
employee_payroll_system.c
tic_tac_toe_game.c

For mathematical series:

1 + 11 + 111 + ...
→ repeated_digit_series.c

1 - 1/2 + 1/3 - 1/4 ...
→ alternating_harmonic_series.c

1/(1²)+1/(2²)+...
→ inverse_square_series.c

1/(1³)+1/(2³)+...
→ inverse_cube_series.c

---

## DEVELOPMENT STAGE

Choose exactly one:

basic
practice
learning
assignment
lab
exercise
intermediate
advanced
optimized
improved
experimental
debug
complete
final

---

## PURPOSE

Choose exactly one:

implementation
project
management_system
solver
simulation
game
application
converter
demonstration
example
utility

---

## CATEGORY

Choose exactly one:

Basics
Patterns
Functions
Arrays
Strings
Pointers
Recursion
Structures
Dynamic_Memory
Searching
Sorting
Linked_Lists
Trees
Graphs
Greedy
Mini_Projects
Mathematics
Miscellaneous

Category Guidelines:

Mathematics:
series, factorials, primes, divisibility,
number theory, numerical methods,
combinatorics, equations

Mini_Projects:
student systems,
bank systems,
library systems,
games,
management systems

Searching:
linear search,
binary search

Sorting:
bubble,
selection,
insertion,
merge,
quick sort

Recursion:
factorial recursion,
fibonacci recursion,
tower of hanoi

---

## DESCRIPTION RULES

Write 1 concise professional sentence.

Mention:

* what problem is solved
* algorithm or concept used

Avoid:

"This program..."
"A C program..."

Example:

Calculates the sum of the inverse square series up to n terms.

---

## OUTPUT FORMAT

Return ONLY valid JSON.

Return nothing before or after JSON.

{{
"topic": "",
"stage": "",
"purpose": "",
"category": "",
"filename": "",
"description": ""
}}
---

## SOURCE CODE

{code}
"""

# ======================================
# FIND FILES
# ======================================

c_files = []

for root, dirs, files in os.walk(ROOT_DIR):

    for file in files:

        if file.lower().endswith(".c"):

            c_files.append(
                os.path.join(root, file)
            )

c_files = c_files[:MAX_FILES]

print(f"Found {len(c_files)} files")

# ======================================
# CSV
# ======================================

with open(
    OUTPUT_CSV,
    "w",
    newline="",
    encoding="utf-8"
) as csvfile:

    writer = csv.writer(csvfile)

    writer.writerow([
        "original_name",
        "topic",
        "stage",
        "purpose",
        "category",
        "new_filename",
        "description"
    ])

    # ==================================
    # PROCESS FILES
    # ==================================

    for index, filepath in enumerate(c_files, start=1):

        filename = os.path.basename(filepath)

        try:

            print(
                f"[{index}/{len(c_files)}] Analyzing: {filename}"
            )

            with open(
                filepath,
                "r",
                encoding="utf-8",
                errors="ignore"
            ) as f:

                code = f.read()

            code = code[:8000]

            prompt = PROMPT_TEMPLATE.format(
                code=code
            )

            response = call_groq(prompt)

            content = (
                response
                .choices[0]
                .message
                .content
            )

            start = content.find("{")
            end = content.rfind("}") + 1

            if start == -1 or end <= start:

                raise ValueError(
                    "No valid JSON found in response"
                )

            data = json.loads(
                content[start:end]
            )

            writer.writerow([
                filename,
                data.get("topic", ""),
                data.get("stage", ""),
                data.get("purpose", ""),
                data.get("category", ""),
                data.get("filename", ""),
                data.get("description", "")
            ])

            csvfile.flush()

        except Exception as e:

            print(
                "\nError:",
                filepath
            )
            print(str(e))

            writer.writerow([
                filename,
                "ERROR",
                "ERROR",
                "ERROR",
                "ERROR",
                "ERROR",
                str(e)
            ])

            csvfile.flush()

print()
print("=" * 60)
print("Done")
print("Preview CSV:")
print(OUTPUT_CSV)
print("=" * 60)