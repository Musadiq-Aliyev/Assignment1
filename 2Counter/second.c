#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>

int main(int  argc, char *argv[])
{
    int fd;
    char *file_name;
    
    if(argc < 2){
        printf("File name error!\n");
        exit(-1);
    }

    file_name = argv[1];
    fd = open(file_name, O_RDONLY);

    char buffer[128];
    char buffer2[1000];
    
    int buffer2Index = 0 ;

    int readedChar = 0 ;
    int prevStart = 0 ;
    char maxLine [1000];
    int maxLength = 0;
    int shortestLength = 0;
    int lineLength = 0;  
    int lineCounter = 0;  


       while((readedChar= read(fd, buffer, 128))> 0){
        
        // search for \n

        for(int i = 0 ; i < readedChar ; i++){
            char c;
            c = buffer[i];

            if(c!='\n'){
                buffer2[buffer2Index] = c ;
                buffer2Index ++;
            } else {
                lineCounter ++;
                if(buffer2Index > maxLength){
                    buffer2[buffer2Index+1] = 0 ;
                    maxLength = buffer2Index;
                    strcpy(maxLine ,buffer2);
                    
                } else if ((buffer2Index < shortestLength) || (shortestLength == 0)){
                    shortestLength = buffer2Index ;
                }
                buffer2Index = 0;
            }
        }
    }

     printf("Line count : %d\n" , lineCounter+1);

        return 0;
}