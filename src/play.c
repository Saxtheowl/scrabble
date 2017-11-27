#include "../include/scrabble.h"

int		who_play_first(t_game *);
void		make_play(t_game *);

int		who_play_first(t_game *game)
{
  char		biggest = 'Z';
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
	      biggest = 'Z';
	      blank_flag = false;
	    }
	  else
	    {
	      blank_owner = i;
	      blank_flag = true;
	    }
	  //	  printf("Player %d has a %c (blank tile) and begin\n", i, tmp);
	}
      if(tmp < biggest)
	{
	  to_return = i;
	  biggest = tmp;
	}
      i++;
    }
  printf("Player %d has a %c and is first\n", to_return, biggest);
  if(blank_flag == true)
    {
      printf("Player %d has a '?' (blank tile) and then begin\n", blank_owner);
      return(blank_owner);
    }
  else
    return(to_return);
}

void		reset_turn(t_game *game)
{
}

void		make_play(t_game *game)
{
  while(game->is_turn_done == false)
    {
      print_board(game);
      print_players_info(game);
      menu_play(game);
    }
  system("clear");
  game->is_turn_done = false;
}

void		update_turn(t_game *game)
{
  fulfill_rack(game, game->playing, MAX_LETTERS_RACK - game->nb_letters[game->playing]);
  game->is_turn_done = true;
  game->is_side_word = false;
  update_score(game, game->playing);
}

void		play_word(t_game *game, char *pos1, char *pos2)
{
  char		*word;

  printf("Enter word:\n");
  word = put_prompt();
  strncpy(game->word_test, word, strlen(word) - 1);
  printf("play_word word to test =%s\n", word);
  if(is_valid_syntax(game, pos1, pos2) &&
     is_valid_position(game) &&
     (is_connected_to_a_letter(game) || game->is_side_word == true) &&
     is_valid_word(game, game->word_test) &&
     is_valid_new_words(game) &&
     is_letters_in_rack(game, game->word_test) &&
     is_first_turn_valid(game))
    {
#ifdef DEBUG_FLAG
      printf("missing letters:%d\n", MAX_LETTERS_RACK - game->nb_letters[game->playing]);
#endif
      update_turn(game);
#ifdef DEBUG_FLAG
      printf("word is put\n");
#endif
    }
  else
    {
      remove_word(game);
#ifdef DEBUG_FLAG
      printf("word is not put\n");
#endif
    }
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
	    game->racks[game->playing][i] = letters[0];
	}
    }
  game->is_turn_done = true;
}
