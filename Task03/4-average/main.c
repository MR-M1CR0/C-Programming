#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
    float arr[ROWS][COLS];
    float columnAverages[COLS];

    for (int i = 0; i < ROWS; i++) {
        printf("Enter %d elements for row %d:\n", COLS, i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("Enter element %d: ", j + 1);
            scanf("%f", &arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < COLS; i++) {
        float sum = 0.0;
        for (int j = 0; j < ROWS; j++) {
            sum += arr[j][i];
        }
        columnAverages[i] = sum / ROWS;
    }

    printf("\nColumn averages:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Column %d: %f\n", j + 1, columnAverages[j]);
    }

    return 0;
}
