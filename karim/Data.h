#ifndef DATA_H
#define DATA_H

#include "Calc.h"
struct Student; // Forward declaration of Student structure

int LoadsStudentFile(struct Student **students);
void ChangeStudentID(struct Student *s, int count);
void ChangeStudentExamGrade(struct Student *s, int count);
void removeStudent(struct Student *s, int *count);

#endif
