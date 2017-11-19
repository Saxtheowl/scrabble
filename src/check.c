#include "../include/scrabble.h"
#include <string.h>

bool		test_cant_play(t_game *);
bool		is_valid_word(t_game *, char *);

bool		test_cant_play(t_game *game)
{
  return(false);
}

bool		is_syntax_letter_valid(t_game *game, char *pos)
{
  char		max_letter;

  
  if(game->is_super_mod == true)
    max_letter = 'U';
  else
    max_letter = 'O';
  if(pos[0] >= 'A' && pos[0] <= max_letter)
    return(true);
  return(false);
}

void		get_proper_coord_word(t_game *game, char *pos, bool is_pos1, int dat_number)
{
  printf("pos =%s\n", pos); 
  printf("is_pos1 = %d\n", is_pos1);
  printf("dat_number = %d\n", dat_number);
  if(is_pos1 == true)
    {
      game->x_wrd_p1 = get_number_from_letter(pos[0]);
      game->y_wrd_p1 = dat_number -1;
    }
  else
    {
      game->x_wrd_p2 = get_number_from_letter(pos[0]);
      game->y_wrd_p2 = dat_number -1;
    }
}

bool		is_syntax_number_valid(t_game *game, char *pos, bool is_pos1)
{
  char		*tmp_pos;
  int		dat_number;
  int		i = 1;

  tmp_pos = malloc(sizeof(tmp_pos) * 3);
  while(pos[i] != '\0' && pos[i] != '\n' && pos[i] >= '0' && is_num_char(pos[i]))
    i++;
  if(i == 2)
    dat_number = pos[1] - '0';
  else if(i == 3)
    {
      tmp_pos[0] = pos[1];
      tmp_pos[1] = pos[2];
      tmp_pos[2] = '\0';
      //      printf("tmp pos =%s\n", tmp_pos);
      dat_number = atoi(tmp_pos);
    }
  //  printf("ok2\n");
  if(dat_number <= game->size_board)
    {
      get_proper_coord_word(game, pos, is_pos1, dat_number);
      if(pos[1] >= '1') // last test but there is still more
	return(true);
    }
  return(false);
}

bool		is_valid_syntax(t_game *game, char *pos1, char *pos2)
{
  printf("is_valid_syntax pos =%s\n", pos1);
  if(is_syntax_letter_valid(game, pos1)
     && is_syntax_number_valid(game, pos1, 1)
     && is_syntax_letter_valid(game, pos2)
     && is_syntax_number_valid(game, pos2, 0)
     )
    {
      printf("y word pos1:%d\n", game->y_wrd_p1);
      printf("y word pos2:%d\n", game->y_wrd_p2);
      printf("x word pos1:%d\n", game->x_wrd_p1);
      printf("x word pos2:%d\n", game->x_wrd_p2);
      
      printf("syntax valid\n");
      return(true);
    }
  printf("syntax wrong\n");
  return(false);
}

bool		is_left_to_right(t_game *game)
{
  if((game->y_wrd_p1 == game->y_wrd_p2 )
     && (game->x_wrd_p1 < game->x_wrd_p2))
    {
      game->is_left_to_right = true;
      printf("YES RIGHT\n");
      return(true);
    }
  return(false);
}

bool		is_top_to_bottom(t_game *game)
{
  if((game->x_wrd_p1 == game->x_wrd_p2 )
     && (game->y_wrd_p1 < game->y_wrd_p2))
    {
      game->is_left_to_right = false; // this one or the other, ugly ?
      printf("NO RIGHT\n");
      return(true);
    }
  return(false);
}

bool		is_connected(t_game *game) // http://www.word-buff.com/adding-a-tile-to-each-end-of-a-scrabble-word.html WTF ! ?
{
  int		cp_x_wrd_p1 = game->x_wrd_p1;

  printf("START IS CONNECTED\n");
  if(game->is_left_to_right == true)
    {
      printf("IS CONNECTED ENTER\n");
      while(cp_x_wrd_p1 < game->x_wrd_p2)
	{
	  printf("IS CONNECTED++\n");
	  if(is_char(game->board[cp_x_wrd_p1][game->y_wrd_p1]))
	    return(true);
	  cp_x_wrd_p1++;
	}
    }
  return(false);
}

bool		is_valid_position(t_game *game)
{
  /*
  if(is_left_to_right(game) || is_top_to_bottom(game) && is_connected(game) == true)
    {
      game->board[game->x_wrd_p1][game->y_wrd_p1] = '0';
      game->board[game->x_wrd_p2][game->y_wrd_p2] = '1';
      return(true);
      printf("is valid position valid\n");
    }
  printf("is valid position false\n");
  return(false);
  */
  game->board[game->x_wrd_p1][game->y_wrd_p1] = '0';
  game->board[game->x_wrd_p2][game->y_wrd_p2] = '1';

}

bool		is_valid_word(t_game *game, char *word)
{
  printf("is_valid_word word to test =%s\n", word);
  for(int i = 0; i < game->max_words_dict; i++)
    {
      if(strcmp_dictionnary(word, game->dictionnary[i]) == true)
	{
	  printf(" is valid true\n");
	  return(true);
	}
    }
  printf(" is valid false\n");
  return(false);
}

bool		is_in_rack(t_game *game, char *word, int x, int y)
{
  char		word_cp[7];

  strncpy(word_cp, word, strlen(word));
  printf("word = %s\n", word);
  printf("word cp= %s\n", word_cp);
  
  // WASTE
  // WS TESA
  printf(" is in rack false\n");
  return(false);
}
