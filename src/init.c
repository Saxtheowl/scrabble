#include <string.h>
#include <stdlib.h>

#include "../include/my.h"

void		init_game_data(t_game *);
void		init_alphabet_rules(t_game *);
void		init_board(t_game *);

void		init_game_data(t_game *game)
{
  if(game->is_super_mod == false)
    {
      game->board_path = "board/standard_board";
      game->size_board = 15;
    }
  else
    {
      game->board_path = "board/super_board";
      game->size_board = 21;
    }
  init_board(game);
}

void		init_alphabet_rules(t_game *game)
{
  
}

void		init_super_alphabet_rules(t_game *game)
{
  
}

void		init_board(t_game *game)
{
  FILE		*fp = fopen(game->board_path, "r");
  size_t	len = 0;
  int		i = 0;

  printf("ok\n");
  if (fp == NULL)
    {
      printf("error no board file found\n");
      exit(1);
    }
  game->board = xmalloc(sizeof(*game->board) * game->size_board);
  for(int i = 0; i < game->size_board; i++)
    game->board[i] = xmalloc(sizeof(**game->board) * game->size_board);
  printf("ok\n");
  /*  while(getline(&game->board[i], &len, fp) != -1)
      i++;*/
  for(int i = 0; getline(&game->board[i], &len, fp) != -1; i++);
  printf("ok\n");
  game->board[game->size_board] = NULL;
  printf("ok\n");
}
