#include "../include/scrabble.h"

char		get_letter(t_game *game)
{
  char		letter = ' ';
  int		rd;

  while(letter == ' ')
    {
      rd = rand() % (game->max_letters);
      letter = game->letters_list[rd];
    }
  game->letters_list[rd] = ' ';
  return(letter);
}

void		fulfill_rack(t_game *game, int player)
{
  //  int		amount = MAX_LETTERS_RACK - game->nb_letters[players];
  int		i = 0;

  while(game->nb_letters[player] < MAX_LETTERS_RACK && game->letters_left != 0)
    {
      printf("ok3\n");
      if (game->racks[player][i] != ' ')
	i++;
      game->racks[player][i] = get_letter(game);
      game->nb_letters[player]++;
      game->letters_left--;
      i++;
      printf("ok4\n");
    }
    
}
