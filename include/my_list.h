#ifndef         __MY_LIST_H__
# define         __MY_LIST_H__

#include "my.h"

#define MAX_PLAYERS 4

#define BOARD_SIZE_X 15
#define BOARD_SIZE_Y 15


typedef struct		s_cnfg
{
  
}			t_cnfg;

typedef struct		s_game
{
  bool			is_skip_menu;
  int			language;
  int			amount_players;
  int			players_type[MAX_PLAYERS];

  char			board[BOARD_SIZE_X][BOARD_SIZE_Y];
}			t_game;

#endif /* __MY_LIST_H__ */
