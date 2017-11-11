#include <string.h>
#include <stdlib.h>

#include "../include/my.h"

void		pre_init_game_data(t_game *);

void		pre_init_game_data(t_game *game)
{
  game->players_type = xmalloc(sizeof(*game->players_type) * MAX_PLAYERS);    
}
