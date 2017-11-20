int		main()
{
  char		*map;

  //  map = malloc(sizeof(*map) * 10);

  memcpy(map, "...........", 10);
  //  map[2] = '\0';
  printf("%s\n", map);
}
