#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> // wir werden unix std benutzen für funcs so wie chdir, getcwd, usw
#include <stdlib.h>
#include <dirent.h> // brauchen wir für struct dirent
char datantpd[10000000]; //hat notepad user data
void call_ntpd () {
    printf ("Welcome to SaqShell's Notepad! Type ::EXIT:: to quit, ::SAVE:: to save. Keep in mind to use save ONCE and then exit. else your data will be overwritten. If you save and then exit SaqNtpd, use ::EDIT:: to continue your editing.\n\n\n"); //welcome msg
    char filename[2000]; //speichert der datei name
    char choice[1000]; // es speichert das y/n auswahl
    char tempbuffer[10000]; // es speichert das benutzer input temporär
    bool loop = true;
    while (loop) {
        printf ("> ");
        fgets (tempbuffer, sizeof(tempbuffer), stdin);
        strcat (datantpd, tempbuffer); //es kopiert dateien von tempbuffer ins datantpd
        if (strcmp (tempbuffer, "::EXIT::") == 0) {
            printf ("Save File? y/n > ");
            fgets (choice, sizeof(choice), stdin);
            if (strcmp (choice, "y\n") == 0) {
                printf ("Type Filename with extenstion> ");
                fgets (filename, sizeof(filename), stdin);
                filename [strcspn (filename, "\n")] = 0;
                FILE *ptr = fopen (filename, "w"); /*macht einen ptr names ptr, fopen gibt die addresse von den datei das fopen gemacht hat zu ptr*/
                if (ptr == 0) {
                    printf ("ERR KERNEL RESTRICTED FILEMAKING!\n");/*wenn kernel fopen nicht einen datei machen lässt, gibt*/
                }
                fprintf (ptr, "%s", datantpd); /*fprintf gibt die daten von datantpd zu ptr, dann geht ptr zur datei addresse und gibt die daten ein*/
                fclose (ptr); /*schleisst den pointer 'ptr'*/
                printf ("File %s has been saved Successfully! Exitting to SaqShell...\n", filename);
                break;
                
            }
            else if (strcmp (choice, "n\n")== 0) {
                printf ("Exitting to SaqShell Without saving...\n");
                break;
            } else {
                printf ("Invalid choice, choose 'y' or 'n'\n"); //it could sometimes happen that the user accedently misstypes, you never know
            }
        }
        else if (strcmp (tempbuffer, "::SAVE::")== 0) {
            while (1) {
            printf ("Save menu\n\n\n");
            printf ("Type the Filename with exstention> ");
            fgets (filename, sizeof(filename), stdin);
            filename [strcspn (filename, "\n")] = 0;
            FILE *ptr2 = fopen (filename, "w");
            if (ptr2 == 0) {
                printf ("ERR KERNEL RESTIRCTED TO MAKE NEW FILE!\n");
            }
            fprintf (ptr2, "%s", datantpd);
            fclose (ptr2);
            printf ("File %s Saved Successfully! If you want to edit, type ::EDIT::. DONT SAVE AGAIN, ELSE YOUR DATA WILL BE OVERWRITTEN! You have been warned.\n", filename);//grosser warnung
            break;
            }
        }
        else if (strcmp (tempbuffer, "::EDIT::")== 0) { //ich versuche ein 'edit' menü zu machen mit der append funktion wenn mann fopen benutzt
            while (1) {
            
                printf ("Edit Menu, to save changes type ::SAVE:: or type ::QUIT:: \n\n\n");
                printf ("which file do you wanna edit> ");
                fgets (filename, sizeof(filename), stdin);
                filename [strcspn(filename, "\n")] = 0;
                FILE *ptr3 = fopen (filename, "a");
                if (ptr3 == 0) {
                printf ("ERR KERNEL RESTRICTED TO MAKE EDITS TO FILE %s\n", filename);
                }
                printf ("Edit> ");
                fgets (tempbuffer, sizeof(tempbuffer), stdin);
                strcat (datantpd, tempbuffer);
                if (strcmp (tempbuffer, "::EXIT::")== 0) {
                    printf ("Exitting to SaqShell...\n");
                    break; 
                }
                else if (strcmp (tempbuffer, "::SAVE::")== 0) {
                    printf ("Saving file...\n");
                    fprintf (ptr3, "%s", datantpd);
                    fclose (ptr3);
                    printf ("Editing file %s was successfull exitting to SaqShell...\n", filename);
                    break;

                }
            }
        }
    }
}
void call_calc () {
    double num1, num2;
    char op;
    char calcbuffer[512];
    int itemsfound;
    printf ("Welcome to SaqCalc! Type exit to quit the calc to SaqShell\n\n\n");
    while (1) {
        printf ("> ");
        fgets (calcbuffer, sizeof(calcbuffer), stdin);
        if (strcmp (calcbuffer, "exit\n")== 0) {
            printf ("Exitting to SaqShell...\n");
            break;
        }
        itemsfound = sscanf (calcbuffer, "%lf %c %lf", &num1, &op, &num2);
        if (itemsfound == 3) {
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
                    printf ("Illegal Instruction\n");
                } else {
                    printf ("Result: %g\n", num1 / num2);
                }
            }
        } else {
            printf ("Invalid Equation!\n");
        }
    }


}
void call_todo () { //neuer todo list app, kann einbisschen  kompliziert werden
    char userinput[10000];
    char temp[8000];
    printf ("Welcome to The New App added to SaqShell! ToDoList! to exit, type :::EXIT:::, to go to standby type :::SLEEP:::, in standby mode, you can save your todo list on your harddisk.\n");
    while (1) {
        printf ("> ");
        fgets (temp, sizeof(temp), stdin);
        temp [strcspn(temp, "\n")] = 0;
        strcat (userinput, temp);
        if (strcmp (temp, ":::EXIT:::")== 0) {
            printf ("Quitting to SaqShell...\n");
            break;
        }
        else if (strcmp(temp, ":::SLEEP:::")== 0) {
            printf ("Standby mode, Type ::exit:: to leave standby mode and go back to editing, Type ::save:: to save your todo list on harddisk.\n");
            char inputusr[10000];
            char filename2[1000];
            while(1){
                printf ("> ");
                fgets (inputusr, sizeof(inputusr), stdin);
                if (strcmp (inputusr, "::exit::\n")== 0) {
                    printf ("Exitting standby mode...\n");
                    break;
                }
                else if (strcmp (inputusr, "::save::\n")== 0) {
                    printf ("Save menu\n\n\n");
                    printf ("Type in filename with .exstetion> ");
                    fgets (filename2, sizeof(filename2), stdin);
                    filename2 [strcspn(filename2, "\n")] = 0;
                    FILE *ptr4 = fopen (filename2, "w"); //uses the same logic as the other ptr apps, nothing to explain here tbh
                    if (ptr4 == 0) {
                        printf ("ERR KERNEL DIDNT ALLOW MAKING FILE! Exiting to edit mode...\n");
                        break;
                    }
                    fprintf (ptr4, "%s", userinput);
                    fclose (ptr4);
                    printf ("file %s has been saved successfully, leaving to todo list mode...\n", filename2);
                } else {
                    printf ("unknown command, type ::save::, to save your current ToDo list, type ::exit:: to leave StandBy mode.\n");
                }
            }
        }
    }

}
int main () {
    printf ("Welcome to SaqShellV4! for all commands, type 'help'.\n");
    char shell_input[8096];
    char path_out[8096];
    char chdirtar[8096];
    char echo[8096];
    bool fish = true;
    while (fish) {
        printf ("SaqShell>>> ");
        if (fgets (shell_input, sizeof(shell_input), stdin)== 0) {
            break;
        }
        else if (strcmp(shell_input, "help\n")== 0) {
            printf ("All commands: chdir, currentpath, echo, ls, exit, calc, notepad, todo.\n");
            printf ("how to use echo: type echo ONLY and then contunie with the programm.\n");
        }
        else if (strcmp(shell_input, "echo\n")== 0) { //neuer command namens echo, gibt einfach daten in echo mit printf aus
            printf ("What do you wanna echo>>> ");
            fgets (echo, sizeof(echo), stdin);
            echo [strcspn(echo, "\n")] = 0;
            printf ("You typed: %s\n", echo);
        }
        else if (strcmp(shell_input, "exit\n")== 0) {
            printf ("exitting to OS...\n");
            break;
        }
        else if (strcmp (shell_input, "calc\n")== 0) {
            call_calc ();
        }
        else if (strcmp(shell_input, "notepad\n")== 0) {
            call_ntpd ();
        }
        else if (strcmp(shell_input, "todo\n")== 0) {
            call_todo ();
        }
        else if (strcmp(shell_input, "chdir\n")== 0) {
            printf ("Change Dir to>>> ");
            fgets (chdirtar, sizeof(chdirtar), stdin);
            chdirtar [strcspn(chdirtar, "\n")] = 0;
            chdir (chdirtar);
            getcwd (path_out, sizeof(path_out));
            printf ("Path changed to %s\n", path_out);
            if (chdir(chdirtar)!= 0) {
                printf ("ERR KERNEL DIDNT ALLOW DIR CHANGING!\n");
            }
        }
        else if (strcmp (shell_input, "currentpath\n")== 0) {
            getcwd (path_out, sizeof(path_out));
            printf ("your current path: %s\n", path_out);
        }
        else if (strcmp(shell_input, "ls\n")== 0) { //thats kinda the complicated part in main
            DIR *ptr5 = opendir ("."); //opendir gibt das ordner addresse zu ptr5
            if (ptr5 == 0) {
                printf ("ERR KERNEL DIDNT ALLOW LS!\n");
            }
            struct dirent *entptr;
            while ((entptr = readdir(ptr5)) != 0) { /*readdir schaut in ptr5, dann gibt readdir die daten an entptr weiter bis es keine daten mehr in ptr5 findet. nachdem es auch keine daten mehr findet, ended der while loop*/
                printf (" %s\n", entptr->d_name); /*entryptr geht zur addresse von dirent (in der struct) und dann geht es zur addresse von d_name, */
            }
            closedir (ptr5); //schliest den ordner ptr5
        } else {
            printf ("Unknown command!, Type 'help' for all commands.\n");
        }
    }
    return 0;
}
