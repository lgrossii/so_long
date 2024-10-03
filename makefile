# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 16:02:31 by lorenzogros       #+#    #+#              #
#    Updated: 2024/08/29 16:21:50 by lorenzogros      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS ####################################################################
GREEN				=	\033[0;32m
BLUE				=	\033[0;34m
RED					=	\033[0;31m
RESET				=	\033[0m
### DIRECTORIES ###############################################################
D_FT_PRINTF			=	ft_printf
D_LIBFT				=	libft
GIT_REPO_LIBFT		=	https://github.com/lgrossii/libft
GIT_REPO_FT_PRINTF	=	https://github.com/lgrossii/ft_printf
### FILES #####################################################################
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
MLX_PATH	=	src/mlx
MLX			=	$(MLX_PATH)/libmlx.a
### COMPILATION ##############################################################
CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
MAKEFLAGS	+=-s
LINKER_MLX = -Lsrc/mlx -lmlx -framework OpenGL -framework AppKit
### RULES #####################################################################
all : dependencies $(NAME) 

dependencies:
					echo "$(GREEN)- - - Checking all dependencies  - - -$(RESET)"
					@if [ ! -d $(LIBFT_PATH) ]; then \
					echo "$(RED)!!!!! LIBFT MISSING,  cloning it !!!!!$(RESET)"; \
					git clone $(GIT_REPO_LIBFT) $(LIBFT_PATH); \
					fi
					@if [ ! -d $(PRINTF_PATH) ]; then \
					echo "$(RED)!!!!! ft_printf MISSING,  cloning it     !!!!!$(RESET)"; \
					git clone $(GIT_REPO_FT_PRINTF) $(PRINTF_PATH); \
					fi
					echo "$(GREEN)- - - Dependencies checked √     - - -$(RESET) "


$(PRINTF):
				make -s -C $(PRINTF_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}
				make clean -C ${PRINTF_PATH}

$(NAME) : $(OBJECTS) $(LIBFT) $(PRINTF) $(MLX)
			$(CC) $(OBJECTS) $(LIBFT) $(PRINTF) $(LINKER_MLX) -g -o $(NAME)

$(LIBFT):
			make -s -C$(LIBFT_PATH)
$(PRINTF):
			make -s -C$(PRINTF_PATH)

$(MLX):
			make -s -C$(MLX_PATH)
			
clean:
			${RM} ${OBJECTS}
			make clean -C ${LIBFT_PATH}
			make  clean -C ${PRINTF_PATH}
			make clean -C ${MLX_PATH}

fclean:	clean
			${RM} $(NAME)
			${RM} $(LIBFT)

re:			fclean all

.PHONY:		all clean re
