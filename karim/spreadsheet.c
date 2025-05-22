#include "spreadsheet.h"

int sortchoice = -1;

void DisplayGradeSheet(struct Student *students, int count)
{
    // using q sort to sort students from smallest ID to largest ID

    switch (sortchoice)
    {
    case 1:
        qsort(students, count, sizeof(struct Student), compareByID);
        break;
    case 2:
        qsort(students, count, sizeof(struct Student), compareByTotalGrade);
        break;
    case 3:
        qsort(students, count, sizeof(struct Student), compareByLastName);
        break;
    case 4:
        qsort(students, count, sizeof(struct Student), CompareByExamGrade);
        break;
    default:
        qsort(students, count, sizeof(struct Student), compareByID);
    }

    printf("COMP 348 GRADE SHEET\n");
    printf("ID    Last      First     A1  A2  A3  Midterm  Exam  Total   Grade\n");
    printf("--    ----      -----     --  --  --  -------  ----  -----   -----\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-6d %-10s %-10s %-3d %-3d %-3d %-7d  %-4d  %-7.2lf  %c\n",
               students[i].ID, students[i].LastName, students[i].FirstName,
               students[i].A1, students[i].A2, students[i].A3,
               students[i].midterm, students[i].Exam, students[i].finalgrade,
               students[i].charGrade);
    }
}

void SetSortColumnChoice()
{
    printf("Choose Sort:\n");
    printf("1. Student ID\n");
    printf("2. Total Grade\n");
    printf("3. Last Name\n");
    printf("4. Exam Grade\n");

    int StudentChoice;
    printf("Enter Choice: ");
    scanf("%d", &StudentChoice);

    if (StudentChoice <= 0 || StudentChoice > 3)
    {
        StudentChoice = 1;
    }

    sortchoice = StudentChoice;
}

void DisplayMenu()
{
    system("clear");
    printf("Spreadsheet Menu\n");
    printf("-----------------\n");
    printf("1. Display Spreadsheet\n");
    printf("2. Display Histogram\n");
    printf("3. Set sort column\n");
    printf("4. Update Last name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Update grade Mapping\n");
    printf("7. Delete Student\n");
    printf("8. Exit\n");
}

void ColumnOptionDisplay(struct Student *s)
{
    printf("Column Option Display\n");
    printf("----------------------------");
    printf("1. Student ID");
    printf("2. Last Name");
    printf("3. Exam");
    printf("4. Total");
}

int main()
{
    struct Student *students = NULL;                // Pointer to students array
    int studentCount = LoadsStudentFile(&students); // Pass the address of the pointer

    if (studentCount > 0)
    {
        int choice = 0;
        while (choice != 8)
        {
            DisplayMenu();
            printf("Enter your choice: ");

            if (scanf("%d", &choice) != 1)
            {
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n')
                    ;
                choice = 0;
                continue;
            }

            switch (choice)
            {
            case 1:
                system("clear");
                DisplayGradeSheet(students, studentCount);
                char choice;
                do
                {
                    printf("Press 'C' or 'c' to display the menu again: ");
                    scanf(" %c", &choice);

                    // If input is not 'C' or 'c', print an error message
                    if (choice != 'C' && choice != 'c')
                    {
                        printf("Invalid input! Please enter 'C' or 'c'.\n");
                    }
                } while (choice != 'C' && choice != 'c');
                break;

            case 2:
                system("clear");
                histogram(students, studentCount);
                char choice2;
                do
                {
                    printf("\nPress 'C' or 'c' to display the menu again: ");
                    scanf(" %c", &choice2);

                    // If input is not 'C' or 'c', print an error message
                    if (choice2 != 'C' && choice2 != 'c')
                    {
                        printf("Invalid input! Please enter 'C' or 'c'.\n");
                    }
                } while (choice2 != 'C' && choice2 != 'c');
                break;
            case 3:
                SetSortColumnChoice();
                DisplayGradeSheet(students, studentCount);
                char choice7;
                do
                {
                    printf("Press 'C' or 'c' to display the menu again: ");
                    scanf(" %c", &choice7);

                    // If input is not 'C' or 'c', print an error message
                    if (choice7 != 'C' && choice7 != 'c')
                    {
                        printf("Invalid input! Please enter 'C' or 'c'.\n");
                    }
                } while (choice7 != 'C' && choice7 != 'c');
                break;
            case 4:
                system("clear");
                DisplayGradeSheet(students, studentCount);
                ChangeStudentID(students, studentCount);
                char choice3;
                do
                {
                    printf("\nPress 'C' or 'c' to display the menu again: ");
                    scanf(" %c", &choice3);

                    // If input is not 'C' or 'c', print an error message
                    if (choice3 != 'C' && choice3 != 'c')
                    {
                        printf("Invalid input! Please enter 'C' or 'c'.\n");
                    }
                } while (choice3 != 'C' && choice3 != 'c');
                break;
            case 5:
                system("clear");
                DisplayGradeSheet(students, studentCount);
                ChangeStudentExamGrade(students, studentCount);
                char choice4;
                do
                {
                    printf("\nPress 'C' or 'c' to display the menu again: ");
                    scanf(" %c", &choice4);

                    // If input is not 'C' or 'c', print an error message
                    if (choice4 != 'C' && choice4 != 'c')
                    {
                        printf("Invalid input! Please enter 'C' or 'c'.\n");
                    }
                } while (choice4 != 'C' && choice4 != 'c');
                break;
            case 6:
                system("clear");
                DisplayGradeSheet(students, studentCount);
                UpdateGradeMapping(students, studentCount);
                char choice10;
                do
                {
                    printf("\nPress 'C' or 'c' to display the menu again: ");
                    scanf(" %c", &choice10);

                    // If input is not 'C' or 'c', print an error message
                    if (choice10 != 'C' && choice10 != 'c')
                    {
                        printf("Invalid input! Please enter 'C' or 'c'.\n");
                    }
                } while (choice10 != 'C' && choice10 != 'c');
                break;
            case 7:
                system("clear");
                DisplayGradeSheet(students, studentCount);
                removeStudent(students, &studentCount);
                char choice5;
                do
                {
                    printf("\nPress 'C' or 'c' to display the menu again: ");
                    scanf(" %c", &choice5);

                    // If input is not 'C' or 'c', print an error message
                    if (choice5 != 'C' && choice5 != 'c')
                    {
                        printf("Invalid input! Please enter 'C' or 'c'.\n");
                    }
                } while (choice5 != 'C' && choice5 != 'c');
                break;
            case 8:
                system("clear");
                printf("Exiting program goodbye and thank you for using the program!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
            }
        }

        // Free the memory
        free(students);
    }
    else
    {
        printf("No students were loaded.\n");
    }

    return 0;
}