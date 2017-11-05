#ifndef		__MY_H__
# define       	__MY_H__

#include "my_list.h"

/* ask_user.c */

char		*put_prompt();

/* game_core.c */

void		start_game(t_game);

/* menu.c */

void		display_menu(t_game);
int		pick_language_toplay();

/* ../read_entry.c */

char		*read_entry();

/* main.c */

int		main(int, char **);

#endif /*__MY_H__ */
