#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



bool isPrime(int number){
    if(number < 2)return false;

    for(int i = 2; i * i <= number; i++){
        if(number % i == 0)return false;

    }
    return true;
}





int main(int argc, char const *argv[])
{
    //printf("start %s, end %s, pid %s \n", argv[1], argv[2], argv[3]);
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int counter = 0;

    for(int i = start; i <= end; i++){
        if(isPrime(i)){ 
            counter++;
            //printf("%d \n", i);
        }
    }

   //printf("Ilosc liczb pierwszych w przedziale %d - %d wynosi %d \n", start, end , counter);

    exit(counter);
 
}

