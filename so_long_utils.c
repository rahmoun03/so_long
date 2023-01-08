/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:05:27 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 23:45:43 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	draw_start(t_game *game)
{
	game->chight = game->hight;
	game->cwidth = game->width;
	game->start = 0;
	game->y = 0;
	ground(game);
	mlx_string_put(game->mlx, game->win, 10, game->chight - 30, 000255000000,
		(char *)"press entre to start");
	game->x = (ft_strlen(game->map[0]) / 2 - 1) * 50;
	game->y = (ft_wc_l(game->map) / 2 - 1) * 50;
	put_image(game, (char *)"./asset/start/start.xpm");
	game->x -= 50;
	put_image(game, (char *)"./asset/start/pin.xpm");
	game->y += 50;
	game->x += 50;
	put_image(game, (char *)"./asset/start/exit.xpm");
	game->y += 50;
	game->x += 50;
	put_image(game, game->path->player[game->path->i]);
	game->x -= 100;
	game->y -= 100;
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
