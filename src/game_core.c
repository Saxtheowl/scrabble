#include "../include/scrabble.h"

void		start_game(t_game *);

void		start_game(t_game *game)
{
#ifdef DEBUG_FLAG
  printf("skip menu = %d\n", game->is_skip_menu);
  printf("lang = %d\n", game->language);
  printf("amount = %d\n", game->amount_players);
  printf("type p 1 = %d\n", game->players_type[0]);
  printf("type p 2 = %d\n", game->players_type[1]);
  printf("type p 3 = %d\n", game->players_type[2]);
  printf("board is :\n");
  /*  for(int i = 0; i < 21; i++)
      printf("%s", game->board[i]);*/
  for(int i = 0; game->board[i] != NULL; i++)
    printf("%s", game->board[i]);
  printf("%s\n", game->letters_list);
  for(int i = 0; i < NB_LETTERS_ALPHABET + 1; i++)
    printf("%d\n", game->letters_point[i]);
  
#endif
  int		i = 0;

  while(game->letters_left > 0 || test_cant_play(game) == false)
    {
      getchar();
      if(game->is_first_time == true)
	{
	  fulfill_all_racks(game);
	  game->playing = who_play_first();
	  game->is_first_time = false;
	  print_player_info(game);
	}
      else
	{
	  getchar();
	  printf("ok4\n");
	  fulfill_rack(game, game->playing, 2);
	  printf("ok5\n");
	  print_player_info(game);
	  make_play(game);
	}
      if(game->playing == game->amount_players)
	{
	  printf("ok1\n");
	  game->playing = 0;
	}
      else
	{
	  printf("ok2\n");
	  game->playing++;
	}
    }
  return;
}
