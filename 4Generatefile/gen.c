
#include <unistd.h>		/*  for lseek */
#include <stdio.h>		/* for printf */
#include <fcntl.h>		/* for open */

int main(int ac, char *av[])
{
  if ( ac < 2 ) return 0;

  int fd = open(av[1],O_RDONLY); /* 1 syscall */

  int size = lseek(fd, 0, SEEK_END); /* 2 syscalls */

  printf("%d\n", size);

  close(fd);			/* 3 syscalls */
  
  return 0;
}