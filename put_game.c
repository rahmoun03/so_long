/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:27:50 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 16:58:08 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	key_hook(int key, t_game *game)
{
	if (key == 126 || key == 13)
		ft_up(game);
	if (key == 125 || key == 1)
		ft_down(game);
	if (key == 124 || key == 2)
		ft_right(game);
	if (key == 123 || key == 0)
		ft_lift(game);
	if (key == 53)
	{
		printf("%s ______ YOU EXIT THE GAME _____ %s", "\033[7m\033[33m", \
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
		put_image(game, (char *)"./asset/wall/wall.xpm");
	if (game->map[game->y / 50][game->x / 50] == 'P')
	{
		put_image(game, game->path->player[game->path->i]);
		game->xlpayer = game->x;
		game->ylpayer = game->y;
	}
	if (game->map[game->y / 50][game->x / 50] == 'C')
	{
		put_image(game, (char *)"./asset/coin/coin.xpm");
		game->path->coin++;
	}
	if (game->map[game->y / 50][game->x / 50] == 'E')
		put_image(game, (char *)"./asset/dor/dor.xpm");
}

void	put_game(t_game *game, t_map *ptr)
{
	game->path = (t_path *)malloc(sizeof(t_path));
	game->mlx = mlx_init();
	game->width = ft_strlen(ptr->maps[0]) * 50;
	game->hight = ft_wc_l(ptr->maps) * 50;
	game->win = mlx_new_window(game->mlx, game->width, game->hight,
			(char *)" BERCHO ");
	game->path->i = 0;
	game->path->mov = 0;
	game->path->eat = 0;
	set_player_path(game);
	game->map = ptr->maps;
	draw_start(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx);
}
