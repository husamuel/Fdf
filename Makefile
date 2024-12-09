NAME = fdf

SRC = ./fdf.c \
		./parsing.c \
		./connect.c \
		./windows_manag.c \
		./bresenham.c \
		./isometric.c \
		./extra_color.c \

OBJS = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror
CFLAGS = -I ./libft -I ./get_next_line -I ./ft_printf -I ./mlx

LIBFT = libft/libft.a

GNT = get_next_line/get_next_line.a

PRINT_F = ft_printf/ft_printf.a

MLX = mlx/libmlx.a

MLX_FLAG = -Lmlx -lmlx -lXext -lX11 -lm

all: ${NAME}

${NAME}: ${OBJS}

	$(MAKE) -C libft
	$(MAKE) -C get_next_line
	$(MAKE) -C ft_printf
	$(MAKE) -C mlx
	${CC} -o $(NAME) $(OBJS) $(LIBFT) $(GNT) $(PRINT_F) $(MLX) $(MLX_FLAG)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C mlx clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean
	$(MAKE) -C ft_printf fclean

re: fclean all
