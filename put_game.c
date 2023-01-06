#include "get_next_line.h"
#include "so_long.h"

int	ft_wc_l(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	set_player_path(t_game *game)
{
	game->path->player[0] = ft_strdup("./asset/player/boy.xpm");
	game->path->player[1] = ft_strdup("./asset/player/girl.xpm");
	game->path->ground = ft_strdup("./asset/ground/ground.xpm");
}

void	put_image(t_game *game, char *filename)
{
	game->xpm = mlx_xpm_file_to_image(game->mlx, filename, &game->width,
			&game->hight);
	mlx_put_image_to_window(game->mlx, game->win, game->xpm, game->x, game->y);
	mlx_destroy_image(game->mlx, game->xpm);
}

void	put_player(t_game *game, char *filename)
{
	game->xpm = mlx_xpm_file_to_image(game->mlx, filename, &game->width,
			&game->hight);
	mlx_put_image_to_window(game->mlx, game->win, game->xpm, game->xlpayer,
			game->ylpayer);
	mlx_destroy_image(game->mlx, game->xpm);
}

void	ft_up(t_game *game)
{
	if (game->start == 1 || game->start == 2)
	{
		if (game->start == 1)
			game->start = 0;
		else
			game->start = 1;
		put_image(game, game->path->ground);
		game->y -= 50;
		put_image(game, "./asset/start/pin.xpm");
	}
	else if (game->start > 2 && game->map[(game->ylpayer / 50)
			- 1][game->xlpayer / 50] != '1' && game->map[(game->ylpayer / 50)
			- 1][game->xlpayer / 50] != 'E')
	{
		if (game->map[(game->ylpayer / 50) - 1][game->xlpayer / 50] == 'C')
		{
			game->path->eat++;
			game->map[(game->ylpayer / 50) - 1][game->xlpayer / 50] = '0';
		}
		put_player(game, game->path->ground);
		game->ylpayer -= 50;
		put_player(game, game->path->ground);
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
	}
	else if (game->start > 2 && game->map[(game->ylpayer / 50)
			- 1][game->xlpayer / 50] != '1'
			&& game->path->eat == game->path->coin)
	{
		put_player(game, game->path->ground);
		game->ylpayer -= 50;
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
		exit(0);
	}
}

void	ft_down(t_game *game)
{
	if (game->start == 0 || game->start == 1)
	{
		if (game->start == 0)
			game->start = 1;
		else
			game->start = 2;
		put_image(game, game->path->ground);
		game->y += 50;
		put_image(game, "./asset/start/pin.xpm");
	}
	else if (game->start > 2 && game->map[(game->ylpayer / 50)
			+ 1][game->xlpayer / 50] != '1' && game->map[(game->ylpayer / 50)
			+ 1][game->xlpayer / 50] != 'E')
	{
		if (game->map[(game->ylpayer / 50) + 1][game->xlpayer / 50] == 'C')
		{
			game->path->eat++;
			game->map[(game->ylpayer / 50) + 1][game->xlpayer / 50] = '0';
		}
		put_player(game, game->path->ground);
		game->ylpayer += 50;
		put_player(game, game->path->ground);
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
	}
	else if (game->start > 2 && game->map[(game->ylpayer / 50)
			+ 1][game->xlpayer / 50] != '1'
			&& game->path->eat == game->path->coin)
	{
		put_player(game, game->path->ground);
		game->ylpayer += 50;
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
		exit(0);
	}
}

void	ft_right(t_game *game)
{
	if (game->start == 2)
	{
		game->x += 100;
		game->path->i = 1;
		put_image(game, game->path->ground);
		put_image(game, game->path->player[game->path->i]);
		game->x -= 100;
	}
	else if (game->start > 2 && game->map[game->ylpayer / 50][(game->xlpayer
				/ 50) + 1] != '1' && game->start > 2 && game->map[game->ylpayer
			/ 50][(game->xlpayer / 50) + 1] != 'E')
	{
		if (game->map[game->ylpayer / 50][(game->xlpayer / 50) + 1] == 'C')
		{
			game->path->eat++;
			game->map[game->ylpayer / 50][(game->xlpayer / 50) + 1] = '0';
		}
		put_player(game, game->path->ground);
		game->xlpayer += 50;
		put_player(game, game->path->ground);
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
	}
	else if (game->start > 2 && game->map[game->ylpayer / 50][(game->xlpayer
				/ 50) + 1] != '1' && game->start > 2
			&& game->path->eat == game->path->coin)
	{
		put_player(game, game->path->ground);
		game->xlpayer += 50;
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
		exit(0);
	}
}

void	ft_lift(t_game *game)
{
	if (game->start == 2)
	{
		game->x += 100;
		game->path->i = 0;
		put_image(game, game->path->ground);
		put_image(game, game->path->player[game->path->i]);
		game->x -= 100;
	}
	else if (game->start > 2 && game->map[game->ylpayer / 50][(game->xlpayer
				/ 50) - 1] != '1' && game->start > 2 && game->map[game->ylpayer
			/ 50][(game->xlpayer / 50) - 1] != 'E')
	{
		if (game->map[game->ylpayer / 50][(game->xlpayer / 50) - 1] == 'C')
		{
			game->path->eat++;
			game->map[game->ylpayer / 50][(game->xlpayer / 50) - 1] = '0';
		}
		put_player(game, game->path->ground);
		game->xlpayer -= 50;
		put_player(game, game->path->ground);
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
	}
	else if (game->start > 2 && game->map[game->ylpayer / 50][(game->xlpayer
				/ 50) - 1] != '1' && game->start > 2
			&& game->path->eat == game->path->coin)
	{
		put_player(game, game->path->ground);
		game->xlpayer -= 50;
		put_player(game, game->path->player[game->path->i]);
		printf("MOVES : %d\n", ++game->path->mov);
		exit(0);
	}
}

int	key_hook(int key, t_game *game)
{
	printf("%d / %d\n", game->path->eat, game->path->coin);
	if (key == 126 || key == 13) // up
		ft_up(game);
	if (key == 125 || key == 1) // down
		ft_down(game);
	if (key == 124 || key == 2) // right
		ft_right(game);
	if (key == 123 || key == 0) // lift
		ft_lift(game);
	if (key == 53) // esc
	{
		printf("%s ______ YOU EXIT THE GAME _____ %s", "\033[7m\033[33m",
				"\033[0m");
		exit(0);
	}
	if (key == 36 && game->start <= 1)
	{
		if (game->start == 1)
			exit(0);
		game->start = 3;
		ground(game);
		draw_map(game);
	}
	return (key);
}

void	ground(t_game *game)
{
	game->y = 0;
	while (game->y < game->chight)
	{
		game->x = 0;
		while (game->x < game->cwidth)
		{
			put_image(game, game->path->ground);
			game->x += 50;
		}
		game->y += 50;
	}
}

void	put_compenent(t_game *game)
{
	if (game->map[game->y / 50][game->x / 50] == '1')
		put_image(game, "./asset/wall/wall.xpm");
	if (game->map[game->y / 50][game->x / 50] == 'P')
	{
		put_image(game, game->path->player[game->path->i]);
		game->xlpayer = game->x;
		game->ylpayer = game->y;
	}
	if (game->map[game->y / 50][game->x / 50] == 'C')
	{
		put_image(game, "./asset/coin/coin.xpm");
		game->path->coin++;
	}
	if (game->map[game->y / 50][game->x / 50] == 'E')
		put_image(game, "./asset/dor/dor.xpm");
}

void	draw_map(t_game *game)
{
	game->path->coin = 0;
	game->chight = game->hight;
	game->cwidth = game->width;
	ground(game);
	game->y = 0;
	while (game->map[game->y / 50])
	{
		game->x = 0;
		while (game->map[game->y / 50][game->x / 50])
		{
			put_compenent(game);
			game->x += 50;
		}
		game->y += 50;
	}
}

void	draw_start(t_game *game)
{
	game->chight = game->hight;
	game->cwidth = game->width;
	game->start = 0;
	game->y = 0;
	ground(game);
	mlx_string_put(game->mlx, game->win, 10, game->chight - 30, 000255000000,
			"press entre to start");
	game->x = (ft_strlen(game->map[0]) / 2 - 1) * 50;
	game->y = (ft_wc_l(game->map) / 2 - 1) * 50;
	put_image(game, "./asset/start/start.xpm");
	game->x -= 50;
	put_image(game, "./asset/start/pin.xpm");
	game->y += 50;
	game->x += 50;
	put_image(game, "./asset/start/exit.xpm");
	game->y += 50;
	game->x += 50;
	put_image(game, game->path->player[game->path->i]);
	game->x -= 100;
	game->y -= 100;
}

void	put_game(t_game *game, t_map *ptr)
{
	game->path = (t_path *)malloc(sizeof(t_path));
	game->mlx = mlx_init();
	game->width = ft_strlen(ptr->maps[0]) * 50;
	game->hight = ft_wc_l(ptr->maps) * 50;
	game->win = mlx_new_window(game->mlx, game->width, game->hight, " BERCHO ");
	game->path->i = 0;
	game->path->mov = 0;
	game->path->eat = 0;
	set_player_path(game);
	game->map = ptr->maps;
	draw_start(game);
	printf("%d\n", game->start);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx);
}
