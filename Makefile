CC = cc -Wall -Wextra  -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
OBJS = {SRCS:.c.o}
SRCS = ft_split.c get_next_line_utils.c get_next_line.c main.c move_player.c move_player2.c \
pars.c pars2.c pars3.c put_game.c so_long.c so_long_utils.c


all:
	${CC} ${SRCS} ${MLX} -o ${NAME}
clean:
	rm -rf ${NAME}
re:clean all
