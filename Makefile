NAME = fdf

SRC = ./fdf.c \
		./parsing.c \
		./utils.c \
		./connect.c \
		./windows_manag.c \
		./bresenham.c \
		./isometric.c \
		./extra_color.c \

OBJS = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror

LIBFT = libft/libft.a

GNT = get_next_line/get_next_line.a

PRINT_F = ft_printf/ft_printf.a

${NAME}: ${OBJS}

	$(MAKE) -C libft
	$(MAKE) -C mlx
	${CC} -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAG)

all: ${NAME}


clean:

fclean:

re: