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
    // first of all , we should open the file we are given 
    // using the arugments O_RDWR|O_CREAT|O_APPEND we now can , 
    // read or write to it || create it , if it isnt there || append to the file , if it is there!

    //  there are two integer variables , out and err
    // both of them are file descriptors , but what are they ?
    // there are two standard outputs , one of them is for error , another one for outputs like printf
    // but for us , both of them are sended into our terminal , 
    // so we are putting them in file 

    int out = open(path, O_RDWR|O_CREAT|O_APPEND, 0600);

    int err = open(path, O_RDWR|O_CREAT|O_APPEND, 0600);

    // this function gets the address of current standard input , the terminal
    int save_out = dup(fileno(stdout));
    int save_err = dup(fileno(stderr));


    // this function change the two given output with each other 
    // this means it gets the current standard output and pipe it to our desired output
    if (-1 == dup2(out, fileno(stdout))) { perror("cannot redirect stdout"); }
    if (-1 == dup2(err, fileno(stderr))) { perror("cannot redirect stderr"); }


}


int main(){
    fwdstdout("q3out.txt");
    printf("Hello world!\n");
}