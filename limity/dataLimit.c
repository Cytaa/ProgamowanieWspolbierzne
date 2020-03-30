#include <stdlib.h>
#include <sys/resource.h>
#include <stdio.h>


void stack(){
    int a = 10;
    stack();
}


int main(int argc, char const *argv[])
{
    int res, i, num = 0;
    struct rlimit rl;
    printf(" CUR MAX \n");
    getrlimit(RLIMIT_DATA,&rl);
    printf("DATA %ld %ld \n",rl.rlim_cur, rl.rlim_max);

    rl.rlim_cur = 1000;
    setrlimit(RLIMIT_DATA,&rl);
    printf("DATA %ld %ld \n",rl.rlim_cur, rl.rlim_max);
    stack();
    return 0;
    
}

