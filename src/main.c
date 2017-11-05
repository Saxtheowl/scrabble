#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/my.h"

#define MAX_PLAYER 4
#define HUMAN 0
#define AI 1

int		main(int, char **);

int		main(int ac, char **av)
{
#ifdef DEBUG_FLAG
  printf("YES DEBUG_FLAG\n");
#else
  printf("NO DEBUG_FLAG\n");
#endif
  
  t_game		game;
  if (ac > 1)
    {
      // TODO load game with args
      start_game(game);
    }
  else
    {
      menu_intro(game);
      start_game(game);
    }
}
