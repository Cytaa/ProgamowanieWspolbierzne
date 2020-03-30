#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void main(int argc, char **argv){

    int pid, status;
    int args[argc - 1];

    for(int i = 1; i < argc; i++){
        args[i - 1] = atoi(argv[i]);
    }
    
    for(int i = 0; i < argc - 2; i++){//jak wiele procesow chce utworzyc
        if((pid = fork()) == 0){
            char str[12];
            sprintf(str, "%d", getpid());

            execl("./potEx", "potEx", str, argv[i + 2], (char*) NULL);
            

        }        
   
    }

    for(int i = 0; i < atoi(argv[1]); i++){
            printf("Macierzysty krok %d\n",i);
            sleep(1);
    }    

    for(int i = 0; i < argc - 2; i++){
        
        pid = wait(&status);
        
        printf("Proces %d zostal zakonczony, status  %d \n", pid, WEXITSTATUS(status));           
         
    }


}