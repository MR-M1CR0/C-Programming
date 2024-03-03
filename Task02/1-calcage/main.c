#include <stdio.h>
#include <stdlib.h>

int main() {
    int currentDay = 9;
    int currentMonth = 10;
    int currentYear = 2023;

    int day, month, year;

    do {
        printf("Please enter your year from 1980 to 2023: ");
        scanf("%d", &year);
    } while (year < 1980 || year > 2023);

    do {
        printf("Please enter your month from 1 to 12: ");
        scanf("%d", &month);
    } while (month < 1 || month > 12);

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            do {
                printf("Please enter your day from 1 to 31: ");
                scanf("%d", &day);
            } while (day < 1 || day > 31);
            break;

        case 4: case 6: case 9: case 11:
            do {
                printf("Please enter your day from 1 to 30: ");
                scanf("%d", &day);
            } while (day < 1 || day > 30);
            break;

        case 2:
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
                do {
                    printf("Please enter your day from 1 to 29: ");
                    scanf("%d", &day);
                } while (day < 1 || day > 29);
            } else {
                do {
                    printf("Please enter your day from 1 to 28: ");
                    scanf("%d", &day);
                } while (day < 1 || day > 28);
            }
            break;
    }

    int ageYears = currentYear - year;
    int ageMonths = currentMonth - month;
    int ageDays = currentDay - day;

    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }
    if (ageDays < 0) {
        ageMonths--;
        ageDays += 30;
    }

    printf("You're %d years, %d months, and %d days old.\n", ageYears, ageMonths, ageDays);

    return 0;
}
