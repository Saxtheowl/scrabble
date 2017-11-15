#include "../include/scrabble.h"

void		fulfill_all_racks(t_game *game)
{
  printf("ok3\n");
  for(int i = 0; i < game->amount_players; i++)
    {
      fulfill_rack(game, i, 7);
      getchar();
      printf("ok3\n");
    }
}

int		who_play_first(t_game *game)
{
  //  fulfill_all_racks(game);
  return(1);
}

void		make_play(t_game *game)
{
  menu_play(game);
  game->racks[game->playing][2] = ' ';
  game->racks[game->playing][3] = ' ';
  game->nb_letters[game->playing]--;
  game->nb_letters[game->playing]--;
  fulfill_rack(game, game->playing, 2);
}
