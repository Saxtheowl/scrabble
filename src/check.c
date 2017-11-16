#include "../include/scrabble.h"

bool		test_cant_play(t_game *);
bool		is_valid_word(t_game *, char *);

bool		test_cant_play(t_game *game)
{
  return(false);
}

bool		is_valid_word(t_game *game, char *word)
{
  printf("word to test =%s\n", word);
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

bool		is_in_rack(t_game *game, char *word)
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
