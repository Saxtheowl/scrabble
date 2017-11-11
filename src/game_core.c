#include "../include/my.h"

void		start_game(t_game *);

void		start_game(t_game *game)
{
#ifdef DEBUG_FLAG
  printf("skip menu = %d\n", game->is_skip_menu);
  printf("lang = %d\n", game->language);
  printf("amount = %d\n", game->amount_players);
  printf("type p 1 = %d\n", game->players_type[0]);
  printf("type p 2 = %d\n", game->players_type[1]);
  printf("type p 3 = %d\n", game->players_type[2]);
  printf("board is :\n");
  /*  for(int i = 0; i < 21; i++)
      printf("%s", game->board[i]);*/
  for(int i = 0; game->board[i] != NULL; i++)
    printf("%s", game->board[i]);
#endif
  return;
}
