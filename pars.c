#include "get_next_line.h"
#include "so_long.h"

int	ft_strcmp(char *s1, const char *s2)
{
	int	j;

	j = 0;
	while (s1[j] && s2[j] && (s1[j] == s2[j]))
		j++;
	return (s1[j] - s2[j]);
}

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

int	check_map(char **ptr)
{
	int	colum;
	int	row;

	colum = 0;
	while (ptr[colum])
	{
		row = 0;
		while (ptr[colum][row])
		{
			if (ptr[colum + 1] && ptr[colum][row] == ' ' && (ptr[colum
					+ 1][row] != '1' || ptr[colum - 1][row] != '1'
					|| ptr[colum][row - 1] != '1' || ptr[colum][row
					+ 1] != '1'))
			{
				if (ptr[colum + 1] && ptr[colum][row] == ' ' && (ptr[colum
						+ 1][row] == '0' || ptr[colum - 1][row] == '0'
						|| ptr[colum][row - 1] == '0' || ptr[colum][row
						+ 1] == '0'))
				{
					printf("Error in the colum %d and row %d \n", colum + 1, row
							+ 2);
					return (0);
				}
			}
			row++;
		}
		colum++;
	}
	return (1);
}

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
	if (!ptr->map || ptr->map[0] != '1' || !new_line(ptr->map) || !double_p_e(ptr->map))
		return (0);
	ptr->maps = ft_split(ptr->map, '\n');
	return (ptr->maps);
}

int	ft_parse(t_map *ptr)
{
	ptr->a = 0;
	if (ft_strchr(ptr->maps[ptr->a], '0'))
	{
		printf("ERROR IN LINE : %d\n", ptr->a + 1);
		return (0);
	}
	while (ptr->maps[++ptr->a])
	{
		ptr->j = 0;
		if (ptr->maps[ptr->a][ptr->j] != '1')
		{
			printf("ERROR IN LINE : %d\n", ptr->a + 1);
			return (0);
		}
		while (ptr->maps[ptr->a][ptr->j])
		{
			if(ptr->maps[ptr->a][ptr->j] != '0' && ptr->maps[ptr->a][ptr->j] != '1'
				&& ptr->maps[ptr->a][ptr->j] != 'P' && ptr->maps[ptr->a][ptr->j] != 'E'
					&& ptr->maps[ptr->a][ptr->j] != 'C')
				return 0;
			ptr->j++;
		}
		if (ptr->maps[ptr->a][--ptr->j] != '1')
		{
			printf("ERROR IN LINE : %d\n", ptr->a + 1);
			return (0);
		}
	}
	if (ft_strchr(ptr->maps[--ptr->a], '0'))
	{
		printf("ERROR IN LINE : %d\n", ptr->a + 1);
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
	if (!ft_parse(ptr) || !check_map(ptr->maps))
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
