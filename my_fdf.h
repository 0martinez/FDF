/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:38:31 by omartine          #+#    #+#             */
/*   Updated: 2022/02/21 17:29:18 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FDF_H
# define MY_FDF_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

# define ON 1
# define OFF 0

typedef struct s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	int				width;
	int				height;
	float			zoom;
	float			angle;
	int				**int_matrix;
	char			**char_matrix;
	int				move_x;
	int				move_y;
	int				perspective;
	int				axe;
	int				rotation;
	float			x_rot;
	float			y_rot;
	int				z_rot;
	float			z_escalar;
	int				palette;

}	t_fdf;

char			**ft_split(char const *s, char c);
void			*free_split(char **aux, int words);
size_t			wordcount(char const *s, char c);

void			print_bresenham(float x, float y, float x2, float y2, t_fdf *fdf);

int				get_color(int j, int i, t_fdf *fdf);

int				**rotate_matrix__90(t_fdf *fdf);

int				hex_to_dec(char *str);

int				ft_atoi(const char *str);

void			get_maps(t_fdf *fdf, char *str);
void			get_char_matrix(t_fdf *fdf, char *str, int *i);
void			get_int_matrix(t_fdf *fdf, int i);

#endif
