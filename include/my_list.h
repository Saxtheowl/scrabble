#ifndef         __MY_LIST_H__
# define         __MY_LIST_H__

#include "my.h"

//#define MAX_PLAYERS 4

//#define BOARD_SIZE_X 15
//#define BOARD_SIZE_Y 15


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
  
  char			**board;


  /* fixed value */
  char			*alphabet;
  int			**nb_ltr_en;
  int			**pt_ltr_en;
  
  
}			t_game;

#endif /* __MY_LIST_H__ */
