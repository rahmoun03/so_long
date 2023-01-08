/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:27:55 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 03:18:01 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	**read_map(int fd, t_map *ptr)
{
	ptr->i = 1;
	ptr->map = 0;
	ptr->dst = 0;
	while (1)
	{
		ptr->dst = get_next_line(fd);
		if (!ptr->dst)
			break ;
		ptr->map = ft_strjoin(ptr->map, ptr->dst);
		if (ptr->i > 1)
			free(ptr->dst);
		ptr->i++;
	}
	if (!ptr->map || ptr->map[0] != '1' || !new_line(ptr->map)
		|| !double_p_e(ptr->map))
		return (0);
	ptr->maps = ft_split(ptr->map, '\n');
	return (ptr->maps);
}

int	ft_lc(t_map *ptr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(ptr->maps[0]);
	while (ptr->maps[i])
	{
		if ((int)ft_strlen(ptr->maps[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	sum_fun(t_map *ptr)
{
	if (!ft_parse(ptr))
		return (0);
	if (!check_item(ptr, 'P') || !check_item(ptr, 'E') || !check_item(ptr, 'C'))
		return (0);
	if (!p_e_c(ptr) || !ft_lc(ptr))
		return (0);
	return (1);
}

int	val_or_not(int fd, t_map *ptr)
{
	char	**tmp;

	tmp = 0;
	ptr->maps = read_map(fd, ptr);
	if (ptr->maps && sum_fun(ptr) == 1)
	{
		printf(" %smap is valid %s\n", GREEN, "\033[0m");
		return (1);
	}
	else
		printf(" %sinvalid map %s\n", RED, "\033[0m");
	return (0);
}
