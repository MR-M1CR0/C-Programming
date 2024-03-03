#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    printf("Press a key\n");
    ch = getch();

    if(ch == -32)
    {
        ch = getch();
        printf("Extended %i", ch);
    }
    else
    {
        printf("Normal %i", ch);
    }
    printf("\n");

    return 0;
}
