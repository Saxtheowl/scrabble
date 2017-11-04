#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"

int		main(int ac, char **av)
{
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
