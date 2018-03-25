#include "../include/scrabble.h"

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

bool		select_yes_or_no_question(char *question)
{
  char		*choice;
  int		nb = 0;

  while (nb != 1 && nb != 2)
    {
      printf("%s", question);
      printf("1. Yes\n");
      printf("2. No\n");
      choice = put_prompt();
      nb = atoi(choice);
    }
  return ((nb == 1) ? 1 : 0);
}

void		letters_from_av(t_game *game, char *letters)
{
  game->letters_list = xmalloc(sizeof(*game->letters_list) * strlen(letters) + 1);
  strcpy(game->letters_list, letters);
  game->max_letters = strlen(letters);
  game->letters_left = game->max_letters;
  game->is_letters_from_av = true;
}

bool		single_av_flag(char c)
{
  char		*single_flag_list = "hdstc";

  for (int i = 0; single_flag_list[i] != '\0'; i++)
    {
      if (single_flag_list[i] == c)
	return (true);
    }
  return (false);
}

void		config_with_av(t_game *game, char **cp_av)
{
  int		i = 1;
  
  config_skip_menu(game);
  while (cp_av[i] != NULL) // LUL
    {
      if (strcmp(cp_av[i], "-h") == 0)
	print_help();
      if (strcmp(cp_av[i], "-l") == 0)
	game->language = atoi(cp_av[i + 1]);
      else if (strcmp(cp_av[i], "-a") == 0)
	game->amount_players = atoi(cp_av[i + 1]);
      else if (strcmp(cp_av[i], "-p1") == 0)
	game->players_type[0] = atoi(cp_av[i + 1]);
      else if (strcmp(cp_av[i], "-p2") == 0)
	game->players_type[1] = atoi(cp_av[i + 1]);
      else if (strcmp(cp_av[i], "-p3") == 0)
	game->players_type[2] = atoi(cp_av[i + 1]);
      else if (strcmp(cp_av[i], "-p4") == 0)
	game->players_type[3] = atoi(cp_av[i + 1]);
      else if (strcmp(cp_av[i], "-s") == 0)
	game->is_super_mod = true;
      else if (strcmp(cp_av[i], "-d") == 0)
	game->is_duplicate_mod = true;
      else if (strcmp(cp_av[i], "-e") == 0)
	letters_from_av(game, cp_av[i + 1]);
      else if (strcmp(cp_av[i], "-c") == 0)
	game->is_always_scramble_rack = true;
      else if (strcmp(cp_av[i], "-t") == 0)
	game->is_list_letters_linear = true;
      
      if (single_av_flag(cp_av[i][1]))
	i++;
      else
	i = i + 2;
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

void		config_with_file(t_game *game)
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

  for (int slot_nb = 0; slot_nb < game->amount_players; slot_nb++)
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

void		print_help()
{
  printf("\n all commands:\n");
  printf("-h, display this text \n");
  printf("-l, define language, 1 ENGLISH, 2 FRENCH \n");
  printf("-a, define the amount of players \n");
  printf("-p[x] specify for the x type of player his type, 1 HUMAN, 2 BOT\n");
  printf("-s, select super mod \n");
  printf("-d, select duplicated_mod \n");
  printf("-e, will use the string entered after the flag as the letters that will be used for the bag \n");
  printf("-c, scramble the order in which the letter appear in the racks \n");
  printf("-t, select if the letters in the bag have to given in order ");
}
