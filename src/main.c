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

  pre_init_game_data(&game);
  if (ac > 1)
    config_with_av(&game, av);
  else
    menu_pre_game(&game);
  init_game(&game);
  start_game(&game);

#ifdef DEBUG_FLAG
  printf("return at int main() OK\n");
  printf("size of struct game: %zu\n", sizeof(game));
#endif
  //  end_of_the_game(&game);
  //  free(&game);
  return(0);
}
