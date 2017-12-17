#include "../include/scrabble.h"

// Letter and word premiums count only on the turn in which they are played. On later turns, letters already played on premium squares count at face value.

// standard 1, 2 = letter 3, 4 = word
// super 1, 2, 3 = letter 4, 5,6 = word

int		get_multiplier(t_game *game, char symbol)
{
  if(symbol >= game->symbol_max_letter && symbol <= game->symbol_max_word)
    {
      printf("multiplier =%d\n", (symbol - '0') - (game->symbol_max_letter - '0'));
      return((symbol - '0') - (game->symbol_max_letter - '0'));
    }
  printf("get multiplier return 0\n");
  return(0);
}

int		get_score_from_letter(t_game *game, char c, char symbol, bool is_new_word)
{
  int		i = get_number_from_letter(c);
  int		point = game->letters_point[i];
  int		tmp;

  if(is_new_word == true)// wrong to fix
    {
      printf("1get score from letter to return =%d\n", point);
      return(point);
    }
  else if(symbol > '0' && symbol <= game->symbol_max_letter)
    {
      printf("2get score from letter to return =%d\n", (point * ((symbol - '0') + 1)));
      return(point * ((symbol - '0') + 1));
    }
  printf("3get score from letter to return =%d\n", point);
  return(point);
}

int		get_special_point(t_game *game, int score, int special_pos)
{
  int		multiplier = 1;
  int		i = get_number_from_letter(game->word_test[special_pos]);
  int		point = game->letters_point[i];

  if(game->road_word[special_pos] > '0' && game->road_word[special_pos] <= game->symbol_max_letter)
    {
      printf("special point letter=%d\n", ((point * ((game->road_word[special_pos] - '0') + 1))));
      return((point * (game->road_word[special_pos] - '0')));
    }
  else if(game->road_word[special_pos] >= game->symbol_max_letter && game->road_word[special_pos] <= game->symbol_max_word)
      {
	printf("special point word=%d\n", (score * ((game->road_word[special_pos] - '0') - (game->symbol_max_letter))));
	return(score * ((game->road_word[special_pos] - '0') - (game->symbol_max_letter)));
      }
  return(0);
}

bool		get_bingo(char *word)
{
  if(strlen(word) == 7)
    {
      printf("BINGO !\n");
      return(true);
    }
    return(false);
}

int		get_score(t_game *game, char *word, bool is_new_word, int special_pos)
{
  int		multiplier = 1;
  int		score = 0;

  printf("word to score = %s\n", word);
  for(int i = 0; word[i] != '\0'; i++)
    {
      score = get_score_from_letter(game, word[i], game->road_word[i], is_new_word) + score;
      printf("0score to return =%d\n", score);
      if(is_new_word == false)
	multiplier = get_multiplier(game, game->road_word[i]) + multiplier;
    }
  if(is_new_word == false)
    score = score * multiplier;
  else
    {
      score = score + get_special_point(game, score, special_pos);
      printf("1score to return =%d\n", score);
    }
  if(get_bingo(word) == true)
    return(score + 50);
  printf("multiplier = %d\n", multiplier);
  printf("2score to return =%d\n", score);
  return(score);
}
