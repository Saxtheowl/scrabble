#include "../include/scrabble.h"

void		put_word(t_game *);
void		remove_word(t_game *);

/* WRITE AND REMOVE STUFF ON THE BOARD */

void		put_word(t_game *game)
{
  int		tmp_pos;
  int		i = 0;

  if (game->is_left_to_right == true)
    {
      tmp_pos = game->x_wrd_p1;
      while (tmp_pos <= game->x_wrd_p2)
	{
	  game->board[game->y_wrd_p1][tmp_pos] = game->word_test[i];
	  i++;
	  tmp_pos++;
	}
    }
  else
    {
      tmp_pos = game->y_wrd_p1;
      while (tmp_pos <= game->y_wrd_p2)
	{
	  game->board[tmp_pos][game->x_wrd_p1] = game->word_test[i];
	  i++;
	  tmp_pos++;
	}
    }
  game->is_word_put = true;
}

void		remove_word(t_game *game)
{
  int		tmp_pos;
  int		i = 0;

  if (game->is_left_to_right == true)
    {
      tmp_pos = game->x_wrd_p1;
      while (tmp_pos <= game->x_wrd_p2)
	{
	  game->board[game->y_wrd_p1][tmp_pos] = game->road_word[i];
	  i++;
	  tmp_pos++;
	}
    }
  else
    {
      tmp_pos = game->y_wrd_p1;
      while (tmp_pos <= game->y_wrd_p2)
	{
	  game->board[tmp_pos][game->x_wrd_p1] = game->road_word[i];
	  i++;
	  tmp_pos++;
	}
    }
}
