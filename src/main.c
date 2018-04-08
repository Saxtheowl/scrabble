#include "../include/scrabble.h"

void		interrupt_handler();
int		main(int, char **);

void		interrupt_handler()
{
  printf("exit with ctrl c\n");
  exit(0);
}

int		main(int ac, char **av)
{
  signal(SIGINT, interrupt_handler);
  /*
#ifdef DEBUG_FLAG
  printf("YES DEBUG_FLAG\n\n\n");
#else
  printf("NO DEBUG_FLAG\n\n\n");
  #endif
  */

  t_game		game;

#ifdef DEBUG_FLAG
  printf("size of struct game: %zu\n", sizeof(game));
#endif

  pre_init_game_data(&game);
  if (ac > 1)
    config_with_av(&game, av);
  else
    menu_pre_game(&game);
#ifndef DEBUG_FLAG
  clear();
#endif
  init_game(&game);
  start_game(&game);

#ifdef DEBUG_FLAG
  printf("return at int main() OK\n");
  printf("size of struct game: %zu\n", sizeof(game));
#endif
  //  printf("%s\n", game.letters_list);
  free_all(&game);
  printf("Bye\n");
  return(0);
}
