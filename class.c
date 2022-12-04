#include <stdio.h>
#include <string.h>
#include <time.h>
// void setpass(void);

struct student
{
    char studentname[50];
    char id[20];
    char email[50];
    char section[3];
    char coursename[25];
    char coursecode[10];
    char contactno[15];
    char deadline[15];
    char date[12];
    char attd[20];
    char department[15];
} s;

struct faculty
{
    char facultyname[50];
    char designation[30];
    char email[50];
    char contactno[15];
    char regcourse[20];
    char coursecode[10];
    char assignment[500];
    char homework[500];
    char deadline[15];
    char date[12];
    char apass[30];
    char department[15];
    char section[3];

} f;
struct login
{
    char userid[20];
    char pass[8];
} l;
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
        printf("\n                                                                                   3. SIGN IN\n");
        printf("\n                                                                                   4. EXIT\n\n");
        printf("                                                                                     SELECT AN OPTION : ");

        int option;
        scanf("%d", &option);
        if (option == 1)
        {
            system("clear");
            facultylogin();
            // mainmenue();
            continue;
        }
        else if (option == 2)
        {
            system("clear");
            studentlogin();
            // studentmenue();
            continue;
        }
        else if (option == 3)
        {
            system("cls");
            signin();
            continue;
        }
        else if (option == 4)
        {
            exit(0);
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
        printf("                                                                                                            1.ADD INFO                   \n");
        printf("                                                                                                            2.ADD ASSIGNMENT             \n");
        printf("                                                                                                            3.ADD HW                     \n");
        printf("                                                                                                            4.ATTENDENCE LIST           \n");
        printf("                                                                                                            5.SEARCH STUDENT         \n");
        printf("                                                                                                            6.SET PASSWORD         \n");
        printf("                                                                                                            7.LOG OUT                   \n");
        int ch;
        printf("                                                                                                                       ENTER YOUR CHOICE : ");
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
            attendencelist();
            continue;
        }
        else if (ch == 5)
        {
            system("clear");
            searchinfo();
            continue;
        }
        else if (ch == 6)
        {
            system("clear");
            system("cls");
            setpass();
            continue;
        }

        else if (ch == 7)
        {
            system("clear");
            system("cls");
            main();
            continue;
        }
        getch();
    }
}
void addinfo(void)

{
    system("cls");
    title();
    printf("\n\n");
    file = fopen("faculty.txt", "w");
    printf("                                                     NAME : ");
    fflush(stdin);
    gets(f.facultyname);
    printf("                                                     DESIGNATION : ");
    fflush(stdin);
    gets(f.designation);
    printf("                                                     EMAIL : ");
    fflush(stdin);
    gets(f.department);
    printf("                                                     DEPARTMENT : ");
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
    printf("                                                  ENTER DEADLINE   :  ");
    fflush(stdin);
    gets(f.deadline);
    f.deadline[0] = toupper(f.deadline[0]);
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
    printf("                                                   ENTER DEADLINE :  ");
    fflush(stdin);
    gets(f.deadline);
    f.deadline[0] = toupper(f.deadline[0]);
    printf("\n                                                                                          |||Homework Updated Sucessfully|||");
    fwrite(&f, sizeof(f), 1, file);
    fclose(file);

    getch();
}
void studentmenue()
{
    while (1)
    {
        system("cls");
        title();
        printf("                                                                                               1.ADD INFO         \n");
        printf("                                                                                               2.ASSIGNMENT          \n");
        printf("                                                                                               3.HW                  \n");
        printf("                                                                                               4.ATTENDENCE          \n");
        printf("                                                                                               5.FACULTY DETAILS     \n");
        printf("                                                                                               6.LOG OUT             \n");
        int ch;
        printf("                                                                                                    ENTER YOUR CHOICE : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            system("clear");
            studentinfo();
            continue;
        }
        else if (ch == 2)
        {
            system("clear");
            assignment();
            continue;
        }
        else if (ch == 3)
        {
            system("clear");
            homework();
            continue;
        }
        else if (ch == 4)
        {
            system("clear");
            giveattendence();
            continue;
        }
        else if (ch == 5)
        {
            system("clear");
            system("cls");
            facultydetails();
            continue;
        }

        else if (ch == 6)
        {
            system("clear");
            system("cls");
            main();
            continue;
        }
        getch();
    }
}
void studentinfo(void)
{
    system("cls");
    title();
    printf("\n\n");
    file = fopen("student.txt", "ab");
    printf("                                                     NAME : ");
    fflush(stdin);
    gets(s.studentname);
    printf("                                                     ID : ");
    fflush(stdin);
    gets(s.id);
    printf("                                                     DEPARTMENT : ");
    fflush(stdin);
    gets(s.department);
    printf("                                                     EMAIL : ");
    fflush(stdin);
    gets(s.email);
    printf("                                                     CONTACT NUMBER : ");
    fflush(stdin);
    gets(s.contactno);
    printf("                                                     SECTION : ");
    fflush(stdin);
    gets(s.section);

    printf("                                                     COURSE NAME : ");
    fflush(stdin);
    gets(s.coursename);
    printf("                                                     COURSE CODE : ");
    gets(s.coursecode);
    fflush(stdin);

    printf("\n                                                                                          |||INFO ADDED SUCCESSFULLY|||");
    fwrite(&s, sizeof(s), 1, file);

    fclose(file);

    getch();
}
void assignment()
{

    system("cls");

    printf("   %s- - - - - - - - - - - - - - - - - - -%10s- - - - - - - - - - - - - - - - - - - - - - - -%10s\n", "DATE", "DEADLINE", "ASSIGNMENT");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    file = fopen("assignment.txt", "rb");
    while (fread(&f, sizeof(f), 1, file) == 1)
    {
        printf("%s                 %s                       [ %s ]\n", f.date, f.deadline, f.assignment);
    }

    fclose(file);
    getch();
}

void homework()
{

    system("cls");
    // printf("<== Patient List ==>\n\n");
    printf("   %s- - - - - - - - - - - - - - - - - - -%10s- - - - - - - - - - - - - - - - - - - - - - - -%10s\n", "DATE", "DEADLINE", "HOMEWORK");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    file = fopen("homework.txt", "rb");
    while (fread(&f, sizeof(f), 1, file) == 1)
    {
        printf("%s                 %s                       [ %s ]\n", f.date, f.deadline, f.homework);
    }

    fclose(file);
    getch();
}
void facultydetails()
{

    system("cls");
    title();
    file = fopen("faculty.txt", "rb");
    while (fread(&f, sizeof(f), 1, file) == 1)
    {
        printf("                                                                                           NAME : %s\n\nDESIGNATION : %s\n\nDEPARTMENT : %s\n\nE-MAIL : %s\n\nCONTACT NO. : %s\n\nCOURSE : %s\n\nCOURSE CODE : %s", f.facultyname, f.designation, f.department, f.email, f.contactno, f.regcourse, f.coursecode);
    }

    fclose(file);
    getch();
}
void searchinfo()
{

    system("cls");
    title();
    char id[20];
    printf("ENTER ID : ");
    scanf("%s", &id);

    file = fopen("student.txt", "rb");

    while (fread(&s, sizeof(s), 1, file) == 1)

    {
        if (strcmp(s.id, id) == 0)
        {
            system("cls");
            title();
            printf("                                                                                      NAME : %s\nID : %s\nE-MAIL : %s\nSECTION : %s\nCOURSE : %s\nCOURSE CODE : %s\n", s.studentname, s.id, s.email, s.section, s.coursename, s.coursecode);
        }
        else if ((strcmp(s.id, id) != 0))
        {
            system("cls");
            title();
            printf("                                                                                                      !!!NOT FOUND!!!\n");
        }
    }

    fclose(file);
    getch();
}

void setpass(void)
{
    system("cls");
    title();
    file = fopen("apassword.txt", "w");
    printf("                                                                      |||SET PASSWORD FOR ATTENDENCE|||");
    printf("ENTER PASSWORD : ");
    fflush(stdin);
    gets(f.apass);
    fwrite(&f, sizeof(f), 1, file);
    fclose(file);
    getch();
}

void giveattendence(void)
{

    system("cls");
    title();

    printf("\n\n");
    printf("                                                                        |||GIVE YOUR ATTENDENCE HERE|||");
    printf("\n\n");

    char pass[30];
    printf("                                                                               ENTER PASSWORD : ");
    fflush(stdin);
    gets(pass);
    file = fopen("apassword.txt", "rb");
    if (strcmp(f.apass, pass) == 0)
    {

        system("cls");
        title();
        char myDate[12];
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        strcpy(s.date, myDate);

        file = fopen("attendence.txt", "ab");
        printf("                                                                               ENTER YOUR ID : ");
        fflush(stdin);

        gets(s.attd);
        fwrite(&s, sizeof(s), 1, file);
        fclose(file);
        getch();
    }
    else
    {
        printf("                                                                           SORRY!     WRONG    PASSWORD!");
        getch();
        studentmenue();
        getch();
    }
}
void attendencelist()
{

    system("cls");
    title();

    printf("   %s                     |            %10s", "DATE", "ID");
    printf("\n------------------------------------------------------\n");

    file = fopen("attendence.txt", "rb");
    while (fread(&s, sizeof(s), 1, file) == 1)
    {
        printf("%s                  |                   %s \n", s.date, s.attd);
    }

    fclose(file);
    getch();
}

void ssignin(void)
{
    system("cls");
    title();
    printf("\n\n");
    file = fopen("spassword.txt", "ab");
    printf("                                                                           YOUR ID : ");
    fflush(stdin);
    gets(l.userid);
    printf("                                                                           ENTER A PASSWORD(MAX 8 CHARECTERS) :  ");
    fflush(stdin);
    gets(l.pass);
    printf("\n                                                                                          |||Singed in Sucessfull|||");
    fwrite(&l, sizeof(l), 1, file);
    fclose(file);
    getch();
}
void fsignin(void)
{
    system("cls");
    title();
    printf("\n\n");
    file = fopen("fpassword.txt", "ab");
    printf("                                                                           ENTER USER NAME(COURSE CODE) : ");
    fflush(stdin);
    gets(l.userid);
    printf("                                                                           ENTER A PASSWORD(MAX 8 CHARECTERS) :  ");
    fflush(stdin);
    gets(l.pass);
    printf("\n                                                                                          |||Singed   in   Sucessfull|||");
    fwrite(&l, sizeof(l), 1, file);
    fclose(file);
    getch();
}
void signin(void)
{
    system("cls");
    title();
    printf("\n\n");
    printf("                                                                         1. FACULTY SIGNIN\n");
    printf("                                                                         2. STUDENT SIGNIN\n");
    int ch;
    printf("                                                                          ENTER AN OPTION : ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        system("cls");
        title();
        fsignin();
    }
    else if (ch == 2)
    {
        system("cls");
        title();
        ssignin();
    }
    getch();
}
void facultylogin(void)
{

    system("cls");
    title();
    printf("\n\n");
    char uname[20];
    printf("                                                                   ENTER USER NAME : ");
    fflush(stdin);
    gets(uname);

    char pass[8];
    printf("                                                                   ENTER PASSWORD : ");
    fflush(stdin);
    gets(pass);
    file = fopen("fpassword.txt", "rb");
    while (fread(&l, sizeof(l), 1, file) == 1)
    {
        if (strcmp(l.userid, uname) == 0 && strcmp(l.pass, pass) == 0)
        {
            system("cls");
            title();
            mainmenue();
            getch();
        }
        else
        {
            printf("                                                              !!!WRONG       USERNAME       OR       PASSWORD!!!");
            getch();
            main();
            getch();
        }
    }
}
void studentlogin(void)
{

    system("cls");
    title();
    char uname[20];
    printf("                                                                         ENTER USER NAME : ");
    fflush(stdin);
    gets(uname);

    char pass[8];
    printf("                                                                         ENTER PASSWORD : ");
    fflush(stdin);
    gets(pass);
    file = fopen("spassword.txt", "rb");
    while (fread(&l, sizeof(l), 1, file) == 1)
    {
        if (strcmp(l.userid, uname) == 0 && strcmp(l.pass, pass) == 0)
        {
            system("cls");
            title();
            studentmenue();
            getch();
        }
        else
        {
            printf("                                                                !!!WRONG         USERNAME    OR     PASSWORD!!!");
            getch();
            main();
            getch();
        }
    }
}