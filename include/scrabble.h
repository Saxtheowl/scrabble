#ifndef		__SCRABBLE_H__
# define       	 __SCRABBLE_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define _SVID_SOURCE
#include <string.h>
#include <signal.h>

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

  bool			is_letters_from_av;
  bool			is_always_scramble_rack;
  bool			is_list_letters_linear;
  
  bool			is_skip_menu;
  bool			is_super_mod;
  bool			is_duplicate_mod;
  bool			is_first_turn;
  bool			is_turn_done;
  bool			is_left_to_right;
  bool			is_side_word;
  bool			is_letter_middle;
  bool			is_word_put;
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

  int			symbol_max_letter;
  int			symbol_max_word;

  int			letters_left;

  int			*nb_letters;
  char			**racks;
  int			*old_score;
  int			*score;
  int			new_word_pot;

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

/* util/ */

/* util.c */

char		*read_entry();
char		*put_prompt();
void		super_exit();
int		rack_strlen(char *);
bool		is_char(char);
bool		is_num_char(char);
bool		is_lower_char(char);
bool		is_upper_char(char);
char		to_lower_solo(char);
char		to_upper_solo(char);
char		*to_upper(char *);
int		strcmp_dictionnary(char *, char *);
int		get_number_from_letter(char);
void		print_double_tab(char **);

/* xfunc.c */

void		*xmalloc(int);
void		xgetline(char **, FILE *, int);

/* src/ */

/* board.c */

void		put_word(t_game *);
void		remove_word(t_game *);

/* check.c */

bool		is_syntax_letter_valid(t_game *, char *pos);
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

/* config_pre_game.c */

bool		select_yes_or_no_question(char *);
void		letters_from_av(t_game *, char *);
bool		single_av_flag(char);
void		config_with_av(t_game *game, char **);
void		config_skip_menu(t_game *);
void		config_with_file(t_game *);
void		select_language_to_play(t_game *);
void		select_number_of_players(t_game *);
void		select_players_type(t_game *);
void		print_help();

/* game_core.c */

void		start_game(t_game *);

/* init.c */

void		init_game(t_game *);
void		init_pre_board(t_game *);
void		init_pre_letters(t_game *);
void		init_board(t_game *);
void		init_game_memory(t_game *);
void		init_letters_list(t_game *);
void		init_letters_point(t_game *);
void		init_dictionnary(t_game *);

/* main.c */

int		main(int, char **);

/* menu. */

void		menu_pre_game(t_game *);
void		menu_play(t_game *);

/* output.c */

void		print_board(t_game *);
void		color_print_inner_board(char *, int);
void		print_players_info(t_game *);

/* play.c */

int		who_play_first(t_game *);
void		make_play(t_game *);
void		update_turn(t_game *);
void		play_word(t_game *, char *, char *);
void		play_exchange_letters(t_game *, char *);
void		play_pass(t_game *);
void		transform_joker(t_game *, char *);

/* pre_init.c */

void		pre_init_game_data(t_game *);

/* rack.c */

char		*scramble_rack(char *);
char		give_rdm_letter(t_game *);
char		get_rdm_letter(t_game *);
bool		remove_letter_in_rack(t_game *, char);
void		put_letter_in_rack(t_game *, char);
void		fulfill_rack(t_game *, int, int);
void		fulfill_all_racks(t_game *);
void		put_letter_back_in_list(t_game *, char);
void		put_letters_back_in_rack(t_game *, char *);

/* score.c */

int		get_multiplier(t_game *, char);
int		get_score_from_letter(t_game *, char, char, bool);
int		get_special_point(t_game *, int, int);
bool		get_bingo(char *);
int		get_score(t_game *, char *, bool, int);

#endif /*__SCRABBLE_H__ */
