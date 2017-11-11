#include "../include/my.h"

void		end_of_the_game(t_game *game)
{
  for(int i = 0; i < game->size_board; i++)
    free(game->board[i]);
  free(game->board);
}
