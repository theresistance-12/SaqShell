/* Great, now in this version, we work with ptrs for the first time. lets hope it aint brain brakin*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char notepad_ram[100000]; /*so in the last version it was that fgets copies user input directly here, but that aint the case here, you will see*/
void call_notepad () { //headache starts here :P
	char notepad_bufferin[8192]; //now thats what fgets copies the user input first into
	char savmenu_choice [100];
	char filename[1000];
	printf ("Welcome to SaqNotepadV3!, type ::QUIT:: . In this version of SaqNotepad, you will see the save menu, be aware that the example.txt file will be saved inside the same folder the SaqShell executable is living.\n");
	bool loop = true;
	while (loop) {
		printf ("> "); //thats what the user sees
		fgets (notepad_bufferin, sizeof(notepad_bufferin), stdin);
		if (strcmp(notepad_bufferin, "::QUIT::\n")== 0) {
			break;
		}
		strcat (notepad_ram, notepad_bufferin);
	}
	printf ("Save menu\n\n");
	printf ("Do you wanna save the file? y/n> ");
	fgets (savmenu_choice, sizeof(savmenu_choice), stdin);
	if (strcmp(savmenu_choice, "y\n")== 0) {
		printf ("Enter file name (with . Extention)> ");
		fgets (filename, sizeof(filename), stdin);
		filename[strcspn(filename, "\n")] = 0; //user enters file name, and then strcspn removes the user entered newline
		FILE *file_ptr = fopen(filename, "w"); /*FILE creates a ptr, that manages saving and making files in real os filesystems, then fopen, makes a new file of the name that the user typed in (fgets puts the filename inside of char variable 'filename') then the "w" tells file_ptr to make a new file if the file doesnt exist (which it will make a file 100%)*/
		if (file_ptr != NULL) { /*if the os allows file_ptr to make a new file (os will return non-zero to file_ptr, then if file_ptr isnt the same as NULL, the code inside of if will execute (in our case fprintf writing taking all the user input data from ram_notepad, and putting it inside of file_ptr and then file_ptr will put inside the data inside of example.txt, then fclose saves the file and stops the writing.*/
			fprintf (file_ptr, "%s", notepad_ram); /*fprintf gives file_ptr the direction to example.txt, and fclose tells file_ptr to go to the address of example.txt and delivers notepad_ram data off at example.txt's address*/
			fclose (file_ptr); //actually writes the data from notepad_ram into example.txt
			printf ("File '%s' has been saved in current saqshell executable folder successfully!\n", filename);
		} else {
			printf ("The os has restricted file_ptr to save the file :( returning to SaqShell... ERRCOD: KERNEL_RESTRICTION_FS\n");
		}
	}
	else if (strcmp(savmenu_choice, "n\n")== 0) {
		printf ("Saving aborted, Returning to SaqShell...\n");
	} else {
		printf ("Illegal instruction to SaqNotepad :( non-y/n are not allowed, returning back to SaqShell without saving...\n");
	}
}
// WE SUCCESSFULLY WROTE NOTEPAD WITH REAL FILE SAVING YAYY, now all thats left is the calculator, and the int main if else logic
void call_calc () {
	printf ("Welcome to SaqCalc! type exit to leave the calculator.\n");
	char calc_ram[1024];
	double num1, num2;
	char op;
	bool loop = true;
	while (loop) {
		printf ("> ");
		fgets (calc_ram, sizeof(calc_ram), stdin);
		if (strcmp(calc_ram, "exit\n")== 0) {
			printf ("Exitting to SaqShell...\n");
			break;
		}
		int items_found = sscanf (calc_ram, "%lf %c %lf", &num1, &op, &num2);
		if (items_found = 3) {
			if (op == '+') {
				printf ("Result: %g\n", num1 + num2);
			}
			else if (op == '-') {
				printf ("Result: %g\n", num1 - num2);
			}
			else if (op == '*') {
				printf ("Result: %g\n", num1 * num2);
			}
			else if (op == '/') {
				if (num2 == 0) {
					printf ("Divide by NULL Err!\n");
				} else {
					printf ("Result: %g\n", num1 / num2);
				}
			} else {
				printf ("Illegal Operrator!\n");
			}
		} else {
			printf ("Illegal Instruction to SaqCalc!\n");
		}
	}
}
int main () {
	char shell_input[8086];
	printf ("Welcome to SaqShellV3! type 'help' for all the commands and new features.\n");
	bool loop = true;
	while (loop) {
		printf ("SaqShell>>> ");
		fgets (shell_input, sizeof(shell_input), stdin);
		if (strcmp(shell_input, "help\n")== 0) {
			printf ("All Avaialbe Commands: exit, sudo, cd, calc, ls, notepad\n");
			printf ("New Feature added to SaqShell!: In V3, you can save your text files in Notepad!!\n");
			printf ("(Be Aware that sudo, cd, ls dont do anything, it may be included in version 4)\n");
		}
		else if (strcmp(shell_input, "exit\n")== 0) {
			printf ("Exitting SaqShell...\n");
			break;
		}
		else if (strcmp(shell_input, "sudo\n")== 0) {
			printf ("You are the Super user!\n");
		}
		else if (strcmp(shell_input, "cd\n")== 0) {
			printf ("Change dir: (wont work in this version)\n");
		}
		else if (strcmp(shell_input, "ls\n")== 0) {
			printf ("Current dir: /saqShell\n");
		}
		else if (strcmp(shell_input, "calc\n")== 0) {
			call_calc ();
		}
		else if (strcmp(shell_input, "notepad\n")== 0) {
			call_notepad ();
		} else {
			printf ("Unknown Command!\n");
		}

	}
	return 0;
}   
	
	
