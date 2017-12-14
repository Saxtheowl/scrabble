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

#define MAX_SYMBOL_MULTIPLY_LETTER_STANDARD 2
#define MAX_SYMBOL_MULTIPLY_LETTER_SUPER 3
#define MAX_SYMBOL_MULTIPLY_WORD_STANDARD 4
#define MAX_SYMBOL_MULTIPLY_WORD_SUPER 6

#define MAX_LETTERS_RACK 7

#define	MAX_WORDS_DICT_EN 172805
#define	MAX_WORDS_DICT_FR 130557

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLACK "\033[30m"  



#define clear() system("clear")

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
  bool			is_first_turn;
  bool			is_turn_done;
  bool			is_left_to_right;
  bool			is_side_word;
  bool			is_letter_middle;
  int			language;
  int			amount_players;
  int			*players_type;
  /* fixed value */
  char			**board;
  char			**s_board;

  char			*board_path;
  
  int			size_board;

  char			*letters_list_path;
  char			*letters_points_path;
  int			max_letters;
  char			*alphabet;

  char			*letters_list;
  int			*letters_point;

  int			symbol_max_letter;
  int			symbol_max_word;

  int			letters_left;

  int			*nb_letters;
  char			**racks;
  int			*old_score;
  int			*score;

  int			playing;

  char			**dictionnary;
  char			*dictionnary_path;
  int			max_words_dict;

  int			y_wrd_p1;
  int			y_wrd_p2;
  int			x_wrd_p1;
  int			x_wrd_p2;

  char			*word_test;
  char			*road_word;

  char			new_word_special_symbol;
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
void		init_dictionnary(t_game *);

/* menu.c */

void		menu_pre_game(t_game *);
void		menu_play(t_game *);

/* config_pre_game.c */

void		config_with_av(t_game *, char **);
void		config_skip_menu(t_game *);
bool		select_yes_or_no_question(t_game *, char *);
void		select_language_to_play(t_game *);
void		select_number_of_players(t_game *);
void		select_players_type(t_game *);

/* letters.c */

char		get_letter(t_game *);
char		get_rdm_letter(t_game *, int);
void		fulfill_rack(t_game *, int, int);

/*output.c */

void		print_board(t_game *);
void		print_players_info(t_game *);

/* play.c */

void		fulfill_all_racks(t_game *);
int		who_play_first(t_game *);
void		make_play(t_game *);

/* check.c */

bool		test_cant_play(t_game *);
bool		is_valid_word(t_game *, char *);

/* end_of_the_game.c */

void		end_of_the_game(t_game *);

/* main.c */

int		main(int, char **);

/* ../util/util.c */

char		*read_entry();
char		*put_prompt();
void		super_exit(char *);
int		rack_strlen(char *);
bool		is_char(char);
int		strcmp_dictionnary(char *, char *);


/* xfunc.c */

void		*xmalloc(int);
void		xgetline(char **, FILE *, int);

#endif /*__SCRABBLE_H__ */
