#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fn[10];
    char ln[10];
    char fulln[21];

    printf("please enter first name ");
    gets(fn);

    printf("please enter last name ");
    gets(ln);

    strcpy(fulln, fn);
    strcat(fulln, " ");
    strcat(fulln, ln);

    printf("full name = ");
    puts(fulln);

    // Alternative Way to do it
    char firstName[10], lastName[10], fullName[21];
    int i = 0;

    printf("Enter first name: ");
    scanf("%s", firstName);

    printf("Enter last name: ");
    scanf("%s", lastName);

    while (firstName[i] != '\0') {
        fullName[i] = firstName[i];
        i++;
    }

    fullName[i] = ' ';
    i++;

    int j = 0;
    while (lastName[j] != '\0') {
        fullName[i] = lastName[j];
        i++;
        j++;
    }

    fullName[i] = '\0';

    printf("Full name: %s\n", fullName);

    return 0;
}