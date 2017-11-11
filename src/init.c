#include <string.h>
#include <stdlib.h>

#include "../include/my.h"

void		init_game(t_game *);
void		init_pre_board(t_game *);
void		init_pre_letters(t_game *);
void		init_board(t_game *);
void		init_game_memory(t_game *);
void		init_letters_list(t_game *);
void		init_letters_point(t_game *);

void		init_game(t_game *game)
{
  init_pre_board(game);
  init_pre_letters(game);
  init_game_memory(game);
  init_board(game);
  init_letters_list(game);
  init_letters_point(game);
}

void		init_pre_board(t_game *game)
{
  if(game->is_super_mod == false)
    {
      game->board_path = "files/standard_board";
      game->size_board = 15;
    }
  else
    {
      game->board_path = "files/super_board";
      game->size_board = 21;
    }
}

void		init_pre_letters(t_game *game)
{
  if(game->language == ENGLISH)
    {
      game->max_letters = 100;
      game->letters_path = "files/letters_en";
    }
  else if(game->language == FRENCH)
    {
      game->max_letters = 102;
      game->letters_path = "files/letters_fr";
    }
}

void		init_game_memory(t_game *game)
{
  game->board = xmalloc(sizeof(*game->board) * game->size_board);
  for(int i = 0; i < game->size_board; i++)
    game->board[i] = xmalloc(sizeof(**game->board) * game->size_board);
  //  game->nb_ltr_en = xmalloc(sizeof(*game->nb_ltr_en) * game->max_letters);
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

void		init_letters_list(t_game *game) // not sexy
{
  //  game->nb_ltr_en[0] = { 1 };
  /*  if (game->is_super_mod == false)
      game->nb_ltr_en[0][0] = { 1, 2 };*/
}

void		init_letters_point(t_game *game)
{
  
}
