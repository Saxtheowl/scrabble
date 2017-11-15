#include "../include/scrabble.h"

bool		test_cant_play(t_game *game)
{
  return(false);
}

bool		is_valid_word(t_game *game, char *word)
{
  for(int i = 0; i < game->max_words_dict; i++)
    {
      if(strcmp_dictionnary(word, game->dictionnary[i]) == true)
	return(true);
    }
  return(false);
}
