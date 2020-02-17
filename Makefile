# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 10:43:56 by rchallie          #+#    #+#              #
#    Updated: 2020/01/17 08:57:55 by rchallie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -lmlx -lm -framework OpenGL -framework AppKit
#MLX = -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

NAME = cub3D

SRCS = 	cub3d.c \
		utils/putstr_info.c \
		utils/get_line.c \
		utils/utils.c \
		utils/bitmap.c \
		sources/init_game.c \
		sources/description/window_size_from_string.c \
		sources/description/path_from_string.c \
		sources/description/color_from_string.c \
		sources/description/treat_desc.c \
		sources/description/treat_map.c \
		sources/managers/key_manager.c \
		sources/managers/loop_manager.c \
		sources/managers/window_manager.c \
		sources/engine/player.c \
		sources/engine/image.c \
		sources/engine/raycasting.c \
		sources/engine/raycasting_2.c \
		sources/engine/textures.c \
		sources/engine/camera.c \
		sources/engine/draw_sprite.c \
		sources/engine/sprite.c

SRCS_BONUS = 	bonus/engine/bonus_camera.c \
				bonus/engine/bonus_health.c \
				bonus/managers/bonus_key_manager.c \
				bonus/engine/bonus_sound.c \
				bonus/init_bonus.c

OBJSRCS = $(SRCS:.c=.o) 
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS) $(OBJSRCSBONUS)
	@echo "\033[33m[Remove last version...]"
	@rm -rf Cub3D
	@echo "\033[33m[Libft compilation...]"
	@$(MAKE) bonus -C ./libft
	@echo "\033[33m[Cub3D compilation...]"
	@gcc $(OBJSRCSBONUS) $(OBJSRCS) -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)
	@echo "\033[33m[Done !]"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS) $(OBJSRCSBONUS)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all

bonus : $(NAME)
