#include <string.h>
#include <stdlib.h>

#include "../include/scrabble.h"

void		init_game(t_game *);
void		init_pre_board(t_game *);
void		init_pre_letters(t_game *);
void		init_board(t_game *);
void		init_game_memory(t_game *);
void		init_letters_list(t_game *);
void		init_letters_point(t_game *);
void		init_dictionnary(t_game *);

void		init_game(t_game *game)
{
  init_pre_board(game);
  init_pre_letters(game);
  init_game_memory(game);
  init_board(game);
  init_letters_list(game);
  init_letters_point(game);
  init_dictionnary(game);
  game->letters_left = game->max_letters;
  game->is_first_time = true;
  for(int i = 0; game->nb_letters[i] < game->amount_players; i++)
    game->nb_letters[i] = 0;
  for(int i = 0; i < game->amount_players; i++)
    memset(game->racks[i], ' ', MAX_LETTERS_RACK);
  
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
      game->max_letters = MAX_LETTERS_EN;
      game->letters_list_path =  "files/letters_list_en";
      game->letters_points_path = "files/letters_points_en";
      game->dictionnary_path = "files/dictionnary_en_tmp";
      game->max_words_dict = MAX_WORDS_DICT_EN;
    }
  else if(game->language == FRENCH)
    {
      game->max_letters = MAX_LETTERS_FR;
      game->letters_list_path =  "files/letters_list_fr";
      game->letters_points_path = "files/letters_points_fr";
    }
  if(game->is_super_mod == true)
    {
      game->max_letters = MAX_LETTERS_SUPER;
      game->letters_list_path = "files/letters_list_super";
    }
}

void		init_game_memory(t_game *game)
{
  game->board = xmalloc(sizeof(*game->board) * game->size_board);
  for(int i = 0; i < game->size_board; i++)
    game->board[i] = xmalloc(sizeof(**game->board) * game->size_board);
  game->letters_list = xmalloc(sizeof(*game->letters_list) * game->max_letters);
  game->letters_point = xmalloc(sizeof(*game->letters_point) * NB_LETTERS_ALPHABET);
  game->racks = xmalloc(sizeof(*game->racks) * game->amount_players);
  for(int i = 0; i < game->amount_players; i++)
      game->racks[i] = xmalloc(sizeof(**game->racks) * MAX_LETTERS_RACK);
  game->nb_letters = xmalloc(sizeof(*game->nb_letters) * game->amount_players);
  game->dictionnary = xmalloc(sizeof(*game->dictionnary) * game->max_words_dict);
  for(int i = 0; i < game->max_words_dict; i++)
    game->dictionnary[i] = xmalloc(sizeof(**game->dictionnary) * 1); // WTF * 1 ?
}

void		init_board(t_game *game)
{
  FILE		*fp = fopen(game->board_path, "r");
  size_t	len = 0;
  
  if (fp == NULL)
    super_exit("error no files board found\n");
  for(int i = 0; getline(&game->board[i], &len, fp) != -1; i++);
  game->board[game->size_board] = NULL;
}

void		init_letters_list(t_game *game) // not sexy
{
  FILE		*fp = fopen(game->letters_list_path, "r");
  size_t	len = 0;

  if (fp == NULL)
    super_exit("error no letters list file found\n");
  getline(&game->letters_list, &len, fp);
}

void		init_letters_point(t_game *game)
{
  FILE		*fp = fopen(game->letters_points_path, "r");
  size_t	len = 0;
  char		*tmp;

  if (fp == NULL)
    super_exit("error no letters points file found\n");
  for(int i = 0; i < NB_LETTERS_ALPHABET + 1; i++)
    {
      getline(&tmp , &len, fp);
      game->letters_point[i] = atoi(tmp);  
    }
}

void		init_dictionnary(t_game *game)
{
  FILE		*fp = fopen(game->dictionnary_path, "r");
  size_t	len = 0;

  if (fp == NULL)
    super_exit("error no dictionnary file found\n");
  for(int i = 0; i < game->max_words_dict; i++)
    getline(&game->dictionnary[i], &len, fp);
  game->dictionnary[game->max_words_dict] = NULL;
}
