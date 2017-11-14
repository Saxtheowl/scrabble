#include "../include/scrabble.h"

void		config_with_av(t_game *, char **);
void		config_skip_menu(t_game *);
void		config_with_file(t_game *, char *);

bool		select_yes_or_no_question(t_game *, char *);
void		select_language_to_play(t_game *);
void		select_number_of_players(t_game *);
void		select_players_type(t_game *);

bool		select_yes_or_no_question(t_game *game, char *question)
{
  char		*choice;
  int		nb = 0;

  while(nb != 1 && nb != 2)
    {
      printf("%s", question);
      printf("1. Yes\n");
      printf("2. No\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  return((nb == 1) ? 1 : 0);
}

void		config_with_av(t_game *game, char **cp_av)
{
  game->language = 0;
  puts(cp_av[1]);
  start_game(game);
}

void		config_skip_menu(t_game *game)
{
  game->language = 1;
  game->amount_players = 2;
  game->players_type[0] = HUMAN;
  game->players_type[1] = BOT;
}

void		config_with_file(t_game *game, char *path)
{
  config_skip_menu(game);
}

void		select_language_to_play(t_game *game)
{
  char		*choice;
  int		nb = 0;

  while (nb != 1 && nb != 2)
    {
      printf("1. English\n");
      printf("2. French\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  game->language = ((nb == 1) ? 1 : nb);
}

void		select_number_of_players(t_game *game)
{
  char		*choice;
  int		nb = 0;

  while (nb < 2 || nb > 4)
    {
      printf("enter a number between 1 and 4\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  game->amount_players = nb--;
}

void		select_players_type(t_game *game)
{
  int		nb = 0;
  char		*choice;

  for(int slot_nb = 0; slot_nb < game->amount_players; slot_nb++)
    {
      while (nb != 1 && nb != 2)
	{
	  printf("\nFor Player %d, pick:", slot_nb);
	  printf("\n1. HUMAN\n");
	  printf("\n2. BOT\n");
	  choice = put_prompt();
	  nb = atoi(choice);
	}
      game->players_type[slot_nb] = ((nb == 1) ? 1 : 0);
      nb = 0;
    }
}
