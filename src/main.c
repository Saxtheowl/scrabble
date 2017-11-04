#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"

int		main(int ac, char **av)
{
#ifdef DEBUG_FLAG
  printf("YES DEBUG_FLAG\n");
#else
  printf("NO DEBUG_FLAG\n");
#endif
  
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
