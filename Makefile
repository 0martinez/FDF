# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 13:26:33 by omartine          #+#    #+#              #
#    Updated: 2022/02/05 18:26:37 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

LIB_MLX		= libmlx.dylib

SRCS =		fdf.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			split.c bresenham.c

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
