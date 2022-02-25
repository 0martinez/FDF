# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 13:26:33 by omartine          #+#    #+#              #
#    Updated: 2022/02/25 12:50:17 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

LIB_MLX		= libmlx.dylib

SRCS =		main.c utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c \
			utils/split.c utils/ft_atoi.c draw_map/draw_map.c draw_map/draw_map_utils/zoom.c\
			draw_map/draw_map_utils/bresenham.c draw_map/draw_map_utils/color_palette.c \
			draw_map/draw_map_utils/move_map.c draw_map/draw_map_utils/my_put_pixel.c \
			draw_map/draw_map_utils/perspective.c draw_map/draw_map_utils/rotate/rotate_map.c \
			get_maps/get_char_matrix.c get_maps/get_int_matrix/get_int_matrix.c \
			get_maps/get_int_matrix/get_int_matrix_utils.c get_maps/get_maps.c \
			get_maps/get_color.c deal_keys/keys_management.c deal_keys/handle_keys.c \
			deal_keys/mouse_keys.c deal_keys/handle_keys_rotation.c \
			print_on_screen/controls_and_matrix.c draw_map/draw_map_utils/rotate/rotation.c \
			utils/to_be_free.c

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

INC			= -I includes/ -Imlx

%.o: %.c
	cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(LIB_MLX):		$(MLX_OBJS)
			ar -r $(LIB_MLX) $(MLX_OBJS)
			ranlib $(LIB_MLX)

mlx_t:
		make -C mlx

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS)	-o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C mlx

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
