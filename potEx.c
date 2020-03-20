#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    
    for(int i = 0; i < atoi(argv[2]); i++){
        printf("Proces potomny nr. %d, krok nr. %d \n", atoi(argv[1]), i);
        sleep(1);
    }
    exit(0);
}
