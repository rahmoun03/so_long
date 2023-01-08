/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:02:53 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 23:45:23 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include "ft_printf.h"

int	double_p_e(char *str)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			p++;
		if (str[i] == 'E')
			e++;
		if (str[i] == 'C')
			c++;
		i++;
	}
	if (p > 1 || e > 1 || c < 1)
		return (0);
	return (1);
}

int	center_condition(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	else
		return (0);
}

int	center_map(t_map *ptr)
{
	ptr->j = 0;
	if (ptr->maps[ptr->a][ptr->j] != '1')
	{
		ft_printf("ERROR IN LINE : %d\n", ptr->a + 1);
		return (0);
	}
	while (ptr->maps[ptr->a][ptr->j])
	{
		if (!center_condition(ptr->maps[ptr->a][ptr->j]))
			return (0);
		ptr->j++;
	}
	if (ptr->maps[ptr->a][--ptr->j] != '1')
	{
		ft_printf("ERROR IN LINE : %d\n", ptr->a + 1);
		return (0);
	}
	return (1);
}

int	ft_parse(t_map *ptr)
{
	int	check;

	check = 0;
	ptr->a = 0;
	if (ft_strchr(ptr->maps[ptr->a], '0'))
	{
		ft_printf("ERROR IN LINE : %d\n", ptr->a + 1);
		return (0);
	}
	while (ptr->maps[++ptr->a])
	{
		check = center_map(ptr);
		if (!check)
			return (0);
	}
	if (ft_strchr(ptr->maps[--ptr->a], '0'))
	{
		ft_printf("ERROR IN LINE : %d\n", ptr->a + 1);
		return (0);
	}
	return (1);
}

int	check_item(t_map *ptr, int c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j == 0 && ptr->maps[i + 1])
	{
		j = item_chr(ptr->maps[i], c);
		i++;
	}
	if (ptr->maps[--i][j] == c)
	{
		if (ptr->maps[i][j + 1] == '1' && ptr->maps[i][j - 1] == '1'
			&& ptr->maps[i + 1][j] == '1' && ptr->maps[i - 1][j] == '1')
			return (0);
		else
			return (1);
	}
	return (0);
}
