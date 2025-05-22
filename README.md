# C-Based-Grade-Spreadsheet-Application
This project is a terminal-based grade spreadsheet application written in C, developed as part of COMP 348 (Principles of Programming Languages) at Concordia University.

🧩 Features
	•	Reads student grade data from a file (students.txt)
	•	Displays a formatted spreadsheet with dynamically calculated:
	•	Total grades
	•	Letter grades (A–F)
	•	Offers a full interactive menu to:
	1.	View the spreadsheet
	2.	Display grade histogram
	3.	Sort by student ID, last name, exam, or total grade
	4.	Update student last names
	5.	Update student exam grades
	6.	Change grade mappings (e.g., modify A/B/C/D/F cutoffs)
	7.	Remove students
	8.	Exit the application
	•	Handles data parsing and in-memory manipulation using dynamic structures
	•	Utilizes modular programming with multiple .c and .h files

🔧 Tech Stack
	•	Language: C
	•	Compilation: GCC
	•	Tools: Docker-based Linux command line for testing
	•	Libraries: stdio.h, stdlib.h, string.h, ctype.h
	•	Memory management: Manual with malloc and free

💡 Skills Demonstrated
	•	Pointer manipulation and dynamic memory management
	•	File I/O in C
	•	Sorting using qsort()
	•	String tokenization with strtok()
	•	Struct-based data modeling
	•	Modular code organization using header files
	•	Terminal UI design (clear screen, scanf buffering, etc.)

 📝 Notes
	•	No external GUI or libraries were used—entirely text-based.
	•	Designed for robustness and clarity, with memory safety in mind.
	•	This assignment provided critical hands-on experience with C, memory management, and low-level system interaction.

🏁 How to Run

Make sure you’re using a Unix-like environment (e.g., Docker container or Linux VM):
gcc -Wall -g -gdwarf-4 spreadsheet.c data.c ordering.c calc.c -o spreadsheet
./spreadsheet
