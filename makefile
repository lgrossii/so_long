# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 16:02:31 by lorenzogros       #+#    #+#              #
#    Updated: 2023/10/23 18:16:12 by lgrossi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRC			=	main.c functions/textures_all.c functions/textures_player.c functions/moves.c \
				functions/render_animation.c functions/render_player_animation.c functions/render_singles.c \
				functions/utils_free.c functions/utils.c functions/textures_enemy.c functions/render_enemy_animation.c \
				functions/moves_enemy.c functions/check_map_00.c functions/check_map_01.c
HEADER		=	so_long.h
LIBFT_PATH	=	src/libft
LIBFT		=	$(LIBFT_PATH)/libft.a
PRINTF_PATH	=	src/ft_printf
PRINTF		=	$(PRINTF_PATH)/libftprintf.a
OBJECTS		=	$(SRC:.c=.o)
CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
MAKEFLAGS	+=-s
LINKER_MLX = -Lsrc/mlx -lmlx -framework OpenGL -framework AppKit
all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(PRINTF)
			$(CC) $(OBJECTS) $(LIBFT) $(PRINTF) $(LINKER_MLX) -g -o $(NAME)

$(LIBFT):
			make -s -C$(LIBFT_PATH)
$(PRINTF):
			make -s -C$(PRINTF_PATH)
clean:
			${RM} ${OBJECTS}
			make clean -C ${LIBFT_PATH}

fclean:	clean
			${RM} $(NAME)
			${RM} $(LIBFT)

re:			fclean all

.PHONY:		all clean re