#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
int main()
{
    int size;
    int col;
    int row;

    do
    {
        printf("please enter the box size\n");
        scanf("%d", &size);
    }
    while(size < 1 || size > 9);

    system("cls");

    row=1;
    col=size/2+1;

    for(int i=1;i<=size*size;i++)
    {
        gotoxy(col*3+3,row*3);
        printf("%i",i);
        if(i%size!=0)
        {
            row--;
            col--;
            if(row<1){row=size;}
            if(col<1){col=size;}
        }
        else
        {
            row++;
        }
    }
    printf("\n\n");
    return 0;
}
