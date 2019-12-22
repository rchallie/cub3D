# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 10:43:56 by rchallie          #+#    #+#              #
#    Updated: 2019/12/17 12:30:37 by excalibur        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MLX = -lmlx -framework OpenGL -framework AppKit -fsanitize=address
MLX = -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

NAME = Cub3D
NAMELIB = cub3d.a

SRCS = 	cub3d.c \
		utils/putstr_info.c \
		utils/get_line.c \
		sources/init_game.c \
		sources/description/window_size_from_string.c \
		sources/description/path_from_string.c \
		sources/description/color_from_string.c \
		sources/description/treat_desc.c \
		sources/description/treat_map.c \
		sources/managers/key_manager.c \
		sources/managers/loop_manager.c \
		sources/managers/window_manager.c \
		sources/engine/mini_map.c \
		sources/engine/player.c \
		sources/engine/image.c \
		sources/engine/raycasting.c \
		sources/engine/textures.c

OBJSRCS = $(SRCS:.c=.o)

$(NAME) : $(OBJSRCS)
	rm -rf Cub3D
	$(MAKE) bonus -C ./libft
	#gcc -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) ./libft/libft.a $(OBJSRCS) -o $(NAME)
	gcc $(OBJSRCS) -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJSRCS)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf $(NAMELIB)

re : fclean all
