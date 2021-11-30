#include <stdio.h>
#include <stdlib.h>

struct Student{
    int id;
    char Name[5];
    int grades[4];
};

void PrintStudent(struct Student e);
struct Student Fill(void);

int main()
{
    struct Student s;

    s = Fill();
    PrintStudent(s);
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
