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

bool		is_connections_left_to_right_valid(t_game *game)
{
  int		tmp_pos;
  int		i = 0;

  tmp_pos = game->x_wrd_p1;
  while(tmp_pos <= game->x_wrd_p2)
    {
      game->road_word[i] = game->board[game->y_wrd_p1][tmp_pos];
      game->board[game->y_wrd_p1][tmp_pos] = game->word_test[i];
      i++;
      tmp_pos++;
    }
  game->road_word[i] = '\0';
  game->word_test[i] = '\0';
}

bool		is_connections_top_to_bottom_valid(t_game *game)
{
  int		tmp_pos;
  int		i = 0;
  
  tmp_pos = game->y_wrd_p1;
  while(tmp_pos <= game->y_wrd_p2)
    {
      game->road_word[i] = game->board[tmp_pos][game->x_wrd_p1];
      game->board[tmp_pos][game->x_wrd_p1] = game->word_test[i];
      i++;
      tmp_pos++;
    }
      game->road_word[i] = '\0';
      game->word_test[i] = '\0';

}


bool		is_more_left_empty(t_game *game)
{
  int		tmp_pos = game->x_wrd_p1 - 1;

  //  game->board[game->y_wrd_p1][tmp_pos] = 'X';
  if(game->y_wrd_p1 == 0)
    return(true);
   if (game->board[game->y_wrd_p1][tmp_pos] != '.')
     printf("wrong is more left empty\n");
    return(false);
}

bool		is_more_up_empty(t_game *game)
{
  int		tmp_pos = game->y_wrd_p1 - 1;

  //  game->board[game->y_wrd_p1][tmp_pos] = 'X';
  /*  if(game->x_wrd_p1 == 0) USELESS ?
      return(true);*/
   if (game->board[tmp_pos][game->x_wrd_p1] != '.')
     printf("wrong is more up empty\n");
    return(false);

}

bool		is_connected_to_a_letter(t_game *game)
{
  //  setup_connection(game);
  for(int i = 0; game->road_word[i] != '\0' ; i++)
    {
      if(is_char(game->road_word[i]))
	{
	  game->road_word[i] = '\0';
	  game->word_test[i] = '\0';
	  return(true);
	}
    }
  return(false);
}

bool		is_direction_valid(t_game *game)
{
  if((game->y_wrd_p1 == game->y_wrd_p2 )
     && (game->x_wrd_p1 < game->x_wrd_p2))
    {
      game->is_left_to_right = true;
      printf("YES RIGHT TO LEFT\n");
      return(true);
    }
  else if((game->x_wrd_p1 == game->x_wrd_p2 )
     && (game->y_wrd_p1 < game->y_wrd_p2))
    {
      game->is_left_to_right = false; // this one or the other, ugly ?
      printf("NO RIGHT TO LEFT\n");
      return(true);
    }
  return(false);
}

bool		is_valid_position(t_game *game)
{  
  if(is_direction_valid(game))
    {
      if((game->is_left_to_right == true && is_connections_left_to_right_valid(game) == true && is_more_left_empty(game))
	 || (game->is_left_to_right == false &&  is_connections_top_to_bottom_valid(game) == true) && is_more_up_empty(game))
	{
	  if(is_connected_to_a_letter(game))
	    return(true);
	}
    }
      
      /*
      put_temporary_word(game);
      if((is_connections_left_to_right_valid(game) || is_connections_top_to_bottom_valid(game)) && is_connected(game))
	{
	  printf(" valid position TRUE\n");
	  return(true);
	}
    }
  remove_word(game);
  printf("is valid position false\n");
  return(false);*/
}

bool		is_valid_word(t_game *game, char *word)
{
  printf("road word =%s\n", game->road_word);
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

char		*get_letters_to_test(t_game *game, char *word)
{
  
}

bool		is_joker_in_rack(t_game *game)
{
  for(int i = 0; i < MAX_LETTERS_RACK; i++)
    {
      if(game->racks[game->playing][i] = 'j')
	return(true);
    }
  return(false);
}

bool		is_letter_in_rack(t_game *game, char letter)
{
  bool		is_blank_tile_present = false;
  
}

bool		is_letters_in_rack(t_game *game, char *word)
{

  return(false);
}

