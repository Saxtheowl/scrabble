#ifndef		__MY_H__
# define       	__MY_H__

#include <stdbool.h>

#include "my_list.h"

/* ask_user.c */

char		*put_prompt();

/* game_core.c */

void		start_game(t_game);

/* menu.c */

void		menu_intro(t_game);
bool		select_skip_menu();
t_game		init_skip_menu(t_game);
int		select_language_to_play();
int		select_number_of_players();
int		*select_players_type();

/* ../read_entry.c */

char		*read_entry();

/* main.c */

int		main(int, char **);

#endif /*__MY_H__ */
