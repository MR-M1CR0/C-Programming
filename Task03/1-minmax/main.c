#include <stdio.h>
#include <stdlib.h>

#define size 10
int main()
{
    int arr[size];
    for(int i = 0; i < size; i++)
    {
        printf("please enter element %i of 10 for the array\n", i + 1);
        scanf("%i", &arr[i]);
    }

    int min = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    int max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    system("cls");

    printf("Array elements are:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n\n");
    printf("MIN value = %i\n", min);
    printf("MAX value = %i\n", max);

    return 0;
}
