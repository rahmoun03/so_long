NAME = so_long
MLX = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
F = ft_split.c get_next_line_utils.c get_next_line.c move_player.c move_player2.c \
	pars.c pars2.c pars3.c put_game.c so_long.c so_long_utils.c main.c

all : $(NAME)

$(NAME) : $(F)
	@gcc $(FLAGS) $(F) $(MLX) -o $(NAME)
	@tput setaf 2; echo "THE GAME IS READY"

clean:
	@rm -f so_long
	@tput setaf 1; echo "CLEAN COMPLET"
fclean: clean

re: fclean all