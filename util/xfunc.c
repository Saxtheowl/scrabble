#include "../include/my.h"

void		*xmalloc(int size)
{
  void  *ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      printf("malloc error\n");
      exit(0);
    }
  return (ptr);
}
