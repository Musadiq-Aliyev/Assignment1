#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  int i;
  //printf("%s", getcwd(0,0));
  for (i = 0; i < argc; i++)
  {
     printf("%s ", argv[i]);
  }
  return 0;
}
