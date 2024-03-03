#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter array size\n");
    scanf("%i", &size);
    int* ptr = malloc(size * sizeof(int));

    printf("\n");

    for(int i = 0; i < size; i++)
    {
        printf("at index %i\n", i);
        scanf("%i", ptr + i);
    }
    printf("\n");
    for(int i = 0; i < size; i++)
       printf("at index %i is %i\n", i, *(ptr + i));

    // Alternative way to do it
    // for(int i = 0; i < size; i++)
    // {
    //     printf("at index %i\n", i);
    //     scanf("%i", &ptr[i]);
    // }
    // for(int i = 0; i < size; i++)
    //     printf("at index %i is %i\n", i, ptr[i]);

    return 0;
}
