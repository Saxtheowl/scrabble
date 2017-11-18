#include "../include/scrabble.h"

char		get_letter(t_game *);
char		get_rdm_letter(t_game *, int);
void		fulfill_rack(t_game *, int, int);

char		get_letter(t_game *game)
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

void		fulfill_rack(t_game *game, int player, int amount)
{
  int		i = 0;

  while(amount > 0 && game->letters_left > 0 && game->racks[player][i] != '\0')
    {
      if(game->racks[player][i] == ' ')
	{
	  game->racks[player][i] = get_letter(game);
	  game->nb_letters[player]++;
	  game->letters_left--;
	  amount--;
	}
      i++;
    }
}
