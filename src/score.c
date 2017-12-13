#include "../include/scrabble.h"

// Letter and word premiums count only on the turn in which they are played. On later turns, letters already played on premium squares count at face value.

// standard 1, 2 = letter 3, 4 = word
// super 1, 2, 3 = letter 4, 5,6 = word

int		get_multiplier(t_game *game, char special)
{
  printf("special multiplier =%c\n", special);
  if(special >= game->symbol_max_letter && special <= game->symbol_max_word)
    {
      printf("to return get multiplier =%d\n", ((special - '0') - (game->symbol_max_letter - '0')));
      return((special - '0') - (game->symbol_max_letter - '0'));
    }
  else
    return(0);
}

int		get_score_from_letter(t_game *game, char c, char special, bool is_new_word)
{
  int		i = get_number_from_letter(c);
  int		point = game->letters_point[i];
  int		tmp;

  printf("i =%d\n", i);
  printf("point =%d\n", point);
  if(is_new_word == true)// wrong to fix
    {
      printf("point2 =%d\n", point);
      return(point);
    }
  else if(special > '0' && special <= game->symbol_max_letter)
    {
      printf("to return score from letter =%d\n", (point * ((special - '0') + 1)));
      printf("special == %d\n", ((special - '0') + 1));
      return(point * ((special - '0') + 1));
    }
  return(point);
}

int		get_score_top_to_bottom(t_game *game, char *word, int cp_y_wrd_p1, int cp_x_wrd_p1, bool is_new_word)
{
  int		score = 0;
  int		multiplier = 1;
  int		y_tmp = cp_y_wrd_p1;
  
  for(int i = 0; word[i] != '\0'; i++)
    {
      score = get_score_from_letter(game, word[i], game->road_word[i], is_new_word) + score;
      printf("score = %d\n", score);
      if(is_new_word == false)
	multiplier = get_multiplier(game, game->road_word[i]) + multiplier;
      //      game->board[cp_y_wrd_p1][cp_x_wrd_p1] = 'X';
      y_tmp++;
    }
  return(score * multiplier);
}

int		get_score_left_to_right(t_game *game, char *word, int cp_y_wrd_p1, int cp_x_wrd_p1, bool is_new_word)
{
  int		score = 0;
  int		multiplier = 1;
  int		x_tmp = cp_x_wrd_p1;
  
  for(int i = 0; word[i] != '\0'; i++)
    {
      score = get_score_from_letter(game, word[i], game->road_word[i], is_new_word) + score;
      printf("score before multiplier = %d\n", score);
      if(is_new_word == false)
	multiplier = get_multiplier(game, game->road_word[i]) + multiplier;
      //      game->board[cp_y_wrd_p1][cp_x_wrd_p1] = 'X';
      x_tmp++;
    }
  return(score * multiplier);
}

void		update_score(t_game *game, char *word, int cp_y_wrd_p1, int cp_x_wrd_p1, bool is_left_to_right, bool is_new_word)
{
  //  game->board[cp_y_wrd_p1][cp_x_wrd_p1] = 'X';
  if(is_left_to_right == true)
    game->score[game->playing] = get_score_left_to_right(game, word, cp_y_wrd_p1, cp_x_wrd_p1, is_new_word) + game->score[game->playing];
  else
    game->score[game->playing] = get_score_top_to_bottom(game, word, cp_y_wrd_p1, cp_x_wrd_p1, is_new_word) + game->score[game->playing];
}

bool		is_bingo(char *word)
{
  
}
