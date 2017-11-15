#ifndef		__SCRABBLE_H__
# define       	 __SCRABBLE_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define HUMAN 0
#define BOT 1

#define MAX_PLAYERS 4

#define NB_LETTERS_ALPHABET 26

#define MAX_LETTERS_EN 100
#define MAX_LETTERS_FR 102
#define MAX_LETTERS_SUPER 200

#define MAX_LETTERS_RACK 7

#define	MAX_WORDS_DICT_EN 172805

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

enum LANGUAGE
  {
    ENGLISH = 1,
    FRENCH,
  };

/* ask_user.c */

typedef struct		s_game
{
  /* pre config */
  
  bool			is_skip_menu;
  bool			is_super_mod;
  bool			is_duplicate_mod;
  bool			is_first_time;
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

  int			letters_left;

  int			*nb_letters;
  char			**racks;
  int			*score;

  int			playing;

  char			**dictionnary;
  char			*dictionnary_path;
  int			max_words_dict;
}			t_game;

/* game_core.c */

void		start_game(t_game *);

/* pre_init.c */

void		pre_init_game_data(t_game *);

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