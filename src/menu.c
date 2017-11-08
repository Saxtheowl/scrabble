#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"
#include "../include/my_list.h"

void		menu_intro(t_game *);

void		menu_pre_game(t_game *game)
{
  printf("Welcome to the game of scrabble\n");
  printf("do you want to skip menu ?\n");
  select_skip_menu(game);
  if(game->is_skip_menu == true)
    {
      config_skip_menu(game);
      start_game(game);
      return;
    }
  printf("select in which language the game will be played : \n");
  select_language_to_play(game);
  printf("select the type of player : \n");
  //  game.players_type = select_players_type();
  
}

