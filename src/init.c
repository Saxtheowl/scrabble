#include <string.h>
#include <stdlib.h>

#include "../include/my.h"

void		init_game(t_game *);
void		init_game_data(t_game *);
void		init_game_memory(t_game *);
void		init_board(t_game *);
void		init_letters(t_game *);

void		init_game(t_game *game)
{
  init_game_data(game);
  init_game_memory(game);
  init_board(game);
}

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
  game->alphabet = "abcdefghijklmnopqrstuvwxyz";
}

void		init_game_memory(t_game *game)
{
  game->board = xmalloc(sizeof(*game->board) * game->size_board);
  for(int i = 0; i < game->size_board; i++)
    game->board[i] = xmalloc(sizeof(**game->board) * game->size_board);
  game->nb_ltr_en = xmalloc(sizeof(*game->nb_ltr_en) * 2);
  for(int i = 0; i < 2; i++)
    game->nb_ltr_en[i] = xmalloc(sizeof(**game->nb_ltr_en) * NB_LETTERS_ALPHABET);
}

void		init_board(t_game *game)
{
  FILE		*fp = fopen(game->board_path, "r");
  size_t	len = 0;

  if (fp == NULL)
    {
      printf("error no board file found\n");
      exit(1);
    }
  for(int i = 0; getline(&game->board[i], &len, fp) != -1; i++);
  game->board[game->size_board] = NULL;
}

void		init_letters(t_game *game) // not sexy
{
  /*  if (game->is_super_mod == false)
      game->nb_ltr_en[0][0] = { 1, 2 };*/
}
