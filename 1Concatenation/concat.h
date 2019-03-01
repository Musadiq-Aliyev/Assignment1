

#include <stdio.h>
#include <string.h>

char concat(int argc, const char * argv[])
{
   /* Define a temporary variable */
   char example[1000];
   int i;
   /* Copy the first string into the variable */
 
  for (i = 0; i < argc; i++)
  {
     //printf("%s ", argv[i]);
  	strcat(example,argv[i]);
  }
   /* Concatenate the following two strings to the end of the first one */
 
   /* Display the concatenated strings */
   printf("%s\n", example);
   //printf("%s\n ", argv[i]);
   return 0;
}
