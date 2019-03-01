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
    int val;
    char *file_name;
    off_t size;
    mode_t mode;

    if (argc < 2)
    {
        perror("Not enough arguments");
       
    }

    //file_name = argv[1];
    //size = atoi(argv[2]);
    //mode = S_IWUSR | S_IWGRP | S_IWOTH;
    //s=fcntl(fd,F_GETFl)
    //fd = creat(file_name, mode);
    //s=fcntl(fd,F_GETFL);
    val = fcntl(atoi(argv[1]), F_GETFL, 0);
    //lseek(fd, size, SEEK_SET); 
    //write(fd, "", 1); 

           switch (val & O_ACCMODE) {
           case O_RDONLY:
               printf("read only");
               break;
           case O_WRONLY:
               printf("write only");
               break;
           case O_RDWR:
               printf("read write");
               break;
          // default:
             //  err_dump("unknown access mode");
}
  //  printf("%d\n", fd);
   // printf("%d\n", val);
    //close(fd);
   
    return 0;
}