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


void fwdstdout(char *path){

  int out = open(path, O_RDWR|O_CREAT|O_APPEND, 0600);

  int save_out = dup(fileno(stdout));


    if (-1 == dup2(out, fileno(stdout))) { perror("cannot redirect stdout"); }





}


int main(){
    fwdstdout("q3out.txt");
    printf("Hello world!\n");
}