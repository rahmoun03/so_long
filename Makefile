NAME = so_long
MLX = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
SRCS = ft_split.c get_next_line_utils.c get_next_line.c move_player.c move_player2.c \
	pars.c pars2.c pars3.c put_game.c so_long.c so_long_utils.c ft_putunsigned.c \
	ft_printf.c ft_printhexa.c ft_putnbr.c ft_putstr.c ft_putchar.c main.c \

all : $(NAME)

$(NAME) : $(SRCS)
	@cc $(FLAGS) $(SRCS) $(MLX) -o $(NAME)
	@tput setaf 2; echo "THE GAME IS READY"

clean:
	@rm -f so_long
	@tput setaf 1; echo "CLEAN COMPLET"
fclean: clean
re: fclean all