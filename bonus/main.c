#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct Student{
    int id;
    char Name[5];
    int grades[4];
};

void gotoxy1(int x, int y);
void PrintStudent(struct Student e);
struct Student Fill(void);

int main()
{
    struct Student s[3];
    int x=0,y=0;
    int i;
    char in;
    int count = 0;

    while(y!=13)
    {
        system("cls");
        printMenu();
        gotoxy1(x,y);
        in=getch();
        if(in==-32)
            in=getch();

        if(in==80)
        {
            if(y==3)
                y=0;

            else
                y++;
        }

        else if(in==72)
        {
            if(y==0)
                y=3;

            else
                y--;
        }

        else if(in==13)
        {
            system("cls");
            switch(y)
            {
            case 0:
                s[count] = Fill();
                count++;
                break;
            case 1:
                printf("Enter the student index(from 0 to 2): ");
                scanf("%d", &i);
                PrintStudent(s[i]);
                getch();
                break;
            case 2:
                for(i=0;i<count;i++)
                {
                    PrintStudent(s[i]);
                }
                getch();
                break;
            case 3:
                y = 13;
                break;
            }
        }

    }

    return 0;
}

void PrintStudent(struct Student s)
{
    int i;

    printf("\n");
    printf("The student ID is: %d\n", s.id);
    printf("The student name is: %s\n", s.Name);

    for(i=0;i<4;i++)
    {
        printf("The student grade in subject number %d: %d\n", i+1, s.grades[i]);
    }
}

struct Student Fill(void)
{
    struct Student s;
    int i;

    printf("Please, Enter the student ID: ");
    scanf("%d", &s.id);
    printf("Please, Enter the student Name: ");
    scanf("%s", s.Name);
    printf("Please, Enter the student Grades\n");
    for(i=0;i<4;i++)
    {
        printf("Subject number %d: ", i+1);
        scanf("%d",&s.grades[i]);
    }

    printf("\n");
    return s;
}

void gotoxy1(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMenu(void)
{
    gotoxy1(2,0);
    printf("1-Add Student");
    gotoxy1(2,1);
    printf("2-Display Student");
    gotoxy1(2,2);
    printf("3-Display All Students");
    gotoxy1(2,3);
    printf("4-Exit");
}
