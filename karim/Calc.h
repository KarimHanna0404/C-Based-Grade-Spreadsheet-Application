#ifndef CALC_H
#define CALC_H

#include "ordering.h"
struct Student; // Forward declaration of Student structure

void calculateGrade(struct Student *s);
void AssignLetterGrade(int examGrade, char *grade);
void histogram(struct Student *s, int count);
void UpdateGradeMapping(struct Student *s, int count);

#endif
