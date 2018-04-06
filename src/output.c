#include "../include/scrabble.h"

void		print_board(t_game *);
void		color_print_inner_board(char *, int);
void		print_players_info(t_game *);

void		print_board(t_game *game)
{
  int		nb_lines = 1;
  char		*alphabet_tmp;

  if (game->is_super_mod == true)
    alphabet_tmp = "  ABCDEFGHIJKLMNOPQRSTU \n";
  else
    alphabet_tmp = "  ABCDEFGHIJKLMNO \n";
  printf(ANSI_COLOR_RED"%s"ANSI_COLOR_RESET, alphabet_tmp);
  for (int i = 0; i < game->size_board; i++)
    {
      if (nb_lines < 10)
	printf(" ");
      printf(ANSI_COLOR_RED"%d"ANSI_COLOR_RESET, nb_lines);
      color_print_inner_board(game->board[i], game->size_board);
      //printf("%.*s", 15, game->board[i]);
      printf(ANSI_COLOR_RED"%d\n"ANSI_COLOR_RESET, nb_lines);
      nb_lines++;
    }
  printf(ANSI_COLOR_RED"%s"ANSI_COLOR_RESET, alphabet_tmp);
}

void		color_print_inner_board(char *line, int nb_to_copy)
{
  for (int i = 0; i < nb_to_copy; i++)
    {
      if (is_num_char(line[i]))
	printf(ANSI_COLOR_BLUE"%c"ANSI_COLOR_RESET, line[i]);
      else
	printf("%c", line[i]);
    }
}

void		print_players_info(t_game *game)
{
  for (int i = 0; i < game->amount_players; i++)
    {
      printf("PLAYER %d score:%d rack:", i, game->score[i]);
      if (i == game->playing)
	printf("%s\n", game->racks[i]);
      else
	{
	  for (int y = 0; game->racks[i][y] != '\0'; y++)
	    {
	      if (game->racks[i][y] != ' ')
		printf("@");
	      else
		printf(" ");
	    }
	  printf("\n");
	}
    }
  printf("letters left: %d\n", game->letters_left);
}
