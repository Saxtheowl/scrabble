#include "../include/scrabble.h"

int		who_play_first(t_game *);
void		make_play(t_game *);
void		update_turn(t_game *);
void		play_word(t_game *, char *, char *);
void		play_exchange_letters(t_game *, char *);
void		play_pass(t_game *);
void		transform_joker(t_game *, char *);

int		who_play_first(t_game *game) // fuck this lets do a standard random, it is the same
{
  return (rand() % (game->amount_players));
}

void		make_play(t_game *game)
{
  while (game->is_turn_done == false)
    {
      print_board(game);
      print_players_info(game);
      menu_play(game);
    }
  //  system("clear");
  game->is_turn_done = false;
}

void		update_turn(t_game *game)
{
  game->score[game->playing] = game->score[game->playing] + get_score(game, game->word_test, 0, 0) + game->new_word_pot;
  fulfill_rack(game, game->playing, MAX_LETTERS_RACK - game->nb_letters[game->playing]);
  game->is_turn_done = true;
  game->is_side_word = false;
  game->is_word_put = false;
}

void		play_word(t_game *game, char *pos1, char *pos2)
{
  char		*word;

  printf("Enter word:\n");
  word = put_prompt();
  strncpy(game->word_test, word, strlen(word) - 1);
  game->word_test[strlen(word) -1] = '\0';
  if(game->new_word_pot > 0)
    game->new_word_pot = 0;
  if (is_valid_syntax(game, pos1, pos2) &&
      is_valid_position(game) &&
      is_valid_word(game) &&
      is_valid_new_words(game) &&
      is_letters_in_rack(game))
    {
      put_word(game);
      update_turn(game);
#ifdef DEBUG_FLAG
      printf("word is put\n");
#endif
    }
  else if (game->is_word_put == true)
    remove_word(game);
}   

void		play_exchange_letters(t_game *game, char *letters)
{
  for (int i = 0; letters[i] != '\0'; i++)
    {
      if (is_lower_char(letters[i]) == true)
	 letters[i] = '?';
      if (remove_letter_in_rack(game, letters[i]) == true)
	{
	  put_letter_back_in_list(game, letters[i]);
	  fulfill_rack(game, game->playing, 1);
	  game->is_turn_done = true;
	}      
    }
}

void		play_pass(t_game *game)
{
  game->is_turn_done = true;
}

void		transform_joker(t_game *game, char *letters)
{
  if (letters[0] >= 'a' && letters[0] <= 'z')
    {
      for (int i = 0; i < MAX_LETTERS_RACK; i++)
	{
	  if (game->racks[game->playing][i] == '?')
	    {
	      game->racks[game->playing][i] = letters[0];
	      //	      game->is_turn_done = true;
	      return;
	    }
	  else
	    game->is_turn_done = false;
	}
    }
}
