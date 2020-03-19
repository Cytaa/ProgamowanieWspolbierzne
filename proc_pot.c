#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const **argv)
{
    for(int i = 0; i < atoi(argv[1]); i++ ){
        printf("Potomny proces %d, krok %d \n", getpid(), i);
        sleep(1);
    }

    exit(getpid());
}
