#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void MultibleArrayByTen(int * param,int size)
{
    param[0]*=10;
    param[1]*=10;
    param[2]*=10;
}

int* TryMe()
{
    static int arr[5]={1,2,3,4,5};
    return arr;
}

struct Employee
{
    int id;
    char name[10];
    int age;
};

int main()
{
    //1
    int num;
    int *ptr = &num;
    printf("please enter a number: ");
    scanf("%d", ptr);;
    printf("you entered: %d\n", *ptr);

    //2
    char arr[50];
    char *ptr2 = arr;
    printf("please enter your name: ");
    scanf("%s", ptr2);
    printf("you entered: %s\n", ptr2);
    //2 other ways
    int arr2[5];
    int *ptr10 = arr2;
    for(int i=0; i<5; i++)
    {
        *ptr10=10;
        ptr10++;
    }
    ptr10=arr2;
    for(int i=0; i < 5; i++)
    {
        printf("%i",*ptr10);
        ptr10++;
    }
    ptr10=arr2;
    printf("\n");
    //
    int arr3[5];
    int *ptr20=arr3;
    for(int i=0;i<5;i++)
    {
        *(ptr20+i)=10;
    }
    for(int i=0;i<5;i++)
    {
        printf("%i",*(ptr20+i));
    }
    printf("\n");
    //
    int arr4[5];
    int *ptr30=arr4;
    for(int i=0;i<5;i++)
    {
        arr4[i]=10;
    }
    for(int i=0;i<5;i++)
    {
        ptr30[i]=10;
    }
    for(int i=0;i<4;i++)
    {
        printf("%i",ptr30[i]);
    }

    //3
    int num2 = 10;
    int *firstptr = &num2;
    int **secondptr = &firstptr;
    printf("%d\n", **secondptr);

    //4
    int a = 10;
    int b = 20;
    printf("before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("after swap: a = %d, b = %d\n", a, b);

    //5
    int myArray[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);
    printArray(myArray, arraySize);

    //6
    int arr50[5]={1,2,3,4,5};
    MultibleArrayByTen(arr50,5);
    //
    int *ptr100=TryMe();
    for(int i=0; i<5; i++)
    {
        ptr100[i]=(55+i);
    }
    for(int i=0; i<5; i++)
    {
        printf("%d\n", ptr100[i]);
    }

    //7
    struct Employee e1;
    struct Employee *empPtr;
    empPtr=&e1;
    (*empPtr).id=20;
    empPtr->age=24;
    strcpy(empPtr->name, "Ahmed");
    printf("ID: %i\n", empPtr->id);
    printf("Age: %i\n", empPtr->age);
    printf("Name: %s\n", empPtr->name);
    return 0;
}
