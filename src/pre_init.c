#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../include/scrabble.h"

void		pre_init_game_data(t_game *);

void		pre_init_game_data(t_game *game)
{
  srand(time(NULL));
  game->players_type = xmalloc(sizeof(*game->players_type) * MAX_PLAYERS);
  game->is_letters_from_av = false;
  game->is_always_scramble_rack = false;
  game->is_list_letters_linear = false;
}
