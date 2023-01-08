/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:27:58 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 23:41:21 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	move_up(t_game *game)
{
	if (game->start > 2 && game->map[(game->ylpayer / 50) - 1][game->xlpayer
		/ 50] != '1' && game->map[(game->ylpayer / 50) - 1][game->xlpayer
		/ 50] != 'E')
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
		ft_printf("MOVES : %d\n", ++game->path->mov);
	}
	else if (game->start > 2 && game->map[(game->ylpayer / 50)
			- 1][game->xlpayer / 50] != '1'
			&& game->path->eat == game->path->coin)
	{
		put_player(game, game->path->ground);
		game->ylpayer -= 50;
		put_player(game, game->path->player[game->path->i]);
		ft_printf("MOVES : %d\n", ++game->path->mov);
		exit(0);
	}
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
		put_image(game, (char *)"./asset/start/pin.xpm");
	}
	else
		move_up(game);
}

void	move_down(t_game *game)
{
	if (game->start > 2 && game->map[(game->ylpayer / 50) + 1][game->xlpayer
		/ 50] != '1' && game->map[(game->ylpayer / 50) + 1][game->xlpayer
		/ 50] != 'E')
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
		ft_printf("MOVES : %d\n", ++game->path->mov);
	}
	else if (game->start > 2 && game->map[(game->ylpayer / 50)
			+ 1][game->xlpayer / 50] != '1'
			&& game->path->eat == game->path->coin)
	{
		put_player(game, game->path->ground);
		game->ylpayer += 50;
		put_player(game, game->path->player[game->path->i]);
		ft_printf("MOVES : %d\n", ++game->path->mov);
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
		put_image(game, (char *)"./asset/start/pin.xpm");
	}
	else
		move_down(game);
}
