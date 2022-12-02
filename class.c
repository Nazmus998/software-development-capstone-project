#include <stdio.h>
#include <string.h>
#include <time.h>

struct student
{
    char studentname[50];
    int id;
    char email[50];
    char section[3];
    char coursename[25];
    char coursecode[10];
    char date[12];
} s;

struct faculty
{
    char facultyname[50];
    char designation[30];
    char email[50];
    char contactno[12];
    char regcourse[20];
    char coursecode[10];
    char assignment[500];
    char homework[500];
    char date[12];
} f;
FILE *file;
int main()
{

    while (1)
    {
        printf("\n                                 |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n                                 |                                                                                                                           |\n");
        printf("\n                                 |                                   WELCOME  TO THE REAL WORLD OF SOFTWARE ENGINEERING                                      |\n");
        printf("\n                                 |                                       Software-Development-Capstone-Project-SE133                                         |\n");
        printf("\n                                 |                                                                                                                           |\n");
        printf("\n                                 |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

        printf("\n                                                                                   1. Faculty Login    \n");
        printf("\n                                                                                   2. Student Login    \n");
        printf("\n                                                                                   3. Exit\n\n");
        printf("                                                                                     Select a option : ");

        int option;
        scanf("%d", &option);
        if (option == 1)
        {
            system("clear");
            // faculty_login();
            mainmenue();
            continue;
        }
        if (option == 2)
        {
            system("clear");
            // student_login();
            continue;
        }
        if (option == 3)
        {
            return 0;
        }
        getch();
    }
}
void mainmenue(void)
{
    while (1)
    {
        system("cls");
        printf("                                              -----------------------------------------------------------------------------------------------------------------------\n");
        printf("                                                                                   WELCOME TO THE DIGITAL CLASS MANAGEMENT SYSTEM                                \n");
        printf("                                                                                                GREETINGS FROM NS998                                                        \n");
        printf("                                              ------------------------------------------------------------------------------------------------------------------------\n");
        printf("                                                                                                             \n\t\t\t1.ADD INFO                   \n");
        printf("                                                                                                             \n\t\t\t2.ADD ASSIGNMENT             \n");
        printf("                                                                                                             \n\t\t\t3.ADD HW                     \n");
        printf("                                                                                                             \n\t\t\t4.ATTENDENCE LIST           \n");
        printf("                                                                                                             \n\t\t\t6.LOG OUT                   \n");
        int ch;
        printf("                                                                                               ENTER YOUR CHOICE : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            system("clear");
            addinfo();
            continue;
        }
        else if (ch == 2)
        {
            system("clear");
            addassignment();
            continue;
        }
        else if (ch == 3)
        {
            system("clear");
            addhw();
            continue;
        }
        else if (ch == 4)
        {
            system("clear");
            // attendlist
            continue;
        }
       
        else if (ch == 5)
        {
            system("clear");
            system("cls");
            main();
            continue;
        }
    }
}
void addinfo(void)

{
    system("cls");
    title();
    printf("\n\n");
    file = fopen("faculty.txt", "ab");
    printf("                                                     NAME : ");
    fflush(stdin);
    gets(f.facultyname);
    printf("                                                     DESIGNATION : ");
    fflush(stdin);
    gets(f.designation);
    printf("                                                     EMAIL : ");
    fflush(stdin);
    gets(f.email);
    printf("                                                     CONTACT NUMBER : ");
    fflush(stdin);
    gets(f.contactno);

    printf("                                                     COURSE NAME : ");
    fflush(stdin);
    gets(f.regcourse);
    printf("                                                     COURSE CODE : ");
    gets(f.coursecode);
    fflush(stdin);

    printf("\n                                                                                          |||INFO ADDED SUCCESSFULLY|||");
    fwrite(&f, sizeof(f), 1, file);

    fclose(file);

    getch();
}
void title(void)
{
    printf("                                               -----------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                                                   WELCOME TO THE DIGITAL CLASS MANAGEMENT SYSTEM                                \n");
    printf("                                                                                                GREETINGS FROM NS998                                                        \n");
    printf("                                               ------------------------------------------------------------------------------------------------------------------------\n");
}
void addassignment()
{
    system("cls");
    title();
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(f.date, myDate);
    file = fopen("assignment.txt", "ab");
    printf("                                                  ENTER ASSIGNMENT :  ");
    fflush(stdin);
    gets(f.assignment);
    f.assignment[0] = toupper(f.assignment[0]);
    printf("\n                                                                                          |||Assignment Updated Sucessfully|||");
    fwrite(&f, sizeof(f), 1, file);
    fclose(file);

    getch();
}
void addhw()
{
    system("cls");
    title();
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(f.date, myDate);
    file = fopen("homework.txt", "ab");
    printf("                                                   ENTER HOMEWORK :  ");
    fflush(stdin);
    gets(f.homework);
    f.homework[0] = toupper(f.homework[0]);
    printf("\n                                                                                          |||Homework Updated Sucessfully|||");
    fwrite(&f, sizeof(f), 1, file);
    fclose(file);

    getch();
}
