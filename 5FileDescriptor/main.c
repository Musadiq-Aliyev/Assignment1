#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#include "filedesc.h"

int main(int argc, char *argv[]){

  
   // int fd = open("k.txt", O_RDONLY |O_CREAT | O_TRUNC | O_APPEND, 0644);
	int fd = open(argv[1] , O_RDONLY |O_CREAT| O_RDWR, 0644);
    // our fdinfo function returns the file flags
    int flags = fdinfo(fd);

    
}

