NAME = fdf

SRC = ./fdf.c \
		./parsing.c \
		./window.c \
		./isometric.c \
		./utils.c \
		./bresenham.c \
		./connect_points.c \
		./color.c \

OBJS = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror -g
CFLAGS = -I ./libft -I ./get_next_line -I ./ft_printf -I ./mlx

LIBFT = libft/libft.a

GNT = get_next_line/get_next_line.a

PRINT_F = ft_printf/ft_printf.a

MLX = minilibx-linux/minilibx-linux/libmlx.a

MLX_FLAG = -Lmlx -lXext -lX11 -lm

all: ${NAME}

${NAME}: ${OBJS}

	$(MAKE) -C libft
	$(MAKE) -C get_next_line
	$(MAKE) -C ft_printf
	$(MAKE) -C minilibx-linux/minilibx-linux
	${CC} -o $(NAME) $(OBJS) $(LIBFT) $(GNT) $(PRINT_F) $(MLX) $(MLX_FLAG)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C minilibx-linux/minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean
	$(MAKE) -C ft_printf fclean

re: fclean all
