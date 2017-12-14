#include "../include/scrabble.h"

int		who_play_first(t_game *);
void		make_play(t_game *);
/*
int		who_play_first(t_game *game)
{
  char		lowest = 'Z';
  char		tmp;
  int		to_return;
  int		i = 0;
  int		blank_flag = false;
  int		blank_owner = 0;

  while(i < game->amount_players)
    {
      tmp = get_rdm_letter(game, i);
      printf("Player %d pick a %c\n", i, tmp);
      if(tmp == '?')
	{
	  if(blank_flag == true) // in the rare case of double blank :-O
	    {
	      i = 0;
	      blank_owner = 0;
	      tmp = 'Z';
	      lowest = 'Z';
	      blank_flag = false;
	    }
	  else
	    {
	      blank_owner = i;
	      blank_flag = true;
	    }
	  //	  printf("Player %d has a %c (blank tile) and begin\n", i, tmp);
	}
      if(tmp < lowest)
	{
	  to_return = i;
	  lowest = tmp;
	}
      i++;
    }
  printf("Player %d has a %c and so is first\n", to_return, lowest);
  if(blank_flag == true)
    {
      printf("Player %d has a '?' (blank tile) and so is first\n", blank_owner);
      return(blank_owner);
    }
  else
    return(to_return);
}
*/

int		who_play_first(t_game *game) // fuck this lets do a standard random, it is the same
{
  return(rand() % (game->amount_players));
}

void		make_play(t_game *game)
{
  while(game->is_turn_done == false)
    {
      print_board(game);
      print_players_info(game);
      menu_play(game);
    }
  //  system("clear");
  game->is_turn_done = false;
}

void		reset_turn(t_game *game)
{

}

void		update_turn(t_game *game)
{
  game->score[game->playing] = game->score[game->playing] + get_score(game, game->word_test, 0, 0);
  fulfill_rack(game, game->playing, MAX_LETTERS_RACK - game->nb_letters[game->playing]);
  game->is_turn_done = true;
  game->is_side_word = false;
}

void		play_word(t_game *game, char *pos1, char *pos2)
{
  char		*word;

  printf("Enter word:\n");
  word = put_prompt();
  strncpy(game->word_test, word, strlen(word) - 1);
  game->word_test[strlen(word) -1] = '\0';
  printf("play_word =%s\n", word);
  printf("play_word_test =%s\n", game->word_test);
  printf("play_word =%d\n", strlen(word));
  printf("play_word test len =%d\n", strlen(game->word_test));
  if(is_valid_syntax(game, pos1, pos2) &&
     is_valid_position(game) &&
     is_valid_new_words(game)) //&&
     //     is_letters_in_rack(game, game->word_test))
    {
      put_word(game);      
      update_turn(game);
#ifdef DEBUG_FLAG
      printf("word is put\n");
#endif
    }
  else
    remove_word(game);
}   

void		play_exchange_letters(t_game *game, char *letters)
{
  for(int i = 0; letters[i] != '\0'; i++)
    {
      if(is_lower_char(letters[i]))
	 letters[i] = '?';
      if(remove_letter_in_rack(game, letters[i]))
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
  if(letters[0] >= 'a' && letters[0] <= 'z')
    {
      for(int i = 0; i < MAX_LETTERS_RACK; i++)
	{
	  if(game->racks[game->playing][i] == '?')
	    {
	      game->racks[game->playing][i] = letters[0];
	      game->is_turn_done = true;
	    }
	  else
	    game->is_turn_done = false;
	}
    }
}
