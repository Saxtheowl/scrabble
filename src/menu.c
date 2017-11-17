#include <stdio.h>
#include <stdlib.h>

#include "../include/scrabble.h"

void		menu_pre_game(t_game *);
void		menu_play(t_game *);

void		menu_pre_game(t_game *game)
{
  printf("Welcome to the game of scrabble\n");
  game->is_skip_menu = select_yes_or_no_question(game, "Skip menu ?\n");
  if(game->is_skip_menu == true)
    {
      config_skip_menu(game);
      return;
    }
  game->is_super_mod = select_yes_or_no_question(game, "Super scrabble mod ?\n");
  game->is_duplicate_mod = select_yes_or_no_question(game, "Duplicate mod ?\n");
  printf("In which language the game will be played : \n");
  select_language_to_play(game);
  printf("How many players : \n");
  select_number_of_players(game);
  printf("Select the type of player : \n");
  select_players_type(game);
}

void		menu_play(t_game *game)
{
  char		*choice;
  int		nb = 0;
  
  printf("\n( Player %d ) OPTIONS : \n", game->playing);
  while(nb != 1 && nb != 2 && nb != 3) // lol
    {
      printf("1. Play word\n");
      printf("2. Change letter(s)\n");
      printf("3. Pass turn\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  if(nb == 1)
    {
      char		*pos1;
      char		*pos2;

      printf("Enter the position where the word start (eg: E3)\n");
      pos1 = put_prompt();
      printf("Enter the position where the word end (eg: E6)\n");
      pos2 = put_prompt();
      play_word(game, pos1, pos2);
      if (game->is_turn_done == false)
	printf("wrong syntax or wrong position or wrong word or bad coordinate\n");
    }
  if(nb == 3)
    play_pass(game);
  //  getchar();
}
