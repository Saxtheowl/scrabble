#include "../include/scrabble.h"

// Letter and word premiums count only on the turn in which they are played. On later turns, letters already played on premium squares count at face value.

/*Use a score pad or piece of paper to keep a tally of each player's score, entering it after each turn. The score value of each letter is indicated by a number at the bottom of the tile. The score value of a blank is zero.
#2
The score for each turn is the sum of the letter values in each word(s) formed or modified on that turn, plus the additional points obtained from placing letters on Premium Squares.
#3
Premium Letter Squares: A light blue square doubles the score of a letter placed on it; a dark blue square triples the letter score.
#4
Premium Word Squares: The score for an entire word is doubled when one of its letters is placed on a pink square: it is tripled when one of its letters is placed on a red square. Include premiums for double or triple letter values, if any, before doubling or tripling the word score. If a word is formed that covers two premium word squares, the score is doubled and then re-doubled (4 times the letter count), or tripled and then re-tripled (9 times the letter count). NOTE: the center square is a pink square, which doubles the score for the first word.
#5
Letter and word premiums count only on the turn in which they are played. On later turns, letters already played on premium squares count at face value.
#6
When a blank tile is played on a pink or red square, the value of the word is doubled or tripled, even though the blank itself has no score value.
#7
When two or more words are formed in the same play, each is scored. The common letter is counted (with full premium value, if any) for each word. (See Turns 3, 4 and 5 in the Scoring Examples section.)
#8
BINGO! If you play seven tiles on a turn, it's a Bingo. You score a premium of 50 points after totaling your score for the turn.
#9
Unplayed Letters: When the game ends, each player's score is reduced by the sum of his or her unplayed letters. In addition, if a player has used all of his or her letters, the sum of the other players' unplayed letters is added to that player's score.
#10
The player with the highest final score wins the game. In case of a tie, the player with the highest score before adding or deducting unplayed letters wins.*/

// standard 1, 2 = letter 3, 4 = word
// super 1, 2, 3 = letter 4, 5, 6 = word

int		get_multiplier(t_game *, char);
int		get_score_from_letter(t_game *, char, char, bool);
int		get_special_point(t_game *, int, int);
bool		get_bingo(char *);
int		get_score(t_game *, char *, bool, int);


int		get_multiplier(t_game *game, char symbol)
{
  printf("symbol = %c\n", symbol);
  if (symbol > game->symbol_max_letter && symbol <= game->symbol_max_word)
    return ((symbol - '0') - (game->symbol_max_letter - '0') +1);
  return (0);
}

int		get_score_from_letter(t_game *game, char c, char symbol, bool is_new_word)
{
  int		i = get_number_from_letter(c);
  int		point = game->letters_point[i];

  if (is_new_word == true)// wrong to fix
    {
      return (point);
    }
  else if (symbol > '0' && symbol <= game->symbol_max_letter)
    {
      return (point * ((symbol - '0') + 1));
    }
  return (point);
}

int		get_special_point(t_game *game, int score, int special_pos)
{
  int		multiplier;
  int		i = get_number_from_letter(game->word_test[special_pos]);
  int		point = game->letters_point[i];

  if (game->road_word[special_pos] > '0' && game->road_word[special_pos] <= game->symbol_max_letter)
    {
      return ((point * (game->road_word[special_pos] - '0')));
    }
  else if (game->road_word[special_pos] >= game->symbol_max_letter && game->road_word[special_pos] <= game->symbol_max_word)
    {
      multiplier = (game->road_word[special_pos] - '0') - (game->symbol_max_letter - '0');
      score = score * multiplier;
      return (score);
    }
  return (0);
}

bool		get_bingo(char *word)
{
  int		lenght = 0;
  
  for (int i = 0; word[i]; i++)
    {
      if(!(is_char(word[i])))
	lenght++;
    }
  if (lenght == 7)
    return (true);
  else
    return (false);
}

int		get_score(t_game *game, char *word, bool is_new_word, int special_pos)
{
  int		multiplier = 0;
  int		score = 0;

  for (int i = 0; word[i] != '\0'; i++)
    {
      score = get_score_from_letter(game, word[i], game->road_word[i], is_new_word) + score;
      if (is_new_word == false)
	{
	  multiplier = get_multiplier(game, game->road_word[i]) + multiplier;
	}
      printf("multiplier =%d\n", multiplier);
    }
  if(multiplier > 1)
    score = score * multiplier;
  else if(is_new_word == true)
    score = score + get_special_point(game, score, special_pos);
  if (is_new_word == false && get_bingo(game->road_word) == true)
    {
      printf(" for word=%s, point to return =%d\n", word, score);
      return (score + 50);
    }
  printf(" for word=%s, point to return =%d\n", word, score);
  return (score);
}
