#include "../include/scrabble.h"

char		get_letter(t_game *game)
{
  char		letter = ' ';
  int		rd;

  while(letter == ' ')
    {
      rd = rand() % (game->max_letters);
      printf("rd = %d\n", rd);
      letter = game->letters_list[rd];
      //      printf("new char = %c\n", letter);
    }
  game->letters_list[rd] = ' ';
  return(letter);
}

void		fulfill_rack(t_game *game, int player)
{
  int		i = 0;

    while(game->nb_letters[player] < MAX_LETTERS_RACK && game->letters_left != 0 && i < MAX_LETTERS_RACK)
    {
      printf("old char = %c\n", game->racks[player][i]);
      if (game->racks[player][i] == ' ')
	{
	  game->racks[player][i] = get_letter(game);
	  game->nb_letters[player]++;
	  game->letters_left--;
	  printf("letters left : %d\n", game->letters_left);
	  i++;
	}
      else
	i++;
    }
}
