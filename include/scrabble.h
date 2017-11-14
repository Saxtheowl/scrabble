#ifndef		__SCRABBLE_H__
# define       	 __SCRABBLE_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define HUMAN 0
#define BOT 1

#define NB_LETTERS_ALPHABET 26

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
#define MAX_LETTERS_FR 102

enum LANGUAGE
  {
    ENGLISH = 1,
    FRENCH,
  };

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

#define MAX_LETTERS_FR 102

enum NUMBER_LETTERS_FR
  {
    N_FR_A = 9,
    N_FR_B = 2,
    N_FR_C = 2,
    N_FR_D = 3,
    N_FR_E = 15,
    N_FR_F = 2,
    N_FR_G = 2,
    N_FR_H = 2,
    N_FR_I = 8,
    N_FR_J = 1,
    N_FR_K = 1,
    N_FR_L = 8,
    N_FR_M = 3,
    N_FR_N = 6,
    N_FR_O = 6,
    N_FR_P = 2,
    N_FR_Q = 1,
    N_FR_R = 6,
    N_FR_S = 6,
    N_FR_T = 6,
    N_FR_U = 6,
    N_FR_V = 2,
    N_FR_W = 1,
    N_FR_X = 1,
    N_FR_Y = 1,
    N_FR_Z = 1,
  };

enum POINT_LETTERS_FR
  {
    P_FR_A = 1,
    P_FR_B = 3,
    P_FR_C = 3,
    P_FR_D = 2,
    P_FR_E = 1,
    P_FR_F = 4,
    P_FR_G = 2,
    P_FR_H = 4,
    P_FR_I = 1,
    P_FR_J = 8,
    P_FR_K = 10,
    P_FR_L = 1,
    P_FR_M = 2,
    P_FR_N = 1,
    P_FR_O = 1,
    P_FR_P = 2,
    P_FR_Q = 8,
    P_FR_R = 1,
    P_FR_S = 1,
    P_FR_T = 1,
    P_FR_U = 1,
    P_FR_V = 4,
    P_FR_W = 10,
    P_FR_X = 10,
    P_FR_Y = 10,
    P_FR_Z = 10,
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

char		*put_prompt();

/* game_core.c */

void		start_game(t_game *);

/* pre_init.c */

void		pre_init_game_data(t_game *, t_players *);

/* init.c */

void		init_game(t_game *);
void		init_pre_board(t_game *);
void		init_pre_letters(t_game *);
void		init_game_memory(t_game *);
void		init_letters_list(t_game *);
void		init_letters_point(t_game *);

/* menu.c */

void		menu_pre_game(t_game *);

/* config_pre_game.c */

void		config_with_av(t_game *, char **);
void		config_skip_menu(t_game *);
bool		select_yes_or_no_question(t_game *, char *);
void		select_language_to_play(t_game *);
void		select_number_of_players(t_game *);
void		select_players_type(t_game *);

/* main.c */

int		main(int, char **);

/* ../util/util.c */

char		*read_entry();
char		*put_prompt();
void		super_exit(char *);
void		print_double_tab(char **);

/* xfunc.c */

void		*xmalloc(int);
void		xgetline(char **, FILE *, int);

#endif /*__SCRABBLE_H__ */
