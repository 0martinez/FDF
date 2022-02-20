/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:38:31 by omartine          #+#    #+#             */
/*   Updated: 2022/02/17 17:22:35 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FDF_H
# define MY_FDF_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	int		width;
	int		height;
	int		move_x;
	int		move_y;
	int		zoom;
	int		perspective;
	int		**int_matrix;
	char	**char_matrix;
	int		error;
}	t_fdf;

char			**ft_split(char const *s, char c);
void			*free_split(char **aux, int words);
size_t			wordcount(char const *s, char c);

void			print_bresenham(float x, float y, float x2, float y2, t_fdf *fdf);

int				get_color(int j, int i, t_fdf *fdf);

int				**rotate_matrix__90(t_fdf *fdf);

int				hex_to_dec(char *str);

int				ft_atoi(const char *str);

struct s_fdf	get_char_matrix(t_fdf fdf, char *str, int *i);
struct s_fdf	get_int_matrix(t_fdf fdf, int i);

#endif
