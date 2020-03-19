// Ilustracja działania funkcji execl – uruchomienie programu potomny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(void){
    int pid,status;
    if((pid = fork()) == 0) { /* Proces potomny pot ---*/
        execl("./pot","pot",NULL);
    }
 /* Proces macierzysty */
    printf("Macierzysty = %d \n",getpid());
    pid = wait(&status);
    printf("Proces %d zakończony status: %d\n",pid,WEXITSTATUS(status));
} 