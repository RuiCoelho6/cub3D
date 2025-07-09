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
VAL = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes
RM = rm -f


SRCS =  ./srcs/parsing/map/map_stf2.c ./srcs/parsing/color/color_getter_utils.c ./srcs/parsing/textures/init_texture.c ./srcs/parsing/textures/texture_sampling.c \
	./srcs/free_d.c ./srcs/parsing/map/map_stf.c ./srcs/parsing/color/color_getter.c ./srcs/parsing/textures/texture_getter.c \
	./srcs/parsing/textures/texture_color_finder.c ./srcs/parsing/parsing.c ./srcs/parsing/file/file_utils.c \
	./srcs/parsing/file/file_resourchs_getter.c \
	./libs/Get_Next_Line/get_next_line_bonus.c \
	./libs/Get_Next_Line/get_next_line_utils_bonus.c \
	./srcs/main.c \
	./srcs/window_controls.c\
	./srcs/ray/ray_casting_directions/horizontal_cast.c\
	./srcs/ray/ray_casting_directions/vertical_cast.c\
	./srcs/ray/ray_caster.c\
	./srcs/ray/draw/draw_utils.c\
	./srcs/ray/draw/draw.c\
	./srcs/player/player.c\
	./srcs/player/movement_controls.c\
	./srcs/parsing/color/float_color_init.c \

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

s: fclean mlx all
	./$(NAME) maps/strange_valid_map.cub

v: clean mlx $(NAME)
	@$(VAL) ./$(NAME) maps/strange_valid_map.cub

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