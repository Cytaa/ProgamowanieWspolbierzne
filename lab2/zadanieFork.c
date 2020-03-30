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

            for(int y = 0; y < args[i + 1]; y++){
                printf("Krok %d procesu %d \n", y, getpid());
                sleep(1);
            } 
            exit(getpid());
        }
    }
    
    for(int i = 0; i < args[0]; i++){
            printf("Macierzysty krok %d\n",i);
            sleep(1);
    }

    for(int i = 0; i < argc - 2; i++){    
        pid = wait(&status);
        
        printf("Proces %d zostal zakonczony, status  %d \n", pid, WEXITSTATUS(status));
    }

    exit(0);

}