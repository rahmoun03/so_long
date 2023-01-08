/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:27:29 by arahmoun          #+#    #+#             */
/*   Updated: 2023/01/08 23:49:20 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <unistd.h>

typedef struct s_path
{
	char	*player[2];
	char	*ground;
	int		coin;
	int		i;
	int		mov;
	int		eat;
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
void		draw_start(t_game *game);
void		ground(t_game *game);
void		put_compenent(t_game *game);
void		put_image(t_game *game, char *filename);
void		set_player_path(t_game *game);
void		put_player(t_game *game, char *filename);
int			ft_wc_l(char **str);
void		ft_up(t_game *game);
void		ft_down(t_game *game);
void		ft_right(t_game *game);
void		ft_lift(t_game *game);
int			double_p_e(char *str);
int			ft_parse(t_map *ptr);
int			check_item(t_map *ptr, int c);
int			check_map(char **ptr);
void		ft_free_tmp(char **tmp);
char		**ft_strci(char **src);

#endif
