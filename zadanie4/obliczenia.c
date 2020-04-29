#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>



struct {
 int pocz;// początek przedzialu
 int kon; // koniec przedzialu
 int ile; // Ile liczb w przedziale
} wynik;

bool isPrime(int n)
{
	
  	for(int i = 2; i * i <= n; i++)
	{
    		if(n % i == 0) return false ;
 	}
 	return true;
}

int main(int argc, char *argv[])
{
	int file, primary, start, end, counter=0;
	start = atoi(argv[2]);
	end = atoi(argv[3]);
	for(int i = start; i <= end; i++)
	{
		if(isPrime(i))
		{
			counter++;
		}
	}

	wynik.pocz = start;
	wynik.kon = end;
	wynik.ile = counter;

	file = open("wynik.bin", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (file < 0){
		perror("Blad otwarcia");
		exit(0);
	}

	int res = lockf(file, F_LOCK, 0);
	write(file, &wynik, sizeof(wynik));
	res = lockf(file, F_ULOCK, 0);
	close(file);

	printf("Proces %d - %d liczb pierwszych\n", atoi(argv[1]), counter);
	
	return counter;


}