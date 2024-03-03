#include <stdio.h>
#include <stdlib.h>

#define size 10
int main()
{
    int arr[size];
    int searchNumber;
    int found = 0;

    for(int i = 0; i < size; i++)
    {
        printf("please enter element %i of 10 for the array\n", i + 1);
        scanf("%i", &arr[i]);
    }

    system("cls");

    printf("please enter the number you are search for\n");
    scanf("%i", &searchNumber);

    system("cls");

    printf("Indices of %d in the array: ", searchNumber);
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == searchNumber)
        {
            printf("%i ", i);
            found = 1;
        }
    }

    for (int i = 0; i < 10; i++) 
    {
        if (arr[i] == searchNumber) 
        {
            printf("\n\n");
            printf("First index of %d in the array: %d\n", searchNumber, i);
            break;
        }
    }

    if(!found)
    {
        system("cls");
        printf("Number %d not found in the array.\n", searchNumber);
    }
    else
    {
        printf("\n");
    }

    return 0;
}
