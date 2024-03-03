#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#define Extended -32
#define Enter 13
#define Esc 27
#define Home 71
#define End 79
#define Up 72
#define Down 80

#define MAX_LABEL_LENGTH 20
#define MAX_INPUT_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    int ssn;
    char name[MAX_INPUT_LENGTH];
    int age;
    float salary;
    float commission;
    float deduction;
    float netSalary;
} Employee;

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

float calculateNetSalary(float salary, float commission, float deduction) {
    return salary + commission - deduction;
}


int main()
{
    char menu[8][20] = {"New", "Display All", "Display By SSN", "Delete All", "Delete By SSN", "Display By Name", "Delete By Name", "Exit"};
    int cursor = 0;
    int flag = 1;
    char ch;
    int numEntries;

    do {
        printf("Enter the number of employees (1 to 10): ");
        scanf("%d", &numEntries);
    } while (numEntries < 1 || numEntries > 10);

    Employee *employees = (Employee *)malloc(numEntries * sizeof(Employee));

    do
    {
        system("cls");
        for (int i = 0; i < 8; i++)
        {
            if (cursor == i)
            {
                textattr(14);
            }
            else
            {
                textattr(7);
            }
            gotoxy(10, 5 + i * 2);
            printf("%s", menu[i]);
        }

        ch = getch();

        switch (ch)
        {
            case Extended:
            ch = getch();
            switch (ch)
            {
                case Up:
                cursor--;
                if (cursor < 0)
                {
                    cursor = 7;
                }
                break;
                case Down:
                cursor++;
                if (cursor > 7)
                {
                    cursor = 0;
                }
                break;
                case Home:
                cursor = 0;
                break;
                case End:
                cursor = 7;
                break;
            }
            break;
            case Enter:
            switch (cursor)
            {
                case 0:
                    system("cls");
                    for (int entry = 0; entry < numEntries; entry++)
                    {
                        system("cls");
                        printf("Enter data for Entry %d:\n", entry + 1);
                        gotoxy(7, 2);
                        printf("SSN: ");
                        scanf("%d", &employees[entry].ssn);
                        gotoxy(50, 2);
                        printf("Name: ");
                        scanf("%s", employees[entry].name);
                        gotoxy(7, 8);
                        printf("Age: ");
                        scanf("%d", &employees[entry].age);
                        gotoxy(50, 8);
                        printf("Salary: ");
                        scanf("%f", &employees[entry].salary);
                        gotoxy(7, 14);
                        printf("Commission: ");
                        scanf("%f", &employees[entry].commission);
                        gotoxy(50, 14);
                        printf("Deduction: ");
                        scanf("%f", &employees[entry].deduction);
                        employees[entry].netSalary = calculateNetSalary(employees[entry].salary, employees[entry].commission, employees[entry].deduction);
                        printf("\nPress Enter to proceed to the next entry...");
                        getchar();
                    }
                    break;
                case 1:
                    system("cls");
                    for (int i = 0; i < numEntries; i++)
                    {
                        printf("Entry %d:\n", i + 1);
                        printf("SSN: %d\n", employees[i].ssn);
                        printf("Name: %s\n", employees[i].name);
                        printf("Age: %d\n", employees[i].age);
                        printf("Salary: %f\n", employees[i].salary);
                        printf("Commission: %f\n", employees[i].commission);
                        printf("Deduction: %f\n", employees[i].deduction);
                        printf("\n");
                        printf("Net Salary: %f\n\n", employees[i].netSalary);
                    }
                    printf("Press Enter to go back...");
                    getch();
                    break;
                case 2:
                {
                    system("cls");
                    int searchSSN;
                    int found = 0;
                    printf("Enter the SSN to display: ");
                    scanf("%d", &searchSSN);
                    for (int i = 0; i < numEntries; i++)
                    {
                        if (searchSSN == employees[i].ssn)
                        {
                            printf("Entry Information for SSN %d:\n", employees[i].ssn);
                            printf("Name: %s\n", employees[i].name);
                            printf("Age: %d\n", employees[i].age);
                            printf("Salary: %f\n", employees[i].salary);
                            printf("Commission: %f\n", employees[i].commission);
                            printf("Deduction: %f\n", employees[i].deduction);
                            printf("Net Salary: %f\n\n", employees[i].netSalary);
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                        printf("SSN %d not found.\n", searchSSN);
                    printf("Press Enter to go back...");
                    getchar();
                    getchar();
                    break;
                }
                case 3:
                    system("cls");
                    numEntries = 0;
                    printf("All entries deleted.\n");
                    printf("Press Enter to go back...");
                    getchar();
                    break;
                case 4:
                {
                    system("cls");
                    int deleteSSN;
                    int found = 0;
                    printf("Enter the SSN to delete: ");
                    scanf("%d", &deleteSSN);
                    for (int i = 0; i < numEntries; i++)
                    {
                        if (deleteSSN == employees[i].ssn)
                        {
                            for (int j = i; j < numEntries - 1; j++)
                            {
                                employees[j].ssn = employees[j + 1].ssn;
                                strcpy(employees[j].name, employees[j + 1].name);
                                employees[j].age = employees[j + 1].age;
                                employees[j].salary = employees[j + 1].salary;
                                employees[j].commission = employees[j + 1].commission;
                                employees[j].deduction = employees[j + 1].deduction;
                            }
                            numEntries--;
                            found = 1;
                            break;
                        }
                    }
                    if (found)
                        printf("Entry with SSN %d deleted.\n", deleteSSN);
                    else
                        printf("SSN %d not found.\n", deleteSSN);
                    printf("Press Enter to go back...");
                    getchar();
                    getchar();
                    break;
                }
                case 5:
                {
                    system("cls");
                    char searchName[MAX_INPUT_LENGTH];
                    int found = 0;
                    printf("Enter the name to display: ");
                    scanf("%s", searchName);
                    for (int i = 0; searchName[i]; i++)
                    {
                        searchName[i] = tolower(searchName[i]);
                    }
                    for (int i = 0; i < numEntries; i++)
                    {
                        char lowercaseName[MAX_INPUT_LENGTH];
                        strcpy(lowercaseName, employees[i].name);
                        for (int j = 0; lowercaseName[j]; j++)
                        {
                            lowercaseName[j] = tolower(lowercaseName[j]);
                        }
                        if (strcmp(searchName, lowercaseName) == 0)
                            {
                                printf("Entry Information for Name %s:\n", employees[i].name);
                                printf("SSN: %d\n", employees[i].ssn);
                                printf("Age: %d\n", employees[i].age);
                                printf("Salary: %f\n", employees[i].salary);
                                printf("Commission: %f\n", employees[i].commission);
                                printf("Deduction: %f\n", employees[i].deduction);
                                printf("Net Salary: %f\n\n", employees[i].netSalary);
                                found = 1;
                            }
                    }
                    if (!found)
                        printf("No entry found for the name %s.\n", searchName);
                    printf("Press Enter to go back...");
                    getchar();
                    getchar();
                    break;
                }
                case 6:
                {
                    system("cls");
                    char deleteName[MAX_INPUT_LENGTH];
                    int found = 0;
                    printf("Enter the name to delete: ");
                    scanf("%s", deleteName);
                    for (int i = 0; deleteName[i]; i++)
                    {
                        deleteName[i] = tolower(deleteName[i]);
                    }
                    int i = 0;
                    while (i < numEntries)
                    {
                        char lowercaseName[MAX_INPUT_LENGTH];
                        strcpy(lowercaseName, employees[i].name);
                        for (int j = 0; lowercaseName[j]; j++)
                        {
                            lowercaseName[j] = tolower(lowercaseName[j]);
                        }
                        if (strcmp(deleteName, lowercaseName) == 0)
                        {
                            for (int j = i; j < numEntries - 1; j++)
                            {
                                employees[j].ssn = employees[j + 1].ssn;
                                strcpy(employees[j].name, employees[j + 1].name);
                                employees[j].age = employees[j + 1].age;
                                employees[j].salary = employees[j + 1].salary;
                                employees[j].commission = employees[j + 1].commission;
                                employees[j].deduction = employees[j + 1].deduction;
                            }
                            numEntries--;
                            found = 1;
                        }
                        else
                        {
                            i++;
                        }
                    }
                    if (found)
                        printf("Entries with the name %s deleted.\n", deleteName);
                    else
                        printf("No entries found for the name %s.\n", deleteName);
                    printf("Press Enter to go back...");
                    getchar();
                    getchar();
                    break;
                }
                case 7:
                    flag = 0;
                    break;
            }
            break;
            case Esc:
                flag = 0;
                break;
        }

    } while (flag == 1);

    free(employees);

    return 0;
}
