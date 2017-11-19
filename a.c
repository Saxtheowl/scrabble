int		main()
{
  char		**map;

  map = malloc(sizeof(*map) * 10);

  map[0][0] = 'a';
  map[0][1] = 'a';
  map[1][0] = 'a';
  map[1][1] = 'a';
}
