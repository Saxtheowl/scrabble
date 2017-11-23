#include "../include/scrabble.h"

void		fulfill_all_racks(t_game *);
int		who_play_first(t_game *);
void		make_play(t_game *);

void		fulfill_all_racks(t_game *game)
{
  for(int i = 0; i < game->amount_players; i++)
    fulfill_rack(game, i, 7);
}

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
      if(tmp == 'j')
	{
	  if(blank_flag == true) // in the rare case of double case :-O
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
      printf("Player %d has a 'j' (blank tile) and then begin\n", blank_owner);
      return(blank_owner);
    }
  else
    return(to_return);
}

void		update_score(t_game *game, int player)
{
  game->score[player] = 999999;
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
  if(game->is_first_time == true)
    {
      //      system("clear");
      game->is_first_time == false;
    }
  update_score(game, game->playing);
  game->racks[game->playing][2] = ' ';
  game->racks[game->playing][3] = ' ';
  game->nb_letters[game->playing]--;
  game->nb_letters[game->playing]--;
  fulfill_rack(game, game->playing, 2);
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
     //     is_valid_word(game, word) &&
     is_valid_new_words(game) &&
     is_letters_in_rack(game, word))
    {
      printf("word is put\n");
      game->is_turn_done = true;
    }
}   

void		play_pass(t_game *game)
{
  game->is_turn_done = true;
}
