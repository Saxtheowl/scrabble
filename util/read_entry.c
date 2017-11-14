#include <stdio.h>
#include <stdlib.h>

#include "../include/scrabble.h"

char		*put_prompt();
char		*read_entry();
void		xgetline(char **, FILE *, int);

char		*read_entry()
{
  char *buffer = NULL;
  size_t len;
  
  if (getline(&buffer, &len, stdin) == -1)
    printf("getline error\n");
  return(buffer);
}

char		*put_prompt()
{
  char		*prompt;
  char		*commands;

  prompt = ">";
  printf("%s", prompt);
  commands = read_entry();
  return (commands);
}
