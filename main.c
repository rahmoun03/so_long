/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:28:04 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/07 23:28:05 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	check_path(char *str)
{
	int		i;
	int		j;
	char	*ber;

	j = 0;
	ber = ft_strdup(".ber");
	i = ft_strlen(str) - 4;
	while (str[i])
	{
		if (str[i] != ber[j])
		{
			free(ber);
			return (0);
		}
		i++;
		j++;
	}
	if (!str[i] && !ber[j])
	{
		free(ber);
		return (1);
	}
	free(ber);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	*ptr;
	t_game	*game;

	ptr = (t_map *)malloc(sizeof(t_map));
	game = (t_game *)malloc(sizeof(t_game));
	fd = open(av[1], O_RDWR);
	if (ac != 2 || fd == -1 || !check_path(av[1]))
		return (printf(" %sinvalid path %s ", RED, DEFFAULT));
	if (val_or_not(fd, ptr) == 0)
		return (0);
	else
		put_game(game, ptr);
}
