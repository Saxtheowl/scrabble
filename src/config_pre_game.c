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

void		print_av_help()
{
  printf("each flags consist of:\n");
  printf("-h for this help\n");
}

void		letters_from_av(t_game *game, char *letters)
{
  game->letters_list = xmalloc(sizeof(*game->letters_list) * strlen(letters));
  strcpy(game->letters_list, letters);
  game->max_letters = strlen(letters);
  game->letters_left = game->max_letters;
  game->is_letters_from_av = true;
}

void		config_with_av(t_game *game, char **cp_av)
{
  config_skip_menu(game);
  printf("ok1\n");
  for(int i = 1; cp_av[i] != NULL && cp_av[i + 1] != NULL; i = i + 2)
    {
      printf("ok2\n");
      if(strcmp(cp_av[i], "-h") == 0)
	print_av_help();
      if(strcmp(cp_av[i], "-l") == 0)
	game->language = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-a") == 0)
	game->amount_players = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-0") == 0)
	game->players_type[0] = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-1") == 0)
	game->players_type[1] = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-2") == 0)
	game->players_type[2] = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-3") == 0)
	game->players_type[3] = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-s") == 0)
	game->is_super_mod = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-d") == 0)
	game->is_duplicate_mod = atoi(cp_av[i + 1]);
      else if(strcmp(cp_av[i], "-e") == 0)
	letters_from_av(game, cp_av[i + 1]);
    }
  //  start_game(game);
}

void		config_skip_menu(t_game *game)
{
  game->language = 1;
  game->amount_players = 2;
  game->players_type[0] = HUMAN;
  game->players_type[1] = BOT;
  game->is_super_mod = false;
  game->is_duplicate_mod = false;
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
