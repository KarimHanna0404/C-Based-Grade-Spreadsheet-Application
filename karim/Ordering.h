#ifndef ORDERING_H
#define ORDERING_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char FirstName[20];
    char LastName[20];
    int ID;
    int midterm;
    int grade;
    int A1;
    int A2;
    int A3;
    int Exam;
    double finalgrade;
    char charGrade;
};

extern int A;
extern int B;
extern int C;
extern int D;
extern int F;

int compareByID(const void *a, const void *b);
int compareByLastName(const void *a, const void *b);
int compareByTotalGrade(const void *a, const void *b);
int CompareByExamGrade(const void *a, const void *b);

#endif
