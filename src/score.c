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

int		get_special_char(t_game *game, int score, char special_new_letter, char special_new_symbol)
{
  int		multiplier = 1;
  int		i = get_number_from_letter(special_new_letter);
  int		letter = game->letters_point[i];
  
  if(special_new_symbol >= game->symbol_max_letter && special_new_symbol <= game->symbol_max_word)
    multiplier = (special_new_symbol - '0') - (game->symbol_max_letter - '0');
  return((letter * multiplier) - letter);
}

int		get_score(t_game *game, char *word, bool is_new_word, char special_new_letter, char special_new_symbol)
{
  int		multiplier = 1;
  int		score = 0 + get_bingo();
  
  for(int i = 0; word[i] != '\0'; i++)
    {
      score = get_score_from_letter(game, word[i], game->road_word[i], is_new_word) + score;
      printf("score before multiplier = %d\n", score);
      if(is_new_word == false)
	multiplier = get_multiplier(game, game->road_word[i]) + multiplier;
    }
  if(is_new_word == 0)
    return(score * multiplier);
  else
    return(score + get_special_char(game, score, special_new_letter, special_new_symbol));
}

int		get_bingo(char *word)
{
  
}
