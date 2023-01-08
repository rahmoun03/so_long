/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:34:07 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 03:34:29 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	move_right(t_game *game)
{
	if (game->start > 2 && game->map[game->ylpayer / 50][(game->xlpayer / 50)
		+ 1] != '1' && game->start > 2 && game->map[game->ylpayer
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
	else
		move_right(game);
}

void	move_lift(t_game *game)
{
	if (game->start > 2 && game->map[game->ylpayer / 50][(game->xlpayer / 50)
		- 1] != '1' && game->start > 2 && game->map[game->ylpayer
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
	else
		move_lift(game);
}
