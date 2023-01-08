/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:27:52 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 03:22:57 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	ft_search(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'P' || tmp[i][j] == 'E' || tmp[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_strci(char **src)
{
	char	**dst;
	int		k;
	int		m;

	k = 0;
	while (src[k])
		k++;
	dst = (char **)malloc(sizeof(char *) * (k + 1));
	k = 0;
	while (src[k])
	{
		m = 0;
		dst[k] = (char *)malloc((ft_strlen(src[k]) + 1) * sizeof(char));
		while (src[k][m])
		{
			dst[k][m] = src[k][m];
			m++;
		}
		dst[k][m] = '\0';
		k++;
	}
	dst[k] = 0;
	return (dst);
}

void	ft_free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
}

int	p_e_c(t_map *ptr)
{
	t_ft	*tmp;
	int		check;

	tmp = (t_ft *)malloc(sizeof(t_ft));
	tmp->i = 0;
	tmp->j = 0;
	tmp->colum = 0;
	tmp->tmp = ft_strci(ptr->maps);
	tmp->row = ft_strlen(tmp->tmp[0]);
	while (tmp->tmp[tmp->i] && !tmp->j)
		tmp->j = item_chr(tmp->tmp[tmp->i++], 'P');
	tmp->i--;
	while (tmp->tmp[tmp->colum])
		tmp->colum++;
	flood_fill(tmp, tmp->i, tmp->j);
	check = ft_search(tmp->tmp);
	ft_free_tmp(tmp->tmp);
	free(tmp->tmp);
	free(tmp);
	return (check);
}

void	flood_fill(t_ft *tmp, int i, int j)
{
	if (i < 0 || j < 0 || i > tmp->colum || j > tmp->row
		|| tmp->tmp[i][j] == '*')
		return ;
	if (tmp->tmp[i][j] == 'E')
	{
		tmp->tmp[i][j] = '*';
		return ;
	}
	tmp->tmp[i][j] = '*';
	if (tmp->tmp[i][j + 1] && tmp->tmp[i][j + 1] != '1')
		flood_fill(tmp, i, j + 1);
	if (tmp->tmp[i + 1][j] && tmp->tmp[i + 1][j] != '1')
		flood_fill(tmp, i + 1, j);
	if (tmp->tmp[i - 1][j] && tmp->tmp[i - 1][j] != '1')
		flood_fill(tmp, i - 1, j);
	if (tmp->tmp[i][j - 1] && tmp->tmp[i][j - 1] != '1')
		flood_fill(tmp, i, j - 1);
}
