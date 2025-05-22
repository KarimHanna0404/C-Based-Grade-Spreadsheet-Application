#include "calc.h" // This file includes its own header

void calculateGrade(struct Student *s)
{
    double AssignmentPercentage = ((s->A1 + s->A2 + s->A3) / 120.0) * 25;
    double midtermPercenage = (s->midterm / 25.0) * 25;
    double ExamPercentage = (s->Exam / 40.0) * 50;

    s->finalgrade = AssignmentPercentage + midtermPercenage + ExamPercentage;

    if (s->finalgrade >= A)
    {
        s->charGrade = 'A';
    }
    else if (s->finalgrade >= B)
    {
        s->charGrade = 'B';
    }
    else if (s->finalgrade >= C)
    {
        s->charGrade = 'C';
    }
    else if (s->finalgrade <= D)
    {
        s->charGrade = 'D';
    }
    else
    {
        s->charGrade = 'F';
    }
}
void AssignLetterGrade(int examGrade, char *grade)
{
    if (examGrade >= A)
    {
        *grade = 'A';
    }
    else if (examGrade >= B)
    {
        *grade = 'B';
    }
    else if (examGrade >= C)
    {
        *grade = 'C';
    }
    else if (examGrade >= D)
    {
        *grade = 'D';
    }
    else
    {
        *grade = 'F';
    }
}

void histogram(struct Student *s, int count)
{
    int GradeA = 0;
    int GradeB = 0;
    int GradeC = 0;
    int GradeD = 0;
    int GradeF = 0;

    for (int i = 0; i < count; i++)
    {
        switch (s[i].charGrade)
        {
        case 'A':
            GradeA++;
            break;
        case 'B':
            GradeB++;
            break;
        case 'C':
            GradeC++;
            break;
        case 'D':
            GradeD++;
            break;
        case 'F':
            GradeF++;
            break;

        default:
            printf("wrong grade letter\n");
            break;
        }
    }
    printf("\nCOMP 348 Grade Distribution Histogram");
    printf("\nGrade A: ");
    for (int i = 0; i < GradeA; i++)
    {
        printf("*");
    }
    printf("\nGrade B: ");
    for (int i = 0; i < GradeB; i++)
    {
        printf("*");
    }
    printf("\nGrade C: ");
    for (int i = 0; i < GradeC; i++)
    {
        printf("*");
    }
    printf("\nGrade D: ");
    for (int i = 0; i < GradeD; i++)
    {
        printf("*");
    }
    printf("\nGrade F: ");
    for (int i = 0; i < GradeF; i++)
    {
        printf("*");
    }
}

void UpdateGradeMapping(struct Student *s, int count)
{

    int Atemp = A;
    int Btemp = B;
    int Ctemp = C;
    int Dtemp = D;
    int Ftemp = F;

    printf("Current Mapping: \n");
    printf("A: >= %d\n", A);
    printf("B: >= %d\n", B);
    printf("C: >= %d\n", C);
    printf("D: >= %d\n", D);
    printf("F:  < %d\n", D);

    printf("Enter new grade mapping for A: ");
    scanf("%d", &A);
    printf("Enter new grade mapping for B: ");
    scanf("%d", &B);
    printf("Enter new grade mapping for C: ");
    scanf("%d", &C);
    printf("Enter new grade mapping for D: ");
    scanf("%d", &D);

    if (A < 0 || B < 0 || C < 0 || D < 0 || F < 0)
    {
        A = Atemp;
        B = Btemp;
        C = Ctemp;
        D = Dtemp;
        F = Ftemp;
        printf("Please do not enter a negative value");
    }

    else if (A > 100 || B > 100 || C > 100 || D > 100 || F > 100)
    {
        A = Atemp;
        B = Btemp;
        C = Ctemp;
        D = Dtemp;
        F = Ftemp;
        printf("Please do not enter a value greater than 100");
    }
    else if (A > B && B > C && C > D && D >= 0)
    {
        for (int i = 0; i < count; i++)
        {
            AssignLetterGrade(s[i].finalgrade, &s[i].charGrade);
        }
        printf("Grade mappings updated successfully!\n");
    }
    else
    {
        A = Atemp;
        B = Btemp;
        C = Ctemp;
        D = Dtemp;
        F = Ftemp;
    }
}