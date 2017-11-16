#include "../include/scrabble.h"

void		fulfill_all_racks(t_game *game)
{
  printf("ok3\n");
  for(int i = 0; i < game->amount_players; i++)
    {
      fulfill_rack(game, i, 7);
      getchar();
      printf("ok3\n");
    }
}



int		who_play_first(t_game *game)
{
  char		biggest = 'Z';
  char		tmp;
  int		to_return;
  int		i = 0;

  while(i < game->amount_players)
    {
      tmp = get_rdm_letter(game, i);
      printf("Player %d show a %c\n", i, tmp);
      if(tmp == 'j')
	{
	  printf("Player %d has a %c (blank tile) and begin\n", i, tmp);
	  return(i);
	}
      if(tmp < biggest)
	{
	  to_return = i;
	  biggest = tmp;
	}
      i++;
    }
  printf("Player %d has a %c and is first\n", to_return, biggest);
    return(to_return);
}

void		make_play(t_game *game)
{
  menu_play(game);
  game->racks[game->playing][2] = ' ';
  game->racks[game->playing][3] = ' ';
  game->nb_letters[game->playing]--;
  game->nb_letters[game->playing]--;
  fulfill_rack(game, game->playing, 2);
}
