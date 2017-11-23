#include "../include/scrabble.h"

void		put_letter_in_rack(t_game *game, char letter)
{
  
}

void		fulfill_rack(t_game *game, int player, int amount)
{
  int		i = 0;

  while(amount > 0 && game->letters_left > 0 && game->racks[player][i] != '\0')
    {
      if(game->racks[player][i] == ' ')
	{
	  game->racks[player][i] = give_rdm_letter(game);
	  game->nb_letters[player]++;
	  game->letters_left--;
	  amount--;
	}
      i++;
    }
}

void		fulfill_all_racks(t_game *game)
{
  for(int i = 0; i < game->amount_players; i++)
    fulfill_rack(game, i, 7);
}
