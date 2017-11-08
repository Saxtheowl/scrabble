#include <string.h>
#include <stdlib.h>

#include "../include/my.h"

void		init_game_data(t_game *);

void		init_game_data(t_game *game)
{
  //  game->players_type = xmalloc(sizeof(*game->players_type) * MAX_PLAYERS);
  
}

void		init_board(t_game *game)
{
  FILE		*fp;
  size_t	len;
  char		**board_tmp;
  int		i;

  i = 0;
  fp = fopen("board", "r");
  board_tmp = xmalloc(sizeof(*board_tmp) * 15);
  if (fp == NULL)
    {
      printf("error no board filefound\n");
      exit(1);
    }
  while(getline(&board_tmp[i], &len, fp) != -1)
    {
      strcpy(game->board[i], board_tmp[i]);
      i++;
    }
}
