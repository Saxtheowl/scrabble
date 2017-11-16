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
  int		nb_letters = strlen(word) - 1;
  int		i = 0;
  int		y = 0;
  char		to_find = word[y];

  // WASTE
  // WAEASTE

  while(nb_letters > 0)
    {
      to_find = word[y];
      while(i < game->nb_letters[game->playing])
	{
	  if(game->racks[game->playing][i])
	    {
	      to_find = word[y];
	      printf("to find = %c\n", word[y]);
	      nb_letters--;
	      y++;
	      i = 0;
	    }
	  else
	    i++;
	}
      printf(" is in rack false\n");
      return(false);
    }
  printf(" is in rack true\n");
  return(true);
}
