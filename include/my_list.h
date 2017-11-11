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

  int			max_letters;
  char			*letters_path;
  
  char			*alphabet;

  char			*nb_ltr_en;
  int			*pt_ltr_en;
  
}			t_game;

#endif /* __MY_LIST_H__ */
