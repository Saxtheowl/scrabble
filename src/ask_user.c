#include <stdio.h>

#include "../include/my.h"

char		*put_prompt()
{
  char		*prompt;
  char		*commands;

  prompt = ">";
  puts(prompt);
  commands = read_entry();
  return (commands);
}
