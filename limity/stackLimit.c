#include <stdlib.h>
#include <sys/resource.h>
#include <stdio.h>


int stack(){
    int a = 10;
    return a + stack();
}


int main(int argc, char const *argv[])
{
    int res, i, num = 0;
    struct rlimit rl;
    printf(" CUR MAX \n");
    getrlimit(RLIMIT_STACK,&rl);
    printf("STACK %ld %ld \n",rl.rlim_cur, rl.rlim_max);

    rl.rlim_cur = 100000;
    setrlimit(RLIMIT_STACK,&rl);
    printf("STACK %ld %ld \n",rl.rlim_cur, rl.rlim_max);
    stack();
    return 0;
    
}

