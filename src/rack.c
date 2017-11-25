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

bool		remove_letter_in_rack(t_game *game, char letter)
{
  for(int i = 0; i < MAX_LETTERS_RACK; i++)
    {
      if(game->racks[game->playing][i] == letter)
	{
	  game->racks[game->playing][i] = ' ';
	  return(true);
	}
    }
  printf("no letter %c found \n", letter);
  return(false);
}

void		put_letter_in_rack(t_game *game, char letter)
{
    for(int i = 0; i < MAX_LETTERS_RACK; i++)
    {
      if(game->racks[game->playing][i] == ' ')
	game->racks[game->playing][i] = letter;
    }
    printf("letter = %c\n", letter);
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
