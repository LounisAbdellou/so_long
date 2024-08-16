CC = cc 
NAME = so_long 
LIBFT = ./libft/libft.a
MLX = ./mlx_linux/libmlx.a 

TEST = "\"test\""

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
CFLAGS = -Wall -Wextra -Werror -D PATH="\"$(shell pwd)\"" -Iincludes -Imlx_linux 

SRCS = srcs/main.c srcs/utils.c srcs/error.c srcs/flood.c srcs/image.c \
	   srcs/game.c srcs/init.c

OBJS = ${SRCS:.c=.o} 

all: ${NAME}

${NAME}: ${OBJS}
	@make -C libft
	@make -C mlx_linux
	${CC} ${CFLAGS} ${MLX_FLAGS} ${OBJS} -o ${NAME} ${LIBFT} ${MLX}

clean:
	@make clean -C libft
	rm -f ${OBJS}

fclean: clean
	@make clean -C mlx_linux
	rm -f ${LIBFT}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
