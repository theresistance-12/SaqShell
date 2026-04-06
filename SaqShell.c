#include <stdio.h> //my philosophie is: Keep it readable, Stupid. So that means we Explain Every Line here and we dont make it complicated.
#include <string.h>
int main () {
    char input[4096];
    printf ("Welcome to SaqShell! for any questions, type help. Other Versions will release on my Github page.\n");
    while (1) {
        printf ("SaqShell>>> ");

        fgets (input, sizeof(input), stdin);

        input [strcspn(input, "\n")] = 0;

        if (strcmp(input, "help")== 0) {

            printf ("All commands: sudo, ls, exit\n");

        } else if (strcmp(input, "sudo")== 0) {
            printf ("You are the SuperUser!\n");
        } else if (strcmp(input, "ls")== 0) {
            printf ("/SaqShell\n");
        } else if (strcmp(input, "exit")== 0) {
            printf ("Exitting....\n");
            break;
        } else {
            printf ("Unknown Command Type help\n");
        }
    } 
return 0;
}
