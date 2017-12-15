#include "../include/scrabble.h"

char		*scramble_rack(char *rack) // easy one
{
  int		len = strlen(rack);
  int		i = 0;
  char		tmp;

  while(i < len / 2)
    {
      tmp = rack[i];
      rack[i] = rack[len - 1];
      rack[len - 1] = tmp;
      i++;
    }
  return(rack);
}

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

char		give_linear_letter(t_game *game)
{
  printf("max letters =%d\n", game->max_letters);
  printf("letters left =%d\n", game->letters_left);
  return(game->letters_list[game->max_letters - game->letters_left]);
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
      if(game->racks[game->playing][i] == letter ||
	 game->racks[game->playing][i] == to_lower_solo(letter))
	{
	  game->racks[game->playing][i] = ' ';
	  game->nb_letters[game->playing]--;
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
	{
	  printf("put letter in rack letter for = %c\n", letter);
	  game->racks[game->playing][i] = letter;
	  return;
	}
    }
    printf("put letter in rack letter = %c\n", letter);
}

void		fulfill_rack(t_game *game, int player, int amount)
{
  int		i = 0;

  while(amount > 0 && game->letters_left > 0 && game->racks[player][i] != '\0')
    {
      if(game->racks[player][i] == ' ')
	{
	  if(game->is_list_letters_linear == true)
	    game->racks[player][i] = give_linear_letter(game);
	  else
	    game->racks[player][i] = give_rdm_letter(game);
	  game->nb_letters[player]++;
	  game->letters_left--;
	  amount--;
	}
      i++;
    }
  if(game->is_always_scramble_rack == true)
    {
      printf("scramble ok\n");
      game->racks[player] = scramble_rack(game->racks[player]);
    }
}

void		fulfill_all_racks(t_game *game)
{
  for(int i = 0; i < game->amount_players; i++)
    fulfill_rack(game, i, 7);
}

void		put_letter_back_in_list(t_game *game, char letter)
{
  int		i = 0;
  
  while(game->letters_list[i] != ' ')
    i++;
  game->letters_list[i] = letter;
  game->letters_left++;
}

void		put_letters_back_in_rack(t_game *game, char *retired_letters)
{
  printf("retired letters put letters back in rack =%s\n", retired_letters);
  for(int i = 0; retired_letters[i] != '\0'; i++)
    {
      game->nb_letters[game->playing]++;
      put_letter_in_rack(game, retired_letters[i]);
      printf("retired letters c =%c\n", retired_letters[i]);
    }
}

