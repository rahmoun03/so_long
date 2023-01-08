/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:27:47 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 00:06:55 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	item_chr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
		i++;
	if (c == s[i])
		return (i);
	return (0);
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
