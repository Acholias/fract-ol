NAME = fractol

CC = cc

LIBFT_DIR = ./Libft
MLX_DIR = ./minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

SRC = setup_window.c \
		fractol_tools.c \
		mandelbrot.c \
		julia.c \
		burningship.c \
		color_set.c \
		color_set_bis.c \
		hook.c \
		choice_fractal.c \

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -I$(MLX_DIR) -I$(LIBFT_DIR)

MLX_FLG = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

MAKEFLAGS += -s --no-print-directory

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re