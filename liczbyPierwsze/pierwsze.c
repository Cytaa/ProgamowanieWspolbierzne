#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>



int main(int argc, char const *argv[])
{
    int pid,status;
    int start  = atoi(argv[1]);
    int end = atoi(argv[2]);
    int sub = atoi(argv[3]);
    int inter = (end - start) / sub;
    int counter;
    time_t countTime;

    countTime = time(NULL);

    for(int i = 0; i < sub; i++){
        if((pid = fork()) == 0){
            int actualStart = start + i * inter;
            char startStr[10];
            char endStr[10];
            char pid[10];


            sprintf(pid, "%d", getpid());
            sprintf(startStr, "%d", actualStart);
            sprintf(endStr, "%d", actualStart + inter);

            execl("./licz", "licz", startStr, endStr, pid,(char *) NULL);


        }
    }

    for(int i = 0; i < sub; i++){
        pid = wait(&status);
        counter += status;
    }
    
    countTime = time(NULL) - countTime;
    printf("Ilosc liczb pierwszych %d, czas wykonywania %ld", counter/255, countTime);


    return 0;
}
