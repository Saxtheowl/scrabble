#include "../include/my.h"

void		config_with_av(t_game *, char **);
void		config_skip_menu(t_game *);
void		config_with_file(t_game *, char *);

void		select_skip_menu(t_game *);
void		select_language_to_play(t_game *);
void		select_number_of_players(t_game *);
void		select_players_type(t_game *);

void		config_with_av(t_game *game, char **cp_av)
{
  game->language = 0;
  puts(cp_av[1]);
  start_game(game);
}

void		config_skip_menu(t_game *game)
{
}

void		config_with_file(t_game *game, char *path)
{
}


void		select_number_of_players(t_game *game)
{
  char		*choice;
  int		nb = 0;
  
  while (nb < 1 && nb > 4)
    {
      printf("choose a number between 1 and 4");
      choice = put_prompt();
      nb = atoi(choice);
    }
  game->amount_players = nb;
}

void		select_skip_menu(t_game *game)
{
  char		*choice;
  int		nb = 0;

  while (nb != 1 && nb != 2)
    {
      printf("\n1. Yes\n");
      printf("\n2. No\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  game->is_skip_menu = nb--;
  return(nb);
}

void		select_players_type(t_game *game)
{
  int		*a;

  return(a);

  /*
  int		*players_type[3];
  int		slot_nb = 0;

  while (slot_nb != 1 && nb != 2)
    {
      printf("\n1. English\n");
      printf("\n2. French\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  return(nb);
 */
}

void		select_language_to_play(t_game *game)
{
  char		*choice;
  int		nb = 0;

  while (nb != 1 && nb != 2)
    {
      printf("\n1. English\n");
      printf("\n2. French\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
}
