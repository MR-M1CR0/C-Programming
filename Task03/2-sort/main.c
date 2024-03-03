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

    system("cls");
    printf("Array before sorting\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n\n");
    printf("Array after sorting\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
