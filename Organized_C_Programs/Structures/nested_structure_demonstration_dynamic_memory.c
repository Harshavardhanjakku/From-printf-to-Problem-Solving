#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char hallticket[20];
    int *marks;
    int total;
    float average;
    char grade;
    char result[10];
};

void calculateResults(struct Student *students, int n, int m);
void sortByName(struct Student *students, int n);
void saveDetainedStudents(struct Student *students, int n);
void saveTopThreeStudents(struct Student *students, int n);
void saveStudentResults(struct Student *students, int n);

int main() {
    int n, m, i, j;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Number of subjects: ");
        scanf("%d", &m);
        
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    
    printf("\nEnter the details of students:\n");
    
    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        
        printf("Name: ");
        scanf("%s", students[i].name);
        
        printf("Hallticket no: ");
        scanf("%s", students[i].hallticket);
        
        
        students[i].marks = (int *)malloc(m * sizeof(int));
        
        printf("Enter marks for each subject:\n");
        
        for (j = 0; j < m; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }
    
    calculateResults(students, n, m);
    sortByName(students, n);
    saveDetainedStudents(students, n);
    saveTopThreeStudents(students, n);
    saveStudentResults(students, n);
    
    free(students);
    
    return 0;
}

void calculateResults(struct Student *students, int n, int m) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        students[i].total = 0;
        
        for (j = 0; j < m; j++) {
            students[i].total += students[i].marks[j];
        }
        
        students[i].average = (float)students[i].total / m;
        
        if (students[i].average >= 90) {
            students[i].grade = 'A';
        } else if (students[i].average >= 80) {
            students[i].grade = 'B';
        } else if (students[i].average >= 70) {
            students[i].grade = 'C';
        } else if (students[i].average >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
        
        if (students[i].grade == 'F') {
            strcpy(students[i].result, "Fail");
        } else {
            strcpy(students[i].result, "Pass");
        }
    }
}

void sortByName(struct Student *students, int n) {
    int i, j;
    struct Student temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void saveDetainedStudents(struct Student *students, int n) {
    FILE *detainedFile = fopen("detained_students.txt", "w");
    
    if (detainedFile == NULL) {
        printf("Error opening file!");
        return;
    }
    
    fprintf(detainedFile, "Detained Students:\n\n");
    
    for (int i = 0; i < n; i++) {
        if (students[i].grade == 'F') {
            fprintf(detainedFile, "Name: %s\n", students[i].name);
            fprintf(detainedFile, "Hallticket No: %s\n", students[i].hallticket);
            fprintf(detainedFile, "Total Marks: %d\n", students[i].total);
            fprintf(detainedFile, "Average Marks: %.2f\n", students[i].average);
            fprintf(detainedFile, "Grade: %c\n", students[i].grade);
            fprintf(detainedFile, "Result: %s\n\n", students[i].result);
        }
    }
    
    fclose(detainedFile);
}

void saveTopThreeStudents(struct Student *students, int n) {
    FILE *topThreeFile = fopen("top_three_students.txt", "w");
    
    if (topThreeFile == NULL) {
        printf("Error opening file!");
        return;
    }
    
    fprintf(topThreeFile, "Top Three Students:\n\n");
    
    for (int i = 0; i < 3 && i < n; i++) {
        fprintf(topThreeFile, "Name: %s\n", students[i].name);
        fprintf(topThreeFile, "Hallticket No: %s\n", students[i].hallticket);
        fprintf(topThreeFile, "Total Marks: %d\n", students[i].total);
        fprintf(topThreeFile, "Average Marks: %.2f\n", students[i].average);
        fprintf(topThreeFile, "Grade: %c\n", students[i].grade);
        fprintf(topThreeFile, "Result: %s\n\n", students[i].result);
    }
    
    fclose(topThreeFile);
}

void saveStudentResults(struct Student *students, int n) {
    FILE *resultsFile = fopen("student_results.txt", "w");
    
    if (resultsFile == NULL) {
        printf("Error opening file!");
        return;
    }
    
    fprintf(resultsFile, "Student Results:\n\n");
    for (int i = 0; i < n; i++) {
        printf( "Name: %s\n", students[i].name);
        printf( "Hallticket No: %s\n", students[i].hallticket);
        printf("Total Marks: %d\n", students[i].total);
        printf( "Average Marks: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
        printf("Result: %s\n\n", students[i].result);
    }
    for (int i = 0; i < n; i++) {
        fprintf(resultsFile, "Name: %s\n", students[i].name);
        fprintf(resultsFile, "Hallticket No: %s\n", students[i].hallticket);
        fprintf(resultsFile, "Total Marks: %d\n", students[i].total);
        fprintf(resultsFile, "Average Marks: %.2f\n", students[i].average);
        fprintf(resultsFile, "Grade: %c\n", students[i].grade);
        fprintf(resultsFile, "Result: %s\n\n", students[i].result);
    }
    
    fclose(resultsFile);
}