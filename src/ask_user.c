#include <stdio.h>

#include "../include/my.h"

char		*put_prompt();

char		*put_prompt()
{
  char		*prompt;
  char		*commands;

  prompt = ">";
  printf("%s", prompt);
  commands = read_entry();
  return (commands);
}
