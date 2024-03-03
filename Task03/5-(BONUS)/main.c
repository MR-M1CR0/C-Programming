#include <stdio.h>
#include <stdlib.h>

#define ROW1 3
#define COL1 3
#define ROW2 3
#define COL2 2

void multiplyMatrices(int mat1[ROW1][COL1], int mat2[ROW2][COL2], int result[ROW1][COL2]) {
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COL1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[ROW1][COL2]) {
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            printf("\t%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[ROW1][COL1];
    int matrix2[ROW2][COL2];
    int result[ROW1][COL2];

    printf("Enter values for matrix1 (%d x %d):\n", ROW1, COL1);
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL1; j++) {
            printf("Enter element at row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\n");

    printf("Enter values for matrix2 (%d x %d):\n", ROW2, COL2);
    for (int i = 0; i < ROW2; i++) {
        for (int j = 0; j < COL2; j++) {
            printf("Enter element at row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\n");

    multiplyMatrices(matrix1, matrix2, result);

    printf("Result = \n");
    displayMatrix(result);

    return 0;
}
