
#define _GNU_SOURCE
#include "../include/scrabble.h"

void		*xmalloc(int);
void		xgetline(char **, FILE *, int);

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

void		xgetline(char **lineptr, FILE *fp, int i)
{
  size_t	len;

  len = 0;
  if ((getline(&lineptr[i], &len, fp)) == -1)
    {
      printf("getline error\n");
      exit(0);
    }
}
