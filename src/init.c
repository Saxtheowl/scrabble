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
  if(game->is_letters_from_av == false)
    {
      printf("wut\n");
      init_letters_list(game);
      game->letters_left = game->max_letters;
    }
  init_letters_point(game);
  init_dictionnary(game);
  game->is_first_turn = true;
  game->is_turn_done = false;
  game->is_side_word = false;
  game->is_letter_middle = false;
  game->is_word_put = false;
  for(int i = 0; game->nb_letters[i] < game->amount_players; i++)
    game->nb_letters[i] = 0;
  for(int i = 0; i < game->amount_players; i++)
    {
      memset(game->racks[i], ' ', MAX_LETTERS_RACK);
      game->score[i] = 0;
      game->old_score[i] = 0;
    }
}

void		init_pre_board(t_game *game)
{
  if(game->is_super_mod == false)
    {
      game->board_path = "files/standard_board_t6";
      game->size_board = 15;
    }
  else
    {
      game->board_path = "files/super_board_t1";
      game->size_board = 21;
    }
}

void		init_pre_letters(t_game *game)
{
  if(game->language == ENGLISH)
    {
      if(game->is_letters_from_av == false)
	game->max_letters = MAX_LETTERS_EN;
      game->letters_list_path =  "files/letters_list_en";
      game->letters_points_path = "files/letters_points_en";
      game->dictionnary_path = "files/dictionnary_en_tmp";
      game->max_words_dict = MAX_WORDS_DICT_EN;
    }
  else if(game->language == FRENCH)
    {
      if(game->is_letters_from_av == false)
	game->max_letters = MAX_LETTERS_FR;
      game->letters_list_path =  "files/letters_list_fr";
      game->letters_points_path = "files/letters_points_fr";
      game->dictionnary_path = "files/dictionnary_fr_tmp";
      game->max_words_dict = MAX_WORDS_DICT_FR;
    }
  if(game->is_super_mod == true)
    {
      game->max_letters = MAX_LETTERS_SUPER;
      game->letters_list_path = "files/letters_list_super";
      game->symbol_max_letter = MAX_SYMBOL_MULTIPLY_LETTER_SUPER + '0';
      game->symbol_max_word = MAX_SYMBOL_MULTIPLY_WORD_SUPER + '0';
    }
  else
    {
      game->symbol_max_letter = MAX_SYMBOL_MULTIPLY_LETTER_STANDARD + '0';
      game->symbol_max_word = MAX_SYMBOL_MULTIPLY_WORD_STANDARD + '0';
    }
  
}

void		init_game_memory(t_game *game) // fcking C language lul
{
  game->board = xmalloc(sizeof(*game->board) * game->size_board);
  for(int i = 0; i < game->size_board; i++)
    game->board[i] = xmalloc(sizeof(**game->board) * game->size_board);
  if(game->is_letters_from_av == false) // TRICKY ?
    game->letters_list = xmalloc(sizeof(*game->letters_list) * game->max_letters);
  game->letters_point = xmalloc(sizeof(*game->letters_point) * NB_LETTERS_ALPHABET);
  game->racks = xmalloc(sizeof(*game->racks) * game->amount_players);
  for(int i = 0; i < game->amount_players; i++)
      game->racks[i] = xmalloc(sizeof(**game->racks) * MAX_LETTERS_RACK);
  game->nb_letters = xmalloc(sizeof(*game->nb_letters) * game->amount_players);
  game->dictionnary = xmalloc(sizeof(*game->dictionnary) * game->max_words_dict);
  for(int i = 0; i < game->max_words_dict; i++)
    game->dictionnary[i] = xmalloc(sizeof(**game->dictionnary) * 1); // WTF * 1 ?
  game->old_score = xmalloc(sizeof(*game->old_score) * game->amount_players);
  game->score = xmalloc(sizeof(*game->score) * game->amount_players);
  game->road_word = xmalloc(sizeof(*game->road_word) * game->size_board);
  game->word_test = xmalloc(sizeof(*game->word_test) * game->size_board);
}

void		init_board(t_game *game)
{
  FILE		*fp = fopen(game->board_path, "r");
  size_t	len = 0;
  int		i = 0;
  
  if (fp == NULL)
    super_exit("error no files board found\n");
  while(getline(&game->board[i], &len, fp) != -1) // not clear
    i++;
  game->board[i] = NULL;
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
