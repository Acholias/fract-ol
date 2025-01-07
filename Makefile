# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 10:50:13 by lumugot           #+#    #+#              #
#    Updated: 2025/01/07 12:01:43 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET  := \033[0m
RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
BLUE   := \033[34m
MAGENTA := \033[35m
CYAN   := \033[36m
WHITE  := \033[37m
BOLD   := \033[1m


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
	@echo "$(BOLD)$(YELLOW)Building Libft ...$(RESET)"
	sleep 1;
	@echo "$(BOLD)$(GREEN)Libft is ready ✅$(RESET)"

$(MLX):
	$(MAKE) -C $(MLX_DIR)
	@echo "$(BOLD)$(YELLOW)Building MLX ...$(RESET)"
	sleep 1;
	@echo "$(BOLD)$(GREEN)MLX is ready ✅$(RESET)"
	sleep 1;
	@echo "$$BANNER"
	sleep 1;
	@echo "$(BOLD)$(MAGENTA)Here are the commands:$(RESET)"
	@echo "$(BOLD)$(CYAN)✵ <F1 or F2> To change the color palettes$(RESET)"
	@echo "$(BOLD)$(CYAN)✵ <ESCAPE> To close the window$(RESET)"
	@echo "$(BOLD)$(CYAN)✵ <ARROWS> To move (up, down, left, right)$(RESET)"
	@echo "$(BOLD)$(CYAN)✵ <PgUp> To increase the number of iterations$(RESET)"
	@echo "$(BOLD)$(CYAN)✵ <PgDn> To decrease the number of iterations$(RESET)"
	@echo "$(BOLD)$(CYAN)✵ <SPACE> To move the Julia sets with the mouse$(RESET)"
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)
	@echo "$(BOLD)$(RED)❄ Remove all $(OBJS)$(RESET)"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo "$(BOLD)$(RED)❄ Remove $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re

define BANNER

\033[38;5;196m░▒▓████████▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░       
\033[38;5;202m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       
\033[38;5;208m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       
\033[38;5;214m░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       
\033[38;5;220m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       
\033[38;5;226m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       
\033[38;5;190m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  ░▒▓█▓▒░   ░▒▓██████▓▒░░▒▓████████▓▒░
\033[0m

endef
export BANNER