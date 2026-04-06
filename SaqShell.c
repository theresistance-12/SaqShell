#include <stdio.h> //my philosophie is: Keep it readable, Stupid. So that means we Explain Every Line here and we dont make it complicated.
#include <string.h> //Include string.h so we can use strcmp or strcsnp
int main () {
    char input[4096]; //here i have an char variable named input, it hold 4096 charekters.
    printf ("Welcome to SaqShell! for any questions, type help. Other Versions will release on my Github page.\n"); //welcome msg
    while (1) { //loop starts here
        printf ("SaqShell>>> "); //User Sees SaqShell>>> while we see it as a printed string lol

        fgets (input, sizeof(input), stdin); //scan for user input and store the input in "input"

        input [strcspn(input, "\n")] = 0;/* now this is kinda annoying. this part here, fgets doesnt automaticly remove the enter "\n" so we have to do it using strcspn. it find the \n and turns it into an 0. else strcmp breaks*/

        if (strcmp(input, "help")== 0) { // if input is the same as help, output 0 and then == 0 will compare the 0 from strcmp that equals to: 1, so the if codeblock will execute (unless the user dont type help)

            printf ("All commands: sudo, ls, exit\n"); //prints all commands if help has been typed by user

        } else if (strcmp(input, "sudo")== 0) { // executes this block of code if user typed sudo
            printf ("You are the SuperUser!\n"); //yep this programm doesnt do much it only responds back, dont worry in the next version its going to be actually useful :)
        } else if (strcmp(input, "ls")== 0) { //same concept here as the others etc etc
            printf ("/SaqShell\n");
        } else if (strcmp(input, "exit")== 0) {
            printf ("Exitting....\n"); //im sure user wont even see that message when they type exit but oh well, speed over visbility ;)
            break; //now this one actually interacts with the system: it exits the aplication nothing else lol
        } else {
            printf ("Unknown Command Type help\n"); 
        }
    } 
return 0; //returns 0 to os, self explainatory
}
