#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char userinput[50];
    char ch;
    int i = 0;

    printf("please enter your message\n");

    while ((ch = getche()) != 13)
    {
        userinput[i] = ch;
        i++;
    }
    userinput[i] = '\0';

    system("cls");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", userinput[j]);
    }

    return 0;
}
