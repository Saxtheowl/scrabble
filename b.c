typedef struct          s_game
{
    int			a;
  //char			b;
}                       t_game;

void		call_struct(t_game *p_game)
{
}

void		copy_or_not_struct()
{
  
}

int		main()
{
  char		c;
  t_game	game;
  t_game	*p_game;

  p_game = &game;
  game->a = 1337;
  //  printf("%d\n", sizeof(game) );
  call_struct(p_game);
  //  read(1, &c, 1);
}
