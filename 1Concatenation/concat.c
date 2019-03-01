

#include <stdio.h>
#include <string.h>
#include "concat.h"



int main(int argc, const char * argv[])
{

	concat(argc, argv);
}
/*

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
  // Define a temporary variable
   char example[1000];
   int i;
    Copy the first string into the variable

  for (i = 0; i < argc; i++)
  {
     //printf("%s ", argv[i]);
  	strcat(example,argv[i]);
  }
    Concatenate the following two strings to the end of the first one
  // strcat(example, "is over 10 ");
  // strcat(example, "years old.");

  Display the concatenated strings
   printf("%s\n", example);
   //printf("%s\n ", argv[i]);
   return 0;
}
*/
