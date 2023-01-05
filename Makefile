CC = cc -Wall -Wextra  -Werror
MLX = -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g
NAME = so_long

all:
	${CC} *.c ${MLX} -o ${NAME}
clean:
	rm -rf ${NAME}
re:clean all
