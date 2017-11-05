#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"

void		menu_intro(t_game);
bool		select_skip_menu();
void		config_skip_menu(t_game game);
int		select_language_to_play();
int		select_number_of_players();
int		*select_players_type();

void		menu_intro(t_game game)
{
  printf("Welcome to the game of scrabble\n");
  printf("select in which language the game will be played : \n");
  game.language = select_language_to_play(game);
  printf("select the type of player : \n");
  game.players_type = select_players_type();
  
}

bool		select_skip_menu()
{
}

void		config_skip_menu()
{
}

int		select_number_of_players()
{
}

int		select_language_to_play()
{
  char		*choice;
  int		nb = 0;

  while (nb != 1 && nb != 2)
    {
      printf("\n1. English\n");
      printf("\n2. French\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  return(nb);
}

int		*select_players_type()
{
  int		*a;

  return(a);
  /*
  int		*players_type[3];
  int		slot_nb = 0;

  while (slot_nb != 1 && nb != 2)
    {
      printf("\n1. English\n");
      printf("\n2. French\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  return(nb);
 */
}
