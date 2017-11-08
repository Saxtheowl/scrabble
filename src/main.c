#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/my.h"

int		main(int, char **);

int		main(int ac, char **av)
{
#ifdef SUPER_SCRABBLE
  printf("YES SUPER_SCRABBLE\n\n\n");
#else
  printf("NO SUPER_SCRABBLE\n\n\n");
#endif
  
#ifdef DEBUG_FLAG
  printf("YES DEBUG_FLAG\n\n\n");
#else
  printf("NO DEBUG_FLAG\n\n\n");
#endif

  t_game		game;

#ifdef DEBUG_FLAG
  printf("size of struct game: %zu\n", sizeof(game));
#endif

  init_game_data(&game);
  init_board(&game);
  if (ac > 1)
    {
      config_with_av(&game, av);
      // TODO load game with args
      start_game(&game);
    }
  else
    menu_pre_game(&game);
#ifdef DEBUG_FLAG
  printf("return at int main() OK\n");
#endif
  return(0);
}
