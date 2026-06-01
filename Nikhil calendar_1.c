#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int days;
    if (month == 2) {
        if (isLeapYear(year)) {
            days = 29;
        } else {
            days = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }
    return days;
}

// Function to get the day of the week for a given date
int getDayOfWeek(int day, int month, int year) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

// Function to display the calendar for a given month and year
void display(int month, int year) {
    int daysInMonth, i, dayOfWeek;
    
    // Array to store the names of the months
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    // Print the month and year header
    printf("\n   %s %d\n", months[month - 1], year);
    printf("---------------------------\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    
    // Get the number of days in the month and the day of the week for the first day of the month
    daysInMonth = getDaysInMonth(month, year);
    dayOfWeek = getDayOfWeek(1, month, year);
    
    // Print the calendar
    for (i = 0; i < dayOfWeek; i++) {
        printf("    ");
    }
    for (i = 1; i <= daysInMonth; i++) {
        printf("%4d", i);
        if ((i + dayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Main function
int main() {
    int month, year;
    
    // Get the month and year from the user
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    
    // Display the calendar
    display(month, year);
    
    return 0;
}