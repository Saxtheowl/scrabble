#include "../include/scrabble.h"

char		*scramble_rack(char *);
char		give_rdm_letter(t_game *);
char		get_rdm_letter(t_game *);
bool		remove_letter_in_rack(t_game *, char);
void		put_letter_in_rack(t_game *, char);
void		fulfill_rack(t_game *, int, int);
void		fulfill_all_racks(t_game *);
void		put_letter_back_in_list(t_game *, char);
void		put_letters_back_in_rack(t_game *, char *);

char		*scramble_rack(char *rack) // easy one
{
  int		len = strlen(rack);
  int		i = 0;
  char		tmp;

  while (i < len / 2)
    {
      tmp = rack[i];
      rack[i] = rack[len - 1];
      rack[len - 1] = tmp;
      i++;
    }
  return (rack);
}

char		give_rdm_letter(t_game *game)
{
  char		letter = ' ';
  int		rd;

  while (letter == ' ')
    {
      rd = rand() % (game->max_letters);
      letter = game->letters_list[rd];
    }
  game->letters_list[rd] = ' ';
  return (letter);
}

char		give_linear_letter(t_game *game)
{
  return (game->letters_list[game->max_letters - game->letters_left]);
}

char		get_rdm_letter(t_game *game)
{
  char		letter = ' ';
  int		rd;

  while (letter == ' ')
    {
      rd = rand() % game->max_letters;
      letter = game->letters_list[rd];
    }
  return (letter);
}

bool		remove_letter_in_rack(t_game *game, char letter)
{
  
  for (int i = 0; i < MAX_LETTERS_RACK; i++)
    {
      if (game->racks[game->playing][i] == letter) /*||
						     game->racks[game->playing][i] == to_lower_solo(letter))*/
	{
	  game->racks[game->playing][i] = ' ';
	  game->nb_letters[game->playing]--;
	  return (true);
	}
    }
  return (false);
}

void		put_letter_in_rack(t_game *game, char letter)
{
    for (int i = 0; i < MAX_LETTERS_RACK; i++)
    {
      if (game->racks[game->playing][i] == ' ')
	{
	  game->racks[game->playing][i] = letter;
	  return;
	}
    }
}

void		fulfill_rack(t_game *game, int player, int amount)
{
  int		i = 0;

  while (amount > 0 && game->letters_left > 0 && game->racks[player][i] != '\0')
    {
      if (game->racks[player][i] == ' ')
	{
	  if (game->is_list_letters_linear == true)
	    game->racks[player][i] = give_linear_letter(game);
	  else
	    game->racks[player][i] = give_rdm_letter(game);
	  game->nb_letters[player]++;
	  game->letters_left--;
	  amount--;
	}
      i++;
    }
  if (game->is_always_scramble_rack == true)
    {
      game->racks[player] = scramble_rack(game->racks[player]);
    }
}

void		fulfill_all_racks(t_game *game)
{
  for (int i = 0; i < game->amount_players; i++)
    fulfill_rack(game, i, 7);
}

void		put_letter_back_in_list(t_game *game, char letter)
{
  int		i = 0;
  
  while (game->letters_list[i] != ' ')
    i++;
  game->letters_list[i] = letter;
  game->letters_left++;
}

void		put_letters_back_in_rack(t_game *game, char *retired_letters)
{
  for (int i = 0; retired_letters[i] != '\0'; i++)
    {
      game->nb_letters[game->playing]++;
      put_letter_in_rack(game, retired_letters[i]);
    }
}

