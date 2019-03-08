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
   // FILE *fd;
    if(argc < 2){
        printf("File name error!\n");
        exit(-1);
    }


    file_name = argv[1];

    fd = open(file_name, O_RDONLY);
    if ( (fd = open(file_name, O_RDONLY)) == -1) {
    perror("Error");                                                          
    return 1;
}
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
  // how does it work ? first of all , using read function , we are going to read 128 
    // byte each time , till it finishes 
    // each 128 byte may contain several line , like in our test.txt file 
    // so we should go to each 128 , character by character and check how many \n it contains
    // count of \n determines the count of lines 
    // each character we read , we add to our backup buffer called buffer2 
    // whenever we see a \n , we know that the line has finished , and we should see how many 
    // characters we have passed , and it means our length of our line 

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
     printf("Length of longest line is %d and shortest line %d\n" , maxLength , shortestLength );
     // write to the counter.log
    // for appending to a file , we have to pass "a" argument to fopen 
    // fprintf prints a line to a file 

         FILE *counterFile= fopen("counter.log", "a");
    if(fd == 0){
        // file not found !
        fprintf(counterFile,"-1\n"); 

    } else {
          
        // what it does ? time(NULL) returns a structure called time_t 
        // the struct contains current date time
        // using ctime function , we can convert this struct to a string format 
        // and the whole thing to file using prinft
        time_t current_time;
        current_time = time(NULL);
        char* c_time_string;
        c_time_string = ctime(&current_time);
        c_time_string[strlen(c_time_string)-1] = 0;
        fprintf(counterFile, "%s Line count :%d ,Max line length :%d, Shortest line length :%d\n", c_time_string ,lineCounter+1,maxLength , shortestLength);

    }
        return 0;
}