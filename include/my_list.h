#ifndef         __MY_LIST_H__
# define         __MY_LIST_H__

#include "my.h"



typedef struct		s_cnfg
{
  
}			t_cnfg;

typedef struct		s_game
{
  /* pre config */
  
  bool			is_skip_menu;
  bool			is_super_mod;
  bool			is_duplicate_mod;
  int			language;
  int			amount_players;
  int			*players_type;
  /* fixed value */
  char			**board;

  char			*board_path;
  int			size_board;

  char			*letters_list_path;
  char			*letters_points_path;
  int			max_letters;
  char			*alphabet;

  char			*letters_list;
  int			*letters_point;
  
}			t_game;

#endif /* __MY_LIST_H__ */
