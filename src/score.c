#include "../include/scrabble.h"

int		get_multiplier(char special)
{


  printf("START get multiplier from letter\n");
  if(special > '3' && special < '7')
    return(special - '0');
}

int		get_score_from_letter(t_game *game, char c, char special, bool is_new_word)
{
  int		i = get_number_from_letter(c);
  int		point = game->letters_point[i];
  int		tmp;

  printf("START get score from letter\n");
  printf("get score from letter i =%d\n", i);
  printf("get score from letter point =%d\n", point);
  printf("get score from letter c =%c\n", c);
  printf("get score from letter special is =%c\n", special);
  if(is_new_word == true)
    return(point);
  else if(special > '0' && special < '4')
    {
      printf("special is %c\n", special);
      printf("to return = %d\n", point * (special - '0' + 1));
      return(point * ((special - '0') + 1));
    }
}

int		get_score_top_to_bottom(t_game *game, char *word, int cp_y_wrd_p1, int cp_x_wrd_p1, bool is_new_word)
{
  
}

int		get_score_left_to_right(t_game *game, char *word, int cp_y_wrd_p1, int cp_x_wrd_p1, bool is_new_word)
{
  int		score = 0;
  int		multiplier = 1;
  
  for(int i = 0; word[i] != '\0'; i++)
    {
      score = get_score_from_letter(game, word[i], game->s_board[cp_y_wrd_p1][cp_x_wrd_p1], is_new_word) + score;
      printf("score get score left to right =%d\n", score);
      if(is_new_word == false)
	multiplier = get_multiplier(game->s_board[cp_y_wrd_p1][cp_x_wrd_p1]) + multiplier;
    }
  printf("to return get score =%d\n", score * multiplier);
  return(score * multiplier);
}

void		update_score(t_game *game, char *word, int cp_y_wrd_p1, int cp_x_wrd_p2, bool is_left_to_right, bool is_new_word)
{
  if(is_left_to_right == true)
    {
      game->score[game->playing] = get_score_left_to_right(game, word, cp_y_wrd_p1, cp_x_wrd_p2, is_new_word);
    }
  else
    game->score[game->playing] = get_score_top_to_bottom(game, word, cp_y_wrd_p1, cp_x_wrd_p2, is_new_word);
}

bool		is_bingo(char *word)
{
  
}
