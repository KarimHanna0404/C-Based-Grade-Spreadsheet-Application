#include "ordering.h"

int A = 80;
int B = 70;
int C = 60;
int D = 50;
int F = 40;

// comparison function to sort by ID
int compareByID(const void *a, const void *b)
{
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;

    return (studentA->ID - studentB->ID); // Ascending order
}
// comparison function to sort by Last Name
int compareByLastName(const void *a, const void *b)
{
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return strcmp(studentA->LastName, studentB->LastName);
}
// comparison function to sort by grade
int compareByTotalGrade(const void *a, const void *b)
{
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;

    if (studentA->finalgrade > studentB->finalgrade)
        return -1; // Higher grades should come first
    else if (studentA->finalgrade < studentB->finalgrade)
        return 1;
    else
        return 0;
}

int CompareByExamGrade(const void *a, const void *b)
{
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;

    if (studentA->Exam > studentB->Exam)
        return -1; // higher grade first
    else if (studentA->Exam < studentB->Exam)
        return 1;
    else
        return 0;
}