#include "../include/scrabble.h"

char		give_rdm_letter(t_game *game)
{
  char		letter = ' ';
  int		rd;

  while(letter == ' ')
    {
      rd = rand() % (game->max_letters);
      //      printf("rd = %d\n", rd);
      letter = game->letters_list[rd];
      //      printf("new char = %c\n", letter);
    }
  game->letters_list[rd] = ' ';
  return(letter);
}

char		get_rdm_letter(t_game *game, int player)
{
  char		letter = ' ';
  int		rd;

  while(letter == ' ')
    {
      rd = rand() % game->max_letters;
      letter = game->letters_list[rd];
    }
  return(letter);
}
