#include <stdio.h>
#include <stdlib.h>

int main()
{
  char op;
  int first, second;
  char continuecalculation = 'y';

  do
  {
    printf("Enter first number : ");
    scanf("%d", &first);

    printf("Enter second number : ");
    scanf("%d", &second);

    _flushall();

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    switch (op) {
        case '+':
            printf("%d + %d = %d\n", first, second, first + second);
            break;

        case '-':
            printf("%d - %d = %d\n", first, second, first - second);
            break;

        case '*':
            printf("%d * %d = %d\n", first, second, first * second);
            break;

        case '/':
            printf("%d / %d = %d\n", first, second, first / second);
            break;

        default:
            printf("Error! operator is not correct");
    }

    _flushall();

    printf("Continue ??? y or n\n");
    scanf("%c", &continuecalculation);

  } while (continuecalculation == 'y' || continuecalculation == 'Y');

    return 0;
}
