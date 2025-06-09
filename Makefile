# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/06/09 10:57:18 by rpires-c          #+#    #+#             #
#    Updated: 2025/06/09 12:45:09 by rpires-c         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc -g
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = \
	./libs/Get_Next_Line/get_next_line_bonus.c \
	./libs/Get_Next_Line/get_next_line_utils_bonus.c \
	./srcs/main.c

OBJDIR = Objs
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
MLX_DIR = libs/minilibx-linux
LIB_DIR = libs/libft

# Rule to compile object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

# Main target
$(NAME): libft $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -lm -Iinc/mlx-linux -lXext -lX11 -L$(MLX_DIR) -lmlx -L$(LIB_DIR) -lft -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

all: $(NAME)

s: clean mlx $(NAME)
	@./$(NAME)

libft:
	@$(MAKE) -C $(LIB_DIR) > /dev/null
	@echo "╔═══════════════════╗"
	@echo "║ ✅ Libft compiled ║"
	@echo "╚═══════════════════╝"

mlx:
	@cd ./libs/minilibx-linux && make > /dev/null
	@echo "╔══════════════════════╗"
	@echo "║ ✅ Minilibx compiled ║"
	@echo "╚══════════════════════╝"

clean:
	@$(RM) -R $(OBJDIR)
	@$(MAKE) -C $(LIB_DIR) fclean > /dev/null 2>&1 || true
	@cd ./libs/minilibx-linux && make clean > /dev/null 2>&1 || true

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re s libft mlx