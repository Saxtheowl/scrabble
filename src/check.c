#include "../include/scrabble.h"

bool		test_cant_play(t_game *game)
{
  return(false);
}

bool		is_valid_word(t_game *game, char *word)
{
  for(int i = 0; i < game->max_words_dict; i++)
    {
      if(strncmp(word, game->dictionnary[i]), strlen(word) != 0)
	return(false);
    }
  printf("OK STRNCMP");
  return(true);
}
