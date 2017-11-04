#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"

//#define DEBUG

int		main(int ac, char **av)
{
#ifdef DEBUG_FLAG
  printf("YES DEBUG_FLAG\n");
#else
  printf("NO DEBUG_FLAG\n");
#endif
  return(0);
  if (ac > 1)
    {
      // TODO load game with args
      start_game();
    }
  else
    {
      menu();
      start_game();
    }
}
