#include <stdio.h>
#include <stdlib.h>

#include "../include/scrabble.h"

void		menu_intro(t_game *);

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
  printf("\n( Player %d ) OPTIONS : \n", game->playing);
  getchar();
}
