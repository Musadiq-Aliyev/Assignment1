#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int  argc, char *argv[])
{
    int fd;
    char *file_name;
    off_t size;
    mode_t mode;

    if (argc < 3)
    {
        perror("Not enough arguments");
       
    }

    file_name = argv[1];
    size = atoi(argv[2]);
    mode = S_IWUSR | S_IWGRP | S_IWOTH;

    fd = creat(file_name, mode);
       
    lseek(fd, size, SEEK_SET); 
    write(fd, "", 1); 
    

    //close(fd);
   
    return 0;
}