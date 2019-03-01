#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <stdlib.h>

#include <stdarg.h>

#define SIZE 100

char * concat (char * format , ...){
    // allocating some size for the answer
    // we are going to return this variable
    char * ans = (char * ) malloc(sizeof(char) * SIZE);

    va_list list; // this is the list of arguments that have been
                  // passed to this function . in our example
                  // 12 and "Hello" are in here

    va_start(list, format);
    vsnprintf(ans, sizeof(char) * SIZE, format, list);
    // vsnprintf function is like sprintf function , it copies the
    // arguemnts in list variable , and put them in the first
    // arguemnt ( in our example , the ans)
    va_end(list);

    return ans ;

}
