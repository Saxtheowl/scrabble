#ifndef		__MY_H__
# define       	 __MY_H__

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_list.h"

#define HUMAN 0
#define BOT 1

//#define BOARD_PATH ../board

/* ask_user.c */

char		*put_prompt();

/* game_core.c */

void		start_game(t_game *);

/* init.c */

void		init_game_data(t_game *);

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
