/* now, here i can make the notepad and calculator code outside of int, and then just call it in inside of int inside of an if statement. but if i wanna make it more messy, i could all put it into an int. i wont do that*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char notepad_data[100000] = ""; //first, what ever the user types, goes into ram_notepad, then strcat copies from ram_notepad into notepad_data
void call_notepad () { // here i made an void function named call_notepad so we could call it in our int code anytime
    char ram_notepad[512]; //whatever the user types, goes first into ram_notepad UPDATE: lol, for some reason the boolean variable 'loop' is undcleared and no while loop wanna run, i guess ill replace it with a 1
    bool loop = true; // we make an extra boolean value to start our while loop because i feel like it lol
    printf ("Welcome to SaqShell's SaqNotepad!, this is a new feature in SaqShell V2. To quit to SaqShell, type: ::QUIT:: and strike enter\n");
    printf ("Already stored notepad data from before: %s\n", notepad_data);
    while (1) { // start loop here
        printf ("> "); //the user now type and even code in c :)
        fgets (ram_notepad, sizeof(ram_notepad), stdin);
        if (strcmp(ram_notepad, "::QUIT::\n") == 0) { /*strcmp compares ram_notepad with "::QUIT::\n", it should be a 0 (a match) and then if compares the 0 from strcmp with a normal == 0*/
            printf ("Quitting SaqNotepad...\n");
            break;
        }
        strcat(notepad_data, ram_notepad); /*copys the content of ram_notepad into notepad_data. to be honest, i shouldnt have made a copying method, because i just can directly put the user input into notepad_data.*/
        
    }
}
// i make another function outside of int main for readbility :)
void call_calc () { // here i made another function called call_calc (), same reason as call_notepad. (line 6)
    char calc_ram[4096]; //holds 512 bytes just incase user spams, the 'ram_calc variable' is used for users 'exit' and equations ofc
    printf ("Welcome to SaqShell's Calculator! to quit, simply type quit, to go back to SaqShell.\n "); //welcome msg
    printf ("How to use: (first num) (Operator) (second num) then strike enter. Example: 10 + 10(strike enter!)\n");
    while (1) { // we reuse boolean value from the call_notepad func
        printf ("Calc>>> "); //thats what the user sees
        fgets (calc_ram, sizeof(calc_ram), stdin);/*scan if user types exit or a equation if he types anything of those two things (or the user could type gibberisch too but it will directly go to else statement) it will go to sscanf, then sscanf checks for nummbers and opperators*/ 
        if (strcmp(calc_ram, "quit\n")== 0){ //the logic if user does type exit
            printf ("Exiting to SaqShell...\n");
            break; 
        }   //lol the bug here was, i didnt put the break inside of if **FIXED**
        double num1, num2; //the first number (op = operrator) the second nummber
        char op; //this is where we store users, +, -, /, *
        int items_found = sscanf (calc_ram, "%lf %c %lf", &num1, &op, &num2); //this part is kinda tricky, sscanf looks into calc_ram, the format speciiers inside of the " " tells scanf what to find, and then if it found the following things: %lf, %c, %lf, it drops off at the address of num1, op, num2. then we can use the if else logic 
        if (items_found == 3) { //This will execute GUARANTEED!!!!!!!!!!!!! if user types something very ramdom, our programm will say 
            if (op == '+') { //i think i dont need to explain the logic here, self explanatory
                printf ("result: %g\n", num1 + num2);
            }
            else if (op == '-') {
                printf ("result: %g\n", num1 - num2);
            }
            else if (op == '*') {
                printf ("result: %g\n", num1 * num2);
            }
            else if (op == '/') {
                if (num2 != 0) { //if num2 isnt a 0, we can let the cpu do math normally, but if its a 0, the cpu will cry, it cant do a x / 0 equation
                    printf ("result: %g\n", num1 / num2);
                } else {
                    printf ("Illegal instruction\n");
                }
            }
        } else {
            printf ("?? Illegal equation ??, type a real equation, if you wanna exit to SaqShell type: exit\n");
        }
    }
}
        






/*GREATTTT I FINISHED THE HARD PART, it took me DAMM 4 HRS to understand allat and write it*/
    



int main () { // time for the peaceful stuff
    char shell_input[4096]; //shell input variable size standard 4096 bytes
    printf ("Welcome to SaqShell V2! type help for all commands.\n");
    while (1) { //heh, 3rd time we used boolean value "loop"
        printf ("SaqShell>>> ");
        fgets (shell_input, sizeof(shell_input), stdin);
        if (strcmp(shell_input, "help\n")== 0) {
            printf ("All Commands (Update V2): cd, sudo, ls, exit, calc, notepad\n");
        }
        else if (strcmp(shell_input, "cd\n")== 0) {
            printf ("Change dir will come in SaqShell V4 sorry :( Error_code: NOT_AVAILABLE_FEATURE\n");
        }
        else if (strcmp(shell_input, "sudo\n")== 0) {
            printf ("You are the SuperUser! (Super User Do will come in SaqShell V4!)\n");
        }
        else if (strcmp(shell_input, "ls\n")== 0) {
            printf ("You are in current directory: SaqShell/shell (real os directories will be added in SaqShell V4)\n");
        }
        else if (strcmp(shell_input, "calc\n")== 0) {
            call_calc ();
        }
        else if (strcmp(shell_input, "exit\n")== 0) {
            printf ("Exitting SaqShell to OS...\n");
            break;
        }
        else if (strcmp(shell_input, "notepad\n")== 0) {
            call_notepad ();
        } else {
            printf ("Illegal Instruction to SaqShell\n");
        }
    }
    return 0; //now we finnaly finished our programm, time to testing :P
}





/*NOTE: continue at line 78, make a else if logic for other commands to work, you know the drill, enough programming for today, my brain broken :P*/
