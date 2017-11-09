#ifndef		__MY_H__
# define       	 __MY_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_list.h"

#define HUMAN 0
#define BOT 1

#ifndef	SUPER_SCRABBLE /* STANDARD SCRABBLE */

#define MAX_PLAYERS 4

#define BOARD_SIZE_X 15
#define BOARD_SIZE_Y 15

#define FILE_BOARD_PATH "board/standard_board"

enum BOARD_SYMBOL_NUMBER
  {
    BOARD_CENTER = 0,
    BOARD_DOUBLE_LETTER = 1,
    BOARD_TRIPLE_LETTER = 2,
    BOARD_DOUBLE_WORD = 3,
    BOARD_TRIPLE_WORD = 4,
  };
  
#define MAX_LETTERS_EN 100

enum NUMBER_LETTERS_EN
  {
    N_EN_A = 9,
    N_EN_B = 2,
    N_EN_C = 2,
    N_EN_D = 4,
    N_EN_E = 12,
    N_EN_F = 2,
    N_EN_G = 3,
    N_EN_H = 2,
    N_EN_I = 9,
    N_EN_J = 1,
    N_EN_K = 1,
    N_EN_L = 4,
    N_EN_M = 2,
    N_EN_N = 6,
    N_EN_O = 8,
    N_EN_P = 2,
    N_EN_Q = 1,
    N_EN_R = 6,
    N_EN_S = 4,
    N_EN_T = 6,
    N_EN_U = 4,
    N_EN_V = 2,
    N_EN_W = 2,
    N_EN_X = 1,
    N_EN_Y = 2,
    N_EN_Z = 1,
    N_EN_JOKER = 2,
  };

enum POINT_LETTERS_EN
  {
    P_EN_A = 1,
    P_EN_B = 3,
    P_EN_C = 3,
    P_EN_D = 2,
    P_EN_E = 1,
    P_EN_F = 4,
    P_EN_G = 2,
    P_EN_H = 4,
    P_EN_I = 1,
    P_EN_J = 8,
    P_EN_K = 5,
    P_EN_L = 1,
    P_EN_M = 3,
    P_EN_N = 1,
    P_EN_O = 1,
    P_EN_P = 3,
    P_EN_Q = 10,
    P_EN_R = 1,
    P_EN_S = 1,
    P_EN_T = 1,
    P_EN_U = 1,
    P_EN_V = 4,
    P_EN_W = 2,
    P_EN_X = 8,
    P_EN_Y = 4,
    P_EN_Z = 10,
    P_EN_JOKER = 0,
  };

enum POINT_LETTERS_FR
  {
    P_FR_A = 0,
  };

enum NUMBER_LETTERS_FR
  {
    N_FR_A = 0,
  };

#else /* SUPER BOARD */

#define MAX_PLAYERS 4

#define BOARD_SIZE_X 21
#define BOARD_SIZE_Y 21

#define FILE_BOARD_PATH "board/super_board"

#define MAX_LETTERS_EN 200

enum BOARD_SYMBOL_NUMBER
  {
    BOARD_CENTER = 0,
    BOARD_DOUBLE_LETTER = 1,
    BOARD_TRIPLE_LETTER = 2,
    BOARD_QUADRUPLE_LETTER = 3,
    BOARD_DOUBLE_WORD = 4,
    BOARD_TRIPLE_WORD = 5,
    BOARD_QUADRUPLE_WORD = 6,
  };


#endif

//#define BOARD_PATH ../board

/* ask_user.c */

char		*put_prompt();

/* game_core.c */

void		start_game(t_game *);

/* init.c */

void		init_game_data(t_game *);
void		init_board(t_game *);

/* menu.c */

void		menu_pre_game(t_game *);


/* config_pre_game.c */

void		config_with_av(t_game *, char **);
void		config_skip_menu(t_game *);
void		select_skip_menu(t_game *);
void		select_language_to_play(t_game *);
void		select_number_of_players(t_game *);
void		select_players_type(t_game *);

/* main.c */

int		main(int, char **);

/* ../util/read_entry.c */

char		*read_entry();
void		xgetline(char **, FILE *, int i);

/* xfunc.c */

void		*xmalloc(int);

#endif /*__MY_H__ */
