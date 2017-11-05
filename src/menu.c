#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"

void		menu_intro(t_game);
int		pick_language_to_play();

void		menu_intro(t_game game)
{
  printf("Welcome to the game of scrabble\n");
  printf("select in which language the game will be played\n");
  game.language = pick_language_to_play(game);
}

int		pick_language_to_play()
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
