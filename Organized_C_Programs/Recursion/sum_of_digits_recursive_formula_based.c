/*

GEEKSFORGEEKS

C program to display month by month calendar for a given year

Prerequisite: Find day of the week for a given date Given a year N, the task is to print the calendar for every month of the given year. Implementation: 

C
*/
// C program to print the month by month 

// calendar for the given year 

 

#include <stdio.h> 

 

// Function that returns the index of the 

// day for date DD/MM/YYYY 

int dayNumber(int day, int month, int year) 

{ 

 

    static int t[] = { 0, 3, 2, 5, 0, 3, 

                    5, 1, 4, 6, 2, 4 }; 

    year -= month < 3; 

    return (year + year / 4 

            - year / 100 

            + year / 400 

            + t[month - 1] + day) 

        % 7; 

} 

 

// Function that returns the name of the 

// month for the given month Number 

// January - 0, February - 1 and so on 

char* getMonthName(int monthNumber) 

{ 

    char* month; 

 

    switch (monthNumber) { 

    case 0: 

        month = "January"; 

        break; 

    case 1: 

        month = "February"; 

        break; 

    case 2: 

        month = "March"; 

        break; 

    case 3: 

        month = "April"; 

        break; 

    case 4: 

        month = "May"; 

        break; 

    case 5: 

        month = "June"; 

        break; 

    case 6: 

        month = "July"; 

        break; 

    case 7: 

        month = "August"; 

        break; 

    case 8: 

        month = "September"; 

        break; 

    case 9: 

        month = "October"; 

        break; 

    case 10: 

        month = "November"; 

        break; 

    case 11: 

        month = "December"; 

        break; 

    } 

    return month; 

} 

 

// Function to return the number of days 

// in a month 

int numberOfDays(int monthNumber, int year) 

{ 

    // January 

    if (monthNumber == 0) 

        return (31); 

 

    // February 

    if (monthNumber == 1) { 

        // If the year is leap then Feb 

        // has 29 days 

        if (year % 400 == 0 

            || (year % 4 == 0 

                && year % 100 != 0)) 

            return (29); 

        else 

            return (28); 

    } 

 

    // March 

    if (monthNumber == 2) 

        return (31); 

 

    // April 

    if (monthNumber == 3) 

        return (30); 

 

    // May 

    if (monthNumber == 4) 

        return (31); 

 

    // June 

    if (monthNumber == 5) 

        return (30); 

 

    // July 

    if (monthNumber == 6) 

        return (31); 

 

    // August 

    if (monthNumber == 7) 

        return (31); 

 

    // September 

    if (monthNumber == 8) 

        return (30); 

 

    // October 

    if (monthNumber == 9) 

        return (31); 

 

    // November 

    if (monthNumber == 10) 

        return (30); 

 

    // December 

    if (monthNumber == 11) 

        return (31); 

} 

 

// Function to print the calendar of 

// the given year 

void printCalendar(int year) 

{ 

    printf("     Calendar - %d\n\n", year); 

    int days; 

 

    // Index of the day from 0 to 6 

    int current = dayNumber(1, 1, year); 

 

    // i for Iterate through months 

    // j for Iterate through days 

    // of the month - i 

    for (int i = 0; i < 12; i++) { 

        days = numberOfDays(i, year); 

 

        // Print the current month name 

        printf("\n ------------%s-------------\n", 

            getMonthName(i)); 

 

        // Print the columns 

        printf(" Sun Mon Tue Wed Thu Fri Sat\n"); 

 

        // Print appropriate spaces 

        int k; 

        for (k = 0; k < current; k++) 

            printf("     "); 

 

        for (int j = 1; j <= days; j++) { 

            printf("%5d", j); 

 

            if (++k > 6) { 

                k = 0; 

                printf("\n"); 

            } 

        } 

 

        if (k) 

            printf("\n"); 

 

        current = k; 

    } 

 

    return; 

} 

 

// Driver Code 

int main() 

{ 

    int year = 2016; 

 

    // Function Call 

    printCalendar(year); 

    return 0; 

} 

/*Output... 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 ------------September------------- Sun Mon Tue Wed Thu Fri Sat 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 ------------October------------- Sun Mon Tue Wed Thu Fri Sat 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 ------------November------------- Sun Mon Tue Wed Thu Fri Sat 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 ------------December------------- Sun Mon Tue Wed Thu Fri Sat 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 

Time Complexity: O(1)
Auxiliary Space: O(1), As constant extra space is used.


Article Tags : 

C Language

C Programs

School Programming

 

Calendars

Recommended Articles

1. Calendar Functions in Python | Set 1( calendar(), month(), isleap()...)

2. Print calendar for a given year in C++

3. C program to check if a given year is leap year using Conditional operator

4. Check if digits from concatenation of date and month can be used to form given year

5. Find the first day of a given year from a base year having first day as Monday

6. Print the season name of the year based on the month number

7. C program to print number of days in a month

8. C Program To Check Leap Year

9. How to calculate the Easter date for a given year using Gauss' Algorithm

10. C Program to display hostname and IP address

11. Program to display all alphabets from A to Z in uppercase and lowercase both

12. C Program to Display Armstrong Number Between Two Intervals

13. C program to display the animated firecrackers with a message using graphics

14. C Program to Display Prime Numbers Between Intervals

15. C Program to Display Prime Numbers Between Two Intervals Using Functions

16. C Program to Display time in Different Country Format

17. AKTU (UPTU) Previous Year Solved Papers | C Programming

18. Why is programming important for first year or school students?

19. C Program for Given a sorted and rotated array, find if there is a pair with a given sum

20. C Program For Deleting A Given Node In Linked List Under Given Constraints

21. C program to detect tokens in a C program

22. C program to print a string without any quote (single or double) in the program

23. C Program for Program to find area of a circle

24. C Program for Program to cyclically rotate an array by one

25. Lex Program to remove comments from C program

Read Full Article

￼

A-143, 9th Floor, Sovereign Corporate Tower,

Sector- 136, Noida, Uttar Pradesh (201305)

feedback@geeksforgeeks.org

Company

About Us

Careers

In Media

Contact Us

Privacy Policy

Copyright Policy

Advertise with us

Learn

DSA

Algorithms

Data Structures

SDE Cheat Sheet

Machine Learning

CS Subjects

Video Tutorials

Courses

NEWS

Top News

Technology

Work & Career

Business

Finance

Lifestyle

Knowledge

Languages

Python

Java

CPP

Golang

C#

SQL

Kotlin

Web Development

Web Tutorials

Django Tutorial

HTML

JavaScript

Bootstrap

ReactJs

NodeJs

Contribute

Write an Article

Improve an Article

Pick Topics to Write

Write Interview Experience

Internships

Video Internship

 */
    