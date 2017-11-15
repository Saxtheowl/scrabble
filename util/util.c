#include <stdio.h>
#include <stdlib.h>

#include "../include/scrabble.h"

char		*put_prompt();
char		*read_entry();
void		super_exit();

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

void		super_exit(char *message)
{
  printf("%s", message);
  exit(1);
}

int		rack_strlen(char *rack)
{
  int		i = 0;

  while(rack[i] != '\0' && rack[i] != ' ' )
    i++;
  return(i);
}
