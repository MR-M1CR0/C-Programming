#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter array size\n");
    scanf("%i", &size);

    int** ptr = (int**)malloc(size * sizeof(int*));

    printf("\n");

    for (int i = 0; i < size; i++) {
        ptr[i] = malloc(size * sizeof(int));
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter integer for index [%d][%d]: ", i, j);
            scanf("%d", &ptr[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Value at index [%d][%d] is %d\n", i, j, ptr[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        free(ptr[i]);
    }

    free(ptr);

    return 0;
}
