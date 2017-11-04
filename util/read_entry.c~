#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"


char		*read_entry()
{
  char *buffer = NULL;
  int read;
  size_t len;
  
  read = getline(&buffer, &len, stdin);
  if (-1 != read)
    puts(buffer);
  else
    printf("No line read...\n");

  printf("Size read: %d\n Len: %d\n", read, len);
  free(buffer);
  return(buffer);
}
