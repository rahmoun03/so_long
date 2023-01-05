#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_path
{
	char	*player[2];
	char	*ground;
	char	*coin;
	int		i;
	int		mov;
	int		change;
}			t_path;

typedef struct s_game
{
	int		start;
	int		xlpayer;
	int		ylpayer;
	int		x;
	int		y;
	void	*img;
	void	*win;
	void	*mlx;
	void	*xpm;
	int		hight;
	int		chight;
	int		width;
	int		cwidth;
	char	**map;
	t_path	*path;
}			t_game;

typedef struct s_ft
{
	int		i;
	int		j;
	int		row;
	int		colum;
	char	**tmp;
}			t_ft;

typedef struct s_map
{
	int		j;
	int		a;
	int		i;
	char	*map;
	char	**maps;
	char	*dst;
}			t_map;

char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);
int			item_chr(char *s, char c);
void		flood_fill(t_ft *tmp, int i, int j);
int			val_or_not(int fd, t_map *ptr);
void		put_game(t_game *game, t_map *ptr);
int			p_e_c(t_map *ptr);
void		draw_map(t_game *game);
void		ground(t_game *game);

#endif