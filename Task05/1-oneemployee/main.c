#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_LABEL_LENGTH 20
#define NUM_FIELDS 6
#define MAX_INPUT_LENGTH 100

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    system("cls");

    char labels[NUM_FIELDS][MAX_LABEL_LENGTH] = {
        "id", "name", "age", "salary", "commission", "deduction"
    };

    int labelPositions[NUM_FIELDS][2] = {
        {7, 2}, {50, 2},
        {7, 8}, {50, 8},
        {7, 14}, {50, 14}
    };

    char inputData[NUM_FIELDS][MAX_INPUT_LENGTH];

    for (int i = 0; i < NUM_FIELDS; i++) {
        gotoxy(labelPositions[i][0], labelPositions[i][1]);
        printf("%s:", labels[i]);

        gotoxy(labelPositions[i][0] + strlen(labels[i]) + 1, labelPositions[i][1]);

        scanf("%s", inputData[i]);
    }

    int salary = atoi(inputData[3]);
    int commission = atoi(inputData[4]);
    int deduction = atoi(inputData[5]);
    int netSalary = salary + commission - deduction;

    system("cls");
    printf("Net Salary: %d\n", netSalary);

    return 0;
}
