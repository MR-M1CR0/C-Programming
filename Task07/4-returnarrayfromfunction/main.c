#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int* arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int size = 5;
    int* arr = createArray(size);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
