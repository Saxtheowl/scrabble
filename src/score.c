#include "../include/scrabble.h"

// Letter and word premiums count only on the turn in which they are played. On later turns, letters already played on premium squares count at face value.

// standard 1, 2 = letter 3, 4 = word
// super 1, 2, 3 = letter 4, 5,6 = word

int		get_multiplier(t_game *game, char symbol)
{
  printf("symbol multiplier =%c\n", symbol);
  if(symbol >= game->symbol_max_letter && symbol <= game->symbol_max_word)
    {
      printf("to return get multiplier =%d\n", ((symbol - '0') - (game->symbol_max_letter - '0')));
      return((symbol - '0') - (game->symbol_max_letter - '0'));
    }
  else
    return(0);
}

int		get_score_from_letter(t_game *game, char c, char symbol, bool is_new_word)
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
  else if(symbol > '0' && symbol <= game->symbol_max_letter)
    {
      printf("to return score from letter =%d\n", (point * ((symbol - '0') + 1)));
      printf("symbol == %d\n", ((symbol - '0') + 1));
      return(point * ((symbol - '0') + 1));
    }
  return(point);
}

int		get_special_point(t_game *game, int score, int special_pos)
{
  int		multiplier = 1;
  int		i = get_number_from_letter(game->word_test[special_pos]);
  int		point = game->letters_point[i];

  printf("special char start\n");
  printf("special_pos =%d\n", special_pos);
  printf("i =%d\n", i);
  printf("special new letter =%c\n", game->word_test[special_pos]);
  printf("special new symbol =%c\n", game->road_word[special_pos]);
  printf("letter point =%d\n", point);
  if(game->road_word[special_pos] > '0' && game->road_word[special_pos] <= game->symbol_max_letter)
    {
      
      printf("special multiplier =%d\n", multiplier);
      printf("special char char point to return =%d\n", (point * ((game->road_word[special_pos] - '0'))));
      return((point * ((game->road_word[special_pos] - '0') + 1)));
    }
  else if(game->road_word[special_pos] >= game->symbol_max_letter && game->road_word[special_pos] <= game->symbol_max_word)
      {
	printf("special score multiply word to return=%d\n", score * ((game->road_word[special_pos] - '0') - (game->symbol_max_letter)));
	return(score * ((game->road_word[special_pos] - '0') - (game->symbol_max_letter)));
      }
  printf("wut error special point\n");
}

bool		get_bingo(char *word)
{
  if(strlen(word) == 7)
    return(true);
    return(false);
}

int		get_score(t_game *game, char *word, bool is_new_word, int special_pos)
{
  int		multiplier = 1;
  int		score = 0;

  printf("word size =%d\n", strlen(word));
  for(int i = 0; word[i] != '\0'; i++)
    {
      score = get_score_from_letter(game, word[i], game->road_word[i], is_new_word) + score;
      printf("score before multiplier = %d\n", score);
      if(is_new_word == false)
	multiplier = get_multiplier(game, game->road_word[i]) + multiplier;
    }
  if(is_new_word == 0)
    score = score * multiplier;
  else
    score = score + get_special_point(game, score, special_pos);
  if(get_bingo(word) == true)
    return(score + 50);
  return(score);
}
