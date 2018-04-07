#include "../include/scrabble.h"

void		free_all(t_game *);

void		free_all(t_game *game)
{
#ifdef DEBUG_FLAG
  printf("free_all start\n");
#endif
  for(int i = 0; i < game->max_words_dict; i++)
    free(game->dictionnary[i]);
  free(game->dictionnary);
#ifdef DEBUG_FLAG
  printf("free_all end\n");
#endif
}
