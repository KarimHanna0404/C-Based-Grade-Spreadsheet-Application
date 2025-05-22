#include "data.h" // This file includes its own header

int LoadsStudentFile(struct Student **students)
{ // Pointer to pointer
    FILE *file_ptr = fopen("students.txt", "rb");
    if (file_ptr == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    char line[256];
    int count = 0;
    int capacity = 10;
    *students = (struct Student *)malloc(capacity * sizeof(struct Student));

    if (*students == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file_ptr);
        return 0;
    }

    // Parse the file line by line
    while (fgets(line, sizeof(line), file_ptr))
    {
        if (count >= capacity)
        {
            // Double the size of the array if more space is needed
            capacity *= 2;
            struct Student *temp = realloc(*students, capacity * sizeof(struct Student));
            if (temp == NULL)
            {
                printf("Memory reallocation failed\n");
                free(*students);
                fclose(file_ptr);
                return 0;
            }
            *students = temp;
        }

        // Parse the line into the student struct
        sscanf(line, "%d|%[^|]|%[^|]|%d|%d|%d|%d|%d",
               &(*students)[count].ID,
               (*students)[count].LastName,
               (*students)[count].FirstName,
               &(*students)[count].A1,
               &(*students)[count].A2,
               &(*students)[count].A3,
               &(*students)[count].midterm,
               &(*students)[count].Exam);

        // Calculate the grade for each student
        calculateGrade(&(*students)[count]);

        count++;
    }

    fclose(file_ptr);
    return count; // Return the number of students loaded
}

void ChangeStudentID(struct Student *s, int count)
{
    int StudentID;
    int found = 0;
    printf("Enter Student ID: ");
    scanf("%d", &StudentID);

    for (int i = 0; i < count; i++)
    {
        if (s[i].ID == StudentID)
        {
            char newLastName[20];
            found = 1;
            printf("Enter the new last name");
            scanf("%s", newLastName);
            // updating name
            strcpy(s[i].LastName, newLastName);
            printf("Last name updated successfully!\n");
            break;
        }
    }
    if (!found)
    {
        printf("Student ID doesn't exist\n");
    }
}

void ChangeStudentExamGrade(struct Student *s, int count)
{
    int StudentID;
    int found = 0;

    printf("Enter Student ID: ");
    scanf("%d", &StudentID);

    for (int i = 0; i < count; i++)
    {
        if (s[i].ID == StudentID)
        {
            int newExamGrade;
            found = 1;

            printf("Enter the new Exam grade: ");
            scanf("%d", &newExamGrade);

            if (newExamGrade > 40 || newExamGrade < 0)
            {
                printf("please enter a grade range from 0-40");
                continue;
            }

            s[i].Exam = newExamGrade;

            // Reassign the letter grade based on the new exam grade
            AssignLetterGrade(s[i].Exam, &s[i].charGrade);

            printf("Exam grade updated successfully!\n");
            printf("New Exam grade: %d, New Letter grade: %c\n", s[i].Exam, s[i].charGrade);
            break;
        }
    }

    if (!found)
    {
        printf("Student ID doesn't exist.\n");
    }
}

void removeStudent(struct Student *s, int *count)
{
    int StudentID;
    int found = 0;
    printf("Enter Student ID: ");
    scanf("%d", &StudentID);
    for (int i = 0; i < *count; i++)
    {
        if (s[i].ID == StudentID)
        {
            found = 1;
            // Move each student one position left
            for (int j = i; j < *count - 1; j++)
            {
                s[j] = s[j + 1];
            }
            (*count)--;
            printf("Student has been succesfully removed!");
            break;
        }
    }
    if (!found)
    {
        printf("Student ID doesn't exist\n");
    }
}