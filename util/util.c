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

bool		is_char(char c)
{
  if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
      //      printf("\nc == %c\n", c);
      return(true);
    }
  printf("\nc == %c\n", c);
  return(false);
}

int		strcmp_dictionnary(char *s1, char *s2)
{
  int		i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  if(s1[i] == '\0' && s2[i] == '\n')
    return(true);
  return(false);
  
  //  return (s1[i] - s2[i]);
}
