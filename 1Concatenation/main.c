#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <stdlib.h>

#include <stdarg.h>

#include "concat.h"

#define SIZE 100



int main(){
    char * temp = concat("%d %s" , 12, "Hello");
    printf("%s\n" ,temp);

}