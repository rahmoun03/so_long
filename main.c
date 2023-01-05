#include "get_next_line.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;
	t_map *ptr;
	t_game *game;

	ptr = (t_map *)malloc(sizeof(t_map));
	game = (t_game *)malloc(sizeof(t_game));
	if (ac != 2 || ft_strcmp(av[1], "map.ber") != 0)
		return (printf("%sinvalid path%s", RED, DEFFAULT));
	fd = open(av[1], O_RDWR);
	if (val_or_not(fd, ptr) == 0)
		return (0);
	else
		put_game(game, ptr);
}
