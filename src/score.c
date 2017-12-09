#include "../include/scrabble.h"

void		update_score(t_game *game, char *word, int pos1, int pos2, bool is_left_to_right, bool is_new_word)
{
  
}

int		get_score_left_to_right(t_game *game, char *word, int pos1, int pos2, bool is_new_word)
{
  int		score = 0;
  int		multiplier = 0;
  
  for(int i = 0; word[i] != '\0'; i++)
    {
      multiplier = get_multiplier(game->s_board[pos1][pos2]) + multiplier;
    }
  return(score * multiplier);
}

int		get_score_top_to_bottom(t_game *game, char *word, int pos1, int pos2, bool is_new_word)
{
  
}

int		get_score_from_letter(t_game *game, char c, char special, bool is_new_word)
{
  int		i = get_number_from_letter(c);
  int		point = game->letters_point[i];

  if(is_new_word == true)
    return(point);
  if(special > '0' && special < '4')
    return(point * (atoi(special) + 1));    
}

int		get_multiplier(char special)
{

  int		tmp;
  if(special > '3' && special < '7')
    {
      tmp = atoi(special);
      return(tmp);
    }
}

bool		is_bingo(char *word)
{
  
}
