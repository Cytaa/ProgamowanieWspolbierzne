#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

struct {
 int pocz;// początek przedzialu
 int kon; // koniec przedzialu
 int ile; // Ile liczb w przedziale
} wynik;


int main(int argc, char const *argv[])
{
    if(argc < 4) {
        printf("Podano zbyt mala liczbe argumentow, wywoalnie programu musi zawierac: dolna granice przedzialu, gorna granice przedzialu oraz liczbe procesow\n");
        return 0;
    }

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int div = atoi(argv[3]);
    time_t countTime;

    int partition = (end - start) / div;

    char buff1[10], buff2[10], buff3[10];

    int file = open("wynik.bin", O_RDWR | O_CREAT | O_TRUNC, 0666);

    if (file < 0){
        perror("blad otwarcia");
        exit(0);
    }
    

    countTime = time(NULL);


    for(int i = 0; i < div; i++){
        int last;

        if(fork() == 0){
            sprintf(buff1, "%d", i + 1);
            sprintf(buff2, "%d", i * partition + start);
            
            last  = (i + 1) * partition + start;

            if(last > end) last = end;

            sprintf(buff3, "%d", last);

            execl("./obliczenia", "obliczenia", buff1, buff2, buff3, NULL);
        
            

            exit(i + 1);
   

        }

    }


    int status;

    for (int i = 0; i < div; i++){
        int pid = wait(&status);
        printf("Proces %d zakończony status: %d\n", pid, status);
    }

    int sum = 0;

    for (int i = 0; i < div; i++){
        read(file, &wynik, sizeof(wynik));
        sum += wynik.ile;

    }

    printf("Czas obliczen: %ld sekund \n", time(NULL) - countTime);
    printf("Wynik obliczen: %d \n", sum);
    close(file);
    return 0;

}
