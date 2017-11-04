#include <stdio.h>
#include <stdlib.h>

#include "../include/my.h"

void		menu()
{
  char		*choice;
  int		nb = 0;
  
  while (nb != 1 && nb != 2)
    {
      printf("Welcome to the game of scrabble\n");
      printf("select in which language the game will be played\n");
      printf("\n1. English\n");
      printf("\n1. French\n");
      choice = put_prompt();
      nb = atoi(choice);
      
    }
}
