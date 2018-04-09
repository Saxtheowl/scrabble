#define _GNU_SOURCE

#include "../include/scrabble.h"


bool		is_syntax_letter_valid(t_game *, char *);
void		get_proper_coord_word(t_game *, char *, bool, int);
bool		is_syntax_number_valid(t_game *, char *, bool);
bool		is_valid_syntax(t_game *, char *, char *);
void		setup_connections_left_to_right(t_game *);
void		setup_connections_top_to_bottom(t_game *);
bool		is_side_left_and_right_empty(t_game *);
bool		is_side_top_and_bottom_empty(t_game *);
bool		is_not_overwritting(t_game *);
bool		is_connected_to_a_letter(t_game *);
bool		is_valid_first_turn(t_game *, char *);
bool		is_lenght_valid(t_game *);
bool		is_direction_valid(t_game *);
bool		search_new_connections_up_or_down(t_game *, int, bool, int);
bool		is_new_connections_down_valid(t_game *, int);
bool		is_new_connections_left_to_right_valid(t_game *);
bool		search_new_connections_left_or_right(t_game *, int, bool, int);
bool		is_new_connections_top_to_bottom_valid(t_game *);
bool		is_valid_position(t_game *);
bool		is_valid_new_words(t_game *);
bool		is_valid_word(t_game *);
bool		is_joker_in_rack(t_game *);
bool		is_letters_in_rack(t_game *);

bool		is_syntax_letter_valid(t_game *game, char *pos)
{
  char		max_letter;
  
  if (game->is_super_mod == true)
    max_letter = 'U';
  else
    max_letter = 'O';
  if (pos[0] >= 'A' && pos[0] <= max_letter)
    return (true);
#ifdef DEBUG_FLAG
  printf("is_syntax_letter_valid false\n");
#endif
  return (false);
}

void		get_proper_coord_word(t_game *game, char *pos, bool is_pos1, int dat_number)
{
  if (is_pos1 == true)
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
  while (pos[i] != '\0' && pos[i] != '\n' && pos[i] >= '0' && is_num_char(pos[i]))
    i++;
  if (i == 2)
    dat_number = pos[1] - '0';
  else if (i == 3)
    {
      tmp_pos[0] = pos[1];
      tmp_pos[1] = pos[2];
      tmp_pos[2] = '\0';
      dat_number = atoi(tmp_pos);
    }
  if (dat_number <= game->size_board)
    {
      get_proper_coord_word(game, pos, is_pos1, dat_number);
      if (pos[1] >= '1') // last test but there is still more
	return (true);
    }
#ifdef DEBUG_FLAG
  printf("is_syntax_number_valid false\n");
#endif
  return (false);
}

bool		is_valid_syntax(t_game *game, char *pos1, char *pos2)
{
  if (is_syntax_letter_valid(game, pos1) &&
      is_syntax_number_valid(game, pos1, 1) &&
      is_syntax_letter_valid(game, pos2) &&
      is_syntax_number_valid(game, pos2, 0))
    {
      return (true);
    }
#ifdef DEBUG_FLAG
  printf("is_valid_syntax false\n");
#endif
  return (false);
}

void		setup_connections_left_to_right(t_game *game)
{
  int		tmp_pos;
  int		i = 0;

  tmp_pos = game->x_wrd_p1;
  while (tmp_pos <= game->x_wrd_p2)
    {
      game->road_word[i] = game->board[game->y_wrd_p1][tmp_pos];
      game->board[game->y_wrd_p1][tmp_pos] = game->word_test[i];
      i++;
      tmp_pos++;
    }
  game->is_word_put = true;
  game->road_word[i] = '\0';
  game->word_test[i] = '\0';
}

void		setup_connections_top_to_bottom(t_game *game)
{
  int		tmp_pos;
  int		i = 0;

  tmp_pos = game->y_wrd_p1;
  while (tmp_pos <= game->y_wrd_p2)
    {
      game->road_word[i] = game->board[tmp_pos][game->x_wrd_p1];
      game->board[tmp_pos][game->x_wrd_p1] = game->word_test[i];
      i++;
      tmp_pos++;
    }
  game->road_word[i] = '\0';
  game->word_test[i] = '\0';
  game->is_word_put = true;
}

bool		is_side_left_and_right_empty(t_game *game)
{
  printf("start empty module\n");
  char tmp_pos1 = 0; //= game->board[game->y_wrd_p1][game->x_wrd_p1 - 1];
  char tmp_pos2 = 0; //= game->board[game->y_wrd_p1][game->x_wrd_p2 + 1];
  printf(" tmp1 =%c\n", tmp_pos1);
  printf(" tmp2 =%c\n", tmp_pos2);
  if(game->x_wrd_p1 < game->size_board)
    tmp_pos2 = game->board[game->y_wrd_p1][game->x_wrd_p2 + 1];
  if(game->x_wrd_p2 > 0)
    tmp_pos1 = game->board[game->y_wrd_p1][game->x_wrd_p1 - 1];
  printf(" tmp1 =%c\n", tmp_pos1);
  printf(" tmp2 =%c\n", tmp_pos2);
  if((game->x_wrd_p1 == 0 && is_char(tmp_pos2) == false) ||
     (game->x_wrd_p2 == game->size_board && is_char(tmp_pos1) == false) ||
     ((game->x_wrd_p1 > 0 && game->x_wrd_p2 < game->size_board) && is_char(tmp_pos1) == false && is_char(tmp_pos2) == false))
    {
      printf("end empty module\n");
      return(true);
    }
#ifdef DEBUG_FLAG
  printf("is_side_left_and_right_empty false\n");
#endif
  return(false);
}

bool		is_side_top_and_bottom_empty(t_game *game)
{
printf("start empty module\n");
  char tmp_pos1 = 0; //= game->board[game->y_wrd_p1][game->y_wrd_p1 - 1];
  char tmp_pos2 = 0; //= game->board[game->y_wrd_p1][game->y_wrd_p2 + 1];
  printf(" tmp1 =%c\n", tmp_pos1);
  printf(" tmp2 =%c\n", tmp_pos2);
  if(game->y_wrd_p1 < game->size_board)
    tmp_pos2 = game->board[game->y_wrd_p1 + 1][game->x_wrd_p1];
  if(game->y_wrd_p2 > 0)
    tmp_pos1 = game->board[game->y_wrd_p2 - 1][game->x_wrd_p1];
  printf(" tmp1 =%c\n", tmp_pos1);
  printf(" tmp2 =%c\n", tmp_pos2);
  if((game->y_wrd_p1 == 0 && is_char(tmp_pos2) == false) ||
     (game->y_wrd_p2 == game->size_board && is_char(tmp_pos1) == false) ||
     ((game->y_wrd_p1 > 0 && game->y_wrd_p2 < game->size_board) && is_char(tmp_pos1) == false && is_char(tmp_pos2) == false))
    {
      printf("end empty module\n");
      return(true);
    }
#ifdef DEBUG_FLAG
  printf("is_side_left_and_right_empty false\n");
#endif
  return(false);  
}

bool		is_not_overwritting(t_game *game)
{
  for (unsigned int i = 0; i < strlen(game->word_test); i++)
    {
      if ((is_char(game->road_word[i]) && is_char(game->word_test[i])) &&
	 (game->road_word[i] != game->word_test[i]))
	{
#ifdef DEBUG_FLAG
	  printf("is_not_overwritting false\n");
#endif
	  return (false);
	}
    }
  return (true);
}

bool		is_connected_to_a_letter(t_game *game)
{
  bool		one_char = false;
  bool		one_empty = false;

  if (game->is_first_turn == false)
    {
      for (int i = 0; game->road_word[i] != '\0' ; i++)
	{
	  if (is_char(game->road_word[i]))
	    one_char = true;
	  if (!(is_char(game->road_word[i])))
	    one_empty = true;
	}
      if (one_char == true && one_empty == true)
	return (true);
      {
#ifdef DEBUG_FLAG
	printf("is_connected_to_a_letter false\n");
#endif
	return (false);
      }
    }
  else
    return (true);
}

bool		is_valid_first_turn(t_game *game, char *tmp_retired_letters)
{
  if (game->is_first_turn == true)
    {
      if (game->is_letter_middle == true) // UGLY
	{
	  game->is_first_turn = false;
	  return (true);
	}
      else
	{
	  put_letters_back_in_rack(game, tmp_retired_letters);
#ifdef DEBUG_FLAG
	  printf("is_valid_first_turn false\n");
#endif
	  return (false);
	}
    }
  return (true);    
}

bool		is_lenght_valid(t_game *game)
{
  unsigned int road_word_lenght = 0;

  if (game->is_left_to_right == true)
    road_word_lenght = game->x_wrd_p2 - game->x_wrd_p1;
  else
    road_word_lenght = game->y_wrd_p2 - game->y_wrd_p1;
  if (road_word_lenght == strlen(game->word_test) - 1)
    return (true);
#ifdef DEBUG_FLAG
  printf("is_lenght_valid false\n");
#endif
  return (false);
}

bool		is_direction_valid(t_game *game)
{
  if ((game->y_wrd_p1 == game->y_wrd_p2 )
     && (game->x_wrd_p1 < game->x_wrd_p2))
    {
      game->is_left_to_right = true;
      return (true);
    }
  else if ((game->x_wrd_p1 == game->x_wrd_p2 )
     && (game->y_wrd_p1 < game->y_wrd_p2))
    {
      game->is_left_to_right = false; // this one or the other, ugly ?
      return (true);
    }
  
#ifdef DEBUG_FLAG
  printf("is_direction_valid false\n");
#endif
  return (false);
}

bool		search_new_connections_up_or_down(t_game *game, int x_cp, bool flag_up, int special_pos)
{
  char		*tmp_new_word;
  int		y_cp = game->y_wrd_p1;
  int		i = 0;
  
  tmp_new_word = xmalloc(sizeof(*tmp_new_word) * game->size_board);
  if (flag_up == true)
    {
      while (y_cp >= 0 && is_char(game->board[y_cp][x_cp]))
	y_cp--;
      y_cp++; // UGLY, TO FIX
    }
  while (y_cp < game->size_board && is_char(game->board[y_cp][x_cp]))
    {
      tmp_new_word[i] = game->board[y_cp][x_cp];
      y_cp++;
      i++;
    }
  tmp_new_word[i] = '\0'; // useless ?
  if (is_valid_word(game))
    {
      game->new_word_pot = game->new_word_pot + get_score(game, tmp_new_word, 1, special_pos);
      game->is_side_word = true;
      return (true);
    }
  else
#ifdef DEBUG_FLAG
  printf("search_new_connections_up_or_down false\n");
#endif
    return (false);
}

bool		is_new_connections_down_valid(t_game *game, int x_cp)
{
  char		*tmp_new_word = NULL;
  int		y_cp = game->y_wrd_p1;
  int		i = 0;

  while (y_cp < game->size_board && is_char(game->board[y_cp][x_cp]))
    {
      tmp_new_word[i] = game->board[y_cp][x_cp];
      y_cp++;
      i++;
    }
  if (is_valid_word(game))
    return (true);
  else
    {
#ifdef DEBUG_FLAG
      printf("is_new_connections_down_valid false\n");
#endif
      return (false);
    }
}

bool		is_new_connections_left_to_right_valid(t_game *game) // UPDATE TMP PRE SCORE ?
{
  int		x_cp = game->x_wrd_p1;
  int		y_cp_up = game->y_wrd_p1 - 1;
  int		y_cp_down = game->y_wrd_p1 + 1;
  int		i = 0;

  while (x_cp <= game->x_wrd_p2)
    {
      if (!(is_char(game->road_word[i])))
	{
	  if ((y_cp_up >= 0 && y_cp_down <= game->size_board - 1) && is_char(game->board[y_cp_up][x_cp]))
	    {
	      if (!(search_new_connections_up_or_down(game, x_cp, 1, i)))
		{
#ifdef DEBUG_FLAG
		  printf("is_new_connections_left_to_right false\n");
#endif
		  return(false);
		}
	    }	  
	  else if (y_cp_down <= game->size_board - 1&& is_char(game->board[y_cp_down][x_cp]))
	    {
	      if (!(search_new_connections_up_or_down(game, x_cp, 0, i)))
#ifdef DEBUG_FLAG
  printf("is_new_connections_left_to_right false\n");
#endif
		return (false);
	    } 
	}
      i++;
      x_cp++;
    }
  return (true);
}

bool		search_new_connections_left_or_right(t_game *game, int y_cp, bool flag_up, int special_pos)
{
  char		*tmp_new_word;
  int		x_cp = game->x_wrd_p1;
  int		i = 0;

  tmp_new_word = xmalloc(sizeof(*tmp_new_word) * game->size_board); // LUL
  if (flag_up == true)
    {
      while (x_cp > 0 && is_char(game->board[y_cp][x_cp]))
	x_cp--;
      x_cp++; // TO FIX
    }
  while (x_cp < game->size_board && is_char(game->board[y_cp][x_cp]))
    {
      tmp_new_word[i] = game->board[y_cp][x_cp];
      x_cp++;
      i++;
    }
  tmp_new_word[i] = '\0';
  if (is_valid_word(game))
    {
      game->new_word_pot = game->new_word_pot + get_score(game, tmp_new_word, 1, special_pos);
      game->is_side_word = true;
      return (true);
    }
  else
    {
#ifdef DEBUG_FLAG
      printf("search_new_connections_left_or_right false\n");
#endif
    }
    return (false);
}

  
bool		is_new_connections_top_to_bottom_valid(t_game *game)
{
  int		y_cp = game->y_wrd_p1;
  int		x_cp_left = game->x_wrd_p1 - 1;
  int		x_cp_right = game->x_wrd_p1 + 1;
  int		i = 0;

  while (y_cp <= game->y_wrd_p2)
    {
      if (!(is_char(game->road_word[i])))
	{
	  if (x_cp_left >= 0 && is_char(game->board[y_cp][x_cp_left]))
	    {
	      if (!(search_new_connections_left_or_right(game, y_cp, 1, i)))
		{
#ifdef DEBUG_FLAG
		  printf("is_new_connections_top_to_bottom false\n");
#endif
		  
		  return (false);
		}
	    }	  
	  else if (is_char(game->board[y_cp][x_cp_right]))
	    {
	      if (!(search_new_connections_left_or_right(game, y_cp, 0, i)))
		{
#ifdef DEBUG_FLAG
		  printf("is_new_connections_top_to_bottom false\n");
#endif
		  return (false);
		}
	    } 
	}
      i++;
      y_cp++;
    }  
  return (true);
}

bool		is_valid_position(t_game *game) // CHECK NUMBER CHAR INPUT EQUAL THE LENGHT OF THE GIVEN POSITION ?
{  
  if (is_direction_valid(game) && is_lenght_valid(game))
    {
      if (game->is_left_to_right == true && is_side_left_and_right_empty(game) == true)
	{
	  setup_connections_left_to_right(game);
	  return (true);
	}
      else if (game->is_left_to_right == false && is_side_top_and_bottom_empty(game) == true)
	{
	  setup_connections_top_to_bottom(game);
	  return (true);
	}
    }
#ifdef DEBUG_FLAG
  printf("is_valid_position false\n");
#endif
  return (false);
}

bool		is_valid_new_words(t_game *game)
{
  if ((game->is_left_to_right == true && is_new_connections_left_to_right_valid(game)) ||
      (game->is_left_to_right == false && is_new_connections_top_to_bottom_valid(game)))
    {
      if (is_char(game->board[(game->size_board / 2)][(game->size_board / 2)]))
	game->is_letter_middle = true;
      if (is_not_overwritting(game) && (is_connected_to_a_letter(game) || game->is_side_word == true))
	return (true);
    }
  remove_word(game);
#ifdef DEBUG_FLAG
  printf("is_valid_new_words false\n");
#endif
  return (false);
}

bool		is_valid_word(t_game *game)
{
  return(true);
  char		*tmp_word = strdup(game->word_test);

  tmp_word = to_upper(tmp_word);
  for (int i = 0; i < game->max_words_dict; i++)
    {
      if (strcmp_dictionnary(tmp_word, game->dictionnary[i]) == true)
      return (true);
    }
#ifdef DEBUG_FLAG
  printf("is_valid_words false\n");
#endif
  return (false);
}

bool		is_there_players(t_game *game)
{
  return(true);
#ifdef DEBUG_FLAG
  printf("is_there_players false\n");
#endif
  return(false);
}

bool		is_new_word_still_possible(t_game *game)
{
}

bool		is_joker_in_rack(t_game *game)
{
  for (int i = 0; i < MAX_LETTERS_RACK; i++)
    {
      if (game->racks[game->playing][i] == '?')
	return (true);
    }
#ifdef DEBUG_FLAG
  printf("is_joker_in_rack false\n");
#endif
  return (false);
}

bool		is_letters_in_rack(t_game *game) // CODE HORROR
{
  char		*tmp_retired_letters;
  int		i = 0;
  int		f = 0;

  tmp_retired_letters = xmalloc(sizeof(*tmp_retired_letters) * MAX_LETTERS_RACK);
  while (game->road_word[i] != '\0')
    {
      if (!(is_char(game->road_word[i])))
	{
	  if (remove_letter_in_rack(game, game->word_test[i]) == true)
	    {
	      tmp_retired_letters[f] = game->word_test[i];
	      f++;
	    }
	  else
	    {
	      put_letters_back_in_rack(game, tmp_retired_letters);
#ifdef DEBUG_FLAG
  printf("is_letters_in_rack false\n");
#endif
  return(false);
	    }
	}
      i++;
    }
  if (is_valid_first_turn(game, tmp_retired_letters))
    return (true);
  else
    return (false);
}
