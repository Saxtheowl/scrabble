#define _GNU_SOURCE
#include "../include/scrabble.h"

char		*read_entry();
char		*put_prompt();
void		super_exit();
int		rack_strlen(char *);
bool		is_char(char);
bool		is_num_char(char);
bool		is_lower_char(char);
bool		is_upper_char(char);
char		to_lower_solo(char);
char		to_upper_solo(char);
char		*to_upper(char *);
int		strcmp_dictionnary(char *, char *);
int		get_number_from_letter(char);
void		print_double_tab(char **);



char		*read_entry()
{
  char *buffer = NULL;
  size_t len;
  
  if (getline(&buffer, &len, stdin) == -1)
    printf("getline error\n");
  return (buffer);
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

  while (rack[i] != '\0' && rack[i] != ' ' )
    i++;
  return (i);
}

bool		is_char(char c)
{
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return (true);
  return (false);
}

bool		is_num_char(char c)
{
  if (c >= '0' && c <= '9')
    return (true);
  return (false);
}

bool		is_lower_char(char c)
{
  if (c >= 'a' && c <= 'z')
    return (true);
  return (false);
}

bool		is_upper_char(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (true);
  return (false);
}

char		to_lower_solo(char letter)
{
  if (letter >= 'A' && letter <= 'Z')
    letter = letter + 32 ;
  return (letter);
}

char		to_upper_solo(char letter)
{
  if (letter >= 'a' && letter <= 'z')
    letter = letter - 32;
  return (letter);
}

char		*to_upper(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
    }
  return (str);
}

int		strcmp_dictionnary(char *wrd, char *dict)
{
  int		i;

  i = 0;
  /*  printf("s1=%s\n", wrd);
      printf("s2=%s\n", dict);*/
  
  while ((wrd[i] == dict[i]) && (wrd[i] != '\0') && (dict[i] != '\0'))
    i++;
  if (wrd[i] == '\0' && dict[i] == '\n') //s2[i] == '\n')
    return (true);
  return (false);
  
  //  return (s1[i] - s2[i]);
}

int		get_number_from_letter(char c)
{
  char		*alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i <= NB_LETTERS_ALPHABET; i++)
    {
      if (alphabet[i] == c)
	return (i);
    }
  return (26);
}

void		print_double_tab(char **dbtab)
{
  for (int i = 0; dbtab[i] != NULL; i++)
    printf("%s\n", dbtab[i]);
}
