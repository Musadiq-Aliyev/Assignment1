#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

int fdinfo(int fd){

    if(fd == -1){
         printf("Error openning file\n");
       
    }
    //Macro: int F_GETFL
    //This macro is used as the command argument to fcntl,
    //to read the file status flags for the open file with descriptor filedes.

    // the function fcntl is a multi functional procedure
    // if we send a file descriptor and F_GETFL , we can get file flags

    int flags = fcntl(fd , F_GETFL);
    printf("FD: %u\n", fd);

    if ((flags & O_ACCMODE) == O_RDONLY) {
        printf("O_RDONLY\n");
    }
    if ((flags & O_ACCMODE) == O_WRONLY) {
        printf("O_WRONLY\n");
    }
    if ((flags & O_ACCMODE) == O_RDWR) {
        printf("O_RDWR\n");
    }
    // printf("\n");
    if (flags & O_DIRECTORY) {
        printf("O_DIRECTORY\n");
    }
    if (flags & O_CREAT) {
        printf("O_CREAT\n");
    }
    if (flags & O_EXCL) {
        printf("O_EXCL\n");
    }

   
    printf("F_GETFL: %u\n", flags);
    return 1;
}

