#include <string.h>
#include <stdlib.h>

#include "../include/my.h"

void		init_game_data(t_game *);

void		init_game_data(t_game *game)
{
  game->players_type = xmalloc(sizeof(*game->players_type) * MAX_PLAYERS);
  game->board = xmalloc(sizeof(*game->board) * BOARD_SIZE_X);
  for(int i = 0; i < BOARD_SIZE_Y; i++)
    game->board[i] = xmalloc(sizeof(**game->board) * BOARD_SIZE_X);

    
}

void		init_board(t_game *game)
{
  FILE		*fp;
  size_t	len;
  char		**board_tmp;
  int		i;

  /*
    for(int i = 0; i < 15; i++)
    {
      //      printf("board tmp = %s", board_tmp[i]);
      printf("board = %s", game->board[i]);
      }*/
    
  i = 0;
  fp = fopen(FILE_BOARD_PATH, "r");
  board_tmp = xmalloc(sizeof(*board_tmp) * 15);
  if (fp == NULL)
    {
      printf("error no board file found\n");
      exit(1);
    }
    while(getline(&board_tmp[i], &len, fp) != -1)
      {
	strncpy(game->board[i], board_tmp[i], 15);
	i++;
      }
}
