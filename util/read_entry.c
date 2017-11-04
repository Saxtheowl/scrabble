#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"


char		*read_entry()
{
  char *buffer = NULL;
  size_t len;
  
  if (getline(&buffer, &len, stdin) == -1)
    printf("getline error\n");
  return(buffer);
}

void		xgetline(char **lineptr, FILE *fp, int i)
{
  char		*line;
  size_t	len;

  len = 0;
  if ((getline(&lineptr[i], &len, fp)) == -1)
    {
      printf("getline error\n");
      exit(0);
    }
}
