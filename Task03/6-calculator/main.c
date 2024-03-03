#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error! Division by zero.\n");
        return 0;
    }
}

char getOperator() {
    char op;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);
    return op;
}

int main() {
    char continuecalculation = 'y';

    do {
        int first, second;
        printf("Enter first num: ");
        scanf("%d", &first);
        printf("Enter second num: ");
        scanf("%d", &second);

        _flushall();

        char op = getOperator();
        int result;

        switch (op) {
            case '+':
                result = add(first, second);
                printf("%d + %d = %d\n", first, second, result);
                break;
            case '-':
                result = subtract(first, second);
                printf("%d - %d = %d\n", first, second, result);
                break;
            case '*':
                result = multiply(first, second);
                printf("%d * %d = %d\n", first, second, result);
                break;
            case '/':
                result = divide(first, second);
                printf("%d / %d = %d\n", first, second, result);
                break;
            default:
                printf("Error! Operator is not correct.\n");
        }
        printf("\n");

        _flushall();

        printf("Continue? (y or n)\n");
        scanf("%c", &continuecalculation);
        printf("\n");
    } while (continuecalculation == 'y' || continuecalculation == 'Y');

    return 0;
}
