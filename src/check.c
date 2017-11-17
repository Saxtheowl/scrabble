#include "../include/scrabble.h"
#include <string.h>

bool		test_cant_play(t_game *);
bool		is_valid_word(t_game *, char *);

bool		test_cant_play(t_game *game)
{
  return(false);
}

bool		is_syntax_letter_valid(t_game *game, char *pos)
{
  char		max_letter;

  if(game->is_super_mod == true)
    max_letter = 'U';
  else
    max_letter = 'O';
  if(pos[0] >= 'A' && pos[0] <= max_letter)
    return(true);
  return(false);
}

bool		is_syntax_number_valid(t_game *game, char *pos)
{
  char		*tmp_pos;
  int		dat_number;
  int		i = 1;

  tmp_pos = malloc(sizeof(tmp_pos) * 3);
  while(pos[i] != '\0' && pos[i] != '\n' && pos[i] >= '0' && pos[i] <= '9')//|| pos[i] != '\n')
    i++;
  if(i == 2)
    {
      dat_number = pos[1] - '0';
    }
  else if(i == 3)
    {
      tmp_pos[0] = pos[1];
      tmp_pos[1] = pos[2];
      tmp_pos[2] = '\0';
      dat_number = atoi(pos);
    }
  printf("number= %d\n", dat_number);
  if(dat_number <= game->size_board)
    return(true);
  return(false);
}

bool		is_valid_syntax(t_game *game, char *pos)
{
  printf("pos =%s\n", pos);
  if(is_syntax_letter_valid(game, pos) && is_syntax_number_valid(game, pos))
    {
      printf("syntax valid\n");
      return(true);
    }
  printf("syntax wrong\n");
  return(false);
}

bool		is_valid_position(t_game *game, char* pos1, char *pos2)
{
  return(true);
}

bool		is_valid_word(t_game *game, char *word)
{
  printf("is_valid_word word to test =%s\n", word);
  for(int i = 0; i < game->max_words_dict; i++)
    {
      if(strcmp_dictionnary(word, game->dictionnary[i]) == true)
	{
	  printf(" is valid true\n");
	  return(true);
	}
    }
  printf(" is valid false\n");
  return(false);
}

bool		is_in_rack(t_game *game, char *word, int x, int y)
{
  char		word_cp[7];

  strncpy(word_cp, word, strlen(word));
  printf("word = %s\n", word);
  printf("word cp= %s\n", word_cp);
  
  // WASTE
  // WS TESA
  printf(" is in rack false\n");
  return(false);
}
