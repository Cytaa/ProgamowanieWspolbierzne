#include <stdlib.h>
#include <sys/resource.h>
#include <stdio.h>



int main(int argc, char *argv[]) {
    int res, i, num = 0;
    struct rlimit rl;
    printf(" CUR MAX \n");
    getrlimit(RLIMIT_CPU,&rl);
    printf("CPU %ld %ld \n",rl.rlim_cur, rl.rlim_max);
    getrlimit(RLIMIT_CORE,&rl);
    printf("CORE %ld %ld \n",rl.rlim_cur, rl.rlim_max);
    rl.rlim_cur = 2;
    setrlimit(RLIMIT_CPU,&rl);
    while (1);
    return 0;
} 