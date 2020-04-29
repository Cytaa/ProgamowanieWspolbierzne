#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>





int main(int argc, char *argv[]) {
	
    int file1, file2, rd, wr;

    char buf[512];

    if(argc < 2) return(0);

    file1 = open(argv[1], O_RDONLY);
    file2 = open(argv[2],O_WRONLY);

    if(file1 < 0){
        perror("open");
        exit(0);
    }

    do{
        rd = read(file1, buf, 512);
        wr = write(file2, buf, rd);
        printf("%s", buf);

    }while(rd == 512);

    close(file1);
    close(file2);


 	return 0;
}
