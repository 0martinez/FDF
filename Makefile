# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 13:26:33 by omartine          #+#    #+#              #
#    Updated: 2022/04/07 18:26:29 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
NAME_BONUS	= fdf_bonus

LIB_MLX		= libmlx.dylib

SRCS =		main.c utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c \
			utils/split.c utils/ft_atoi.c draw_map/draw_map.c draw_map/draw_map_utils/zoom.c\
			draw_map/draw_map_utils/bresenham.c draw_map/draw_map_utils/color_palette.c \
			draw_map/draw_map_utils/move_map.c draw_map/draw_map_utils/my_put_pixel.c \
			draw_map/draw_map_utils/perspective.c draw_map/draw_map_utils/rotate/rotate_map.c \
			get_maps/get_char_matrix/get_char_matrix.c get_maps/get_char_matrix/get_char_matrix_utils.c \
			get_maps/get_int_matrix/get_int_matrix.c \
			get_maps/get_int_matrix/get_int_matrix_utils.c get_maps/get_maps.c \
			get_maps/get_color.c get_maps/get_color_utils.c deal_keys/keys_management.c \
			deal_keys/handle_keys.c deal_keys/mouse_keys.c deal_keys/handle_keys_rotation.c \
			print_on_screen/controls_and_matrix.c draw_map/draw_map_utils/rotate/rotation.c \
			utils/to_be_free.c

SRCS_BONUS = bonus/main.c bonus/utils/get_next_line/get_next_line.c bonus/utils/get_next_line/get_next_line_utils.c \
			bonus/utils/split.c bonus/utils/ft_atoi.c bonus/draw_map/draw_map.c bonus/draw_map/draw_map_utils/zoom.c\
			bonus/draw_map/draw_map_utils/bresenham.c bonus/draw_map/draw_map_utils/color_palette.c \
			bonus/draw_map/draw_map_utils/move_map.c bonus/draw_map/draw_map_utils/my_put_pixel.c \
			bonus/draw_map/draw_map_utils/perspective.c bonus/draw_map/draw_map_utils/rotate/rotate_map.c \
			bonus/get_maps/get_char_matrix/get_char_matrix.c bonus/get_maps/get_char_matrix/get_char_matrix_utils.c \
			bonus/get_maps/get_int_matrix/get_int_matrix.c \
			bonus/get_maps/get_int_matrix/get_int_matrix_utils.c bonus/get_maps/get_maps.c \
			bonus/get_maps/get_color.c bonus/get_maps/get_color_utils.c bonus/deal_keys/keys_management.c \
			bonus/deal_keys/handle_keys.c bonus/deal_keys/mouse_keys.c bonus/deal_keys/handle_keys_rotation.c \
			bonus/print_on_screen/controls_and_matrix.c bonus/draw_map/draw_map_utils/rotate/rotation.c \
			bonus/utils/to_be_free.c

OBJS		= $(SRCS:.c=.o)

BONUS_O		= $(SRCS_BONUS:.c=.o)

FLAGS		= -Wall -Werror -Wextra #-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"

RM			= rm -rf

INC			= -I includes/ -Imlx

%.o: %.c
	gcc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(LIB_MLX):		$(MLX_OBJS)
			ar -r $(LIB_MLX) $(MLX_OBJS)
			ranlib $(LIB_MLX)

mlx_t:
		make -C mlx

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(FLAGS)	-o $(NAME)

clean:
		$(RM) $(OBJS) $(BONUS_O)
		make clean -C mlx

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(BONUS_O)
				$(CC) $(BONUS_O) -Lmlx -lmlx -framework OpenGL -framework AppKit $(FLAGS) -o $(NAME_BONUS)

rebonus:	fclean $(NAME) $(NAME_BONUS)

.PHONY:		all clean fclean re
