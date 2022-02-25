/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:38:31 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 18:44:36 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FDF_H
# define MY_FDF_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "utils/get_next_line/get_next_line.h"

# define ON 1
# define OFF 0
# define FOR_X 0
# define FOR_Y 1
# define MAP_ERROR 1
# define COLOR_ERROR 1
# define EMPTY_LINE 2

typedef struct s_axes
{
	float	x;
	float	y;
	int		z;
}	t_axes;

typedef struct s_aux
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z2;
	int		color;
}	t_aux;

typedef struct s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;

	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				exit;
	int				width;
	int				height;
	float			zoom;
	float			angle;
	int				**int_matrix;
	char			**char_matrix;
	int				**color_matrix;
	int				move_x;
	int				move_y;
	int				perspective;
	int				axe;
	int				rotation;
	float			x_rot;
	float			y_rot;
	float			z_rot;
	int				selected_axis;
	float			z_escalar;
	int				palette;

}	t_fdf;

char			**ft_split(char const *s, char c);
void			*free_split(char **aux, int words);
size_t			wordcount(char const *s, char c);

void			print_bresenham(t_axes first, t_axes second, t_fdf *fdf);

int				get_color(int j, int i, t_fdf *fdf);

int				**rotate_matrix__90(t_fdf *fdf);

int				hex_to_dec(char *str);

int				ft_atoi(const char *str);

void			get_maps(t_fdf *fdf, char *str);
void			get_char_matrix(t_fdf *fdf, char *str, int *i);
void			get_int_matrix(t_fdf *fdf, int i, int *error);
void			get_color_matrix(t_fdf *fdf);

int				check_color_error(char c);
int				hex_to_dec(char *str);

int				deal_key(int key, t_fdf *fdf);
int				mouse_hook(int key, int x, int y, t_fdf *fdf);
void			handle_moves(int key, t_fdf *fdf);
void			handle_zoom(int key, t_fdf *fdf);
void			handle_perspective(int key, t_fdf *fdf);
void			handle_palette(int key, t_fdf *fdf);
void			handle_key_rotation(t_fdf *fdf, int key);

void			draw_map(t_fdf *fdf);

void			print_controls(t_fdf *fdf);
void			draw_map(t_fdf *fdf);
void			draw_map_process(t_fdf *fdf);

void			rotate_x_exe(t_axes *first, t_axes *second, t_fdf *fdf);
void			rotate_y_exe(t_axes *first, t_axes *second, t_fdf *fdf);
void			rotate_z_exe(t_axes *first, t_axes *second, t_fdf *fdf);

int				check_if_jump(char *line);
char			*no_jump_line(char *line);
void			free_aux(char **char_matrix);
void			handle_jump_line(char **char_matrix, char *line,
					t_fdf *fdf, int *to_return);
void			handle_error(t_fdf *fdf, int aux_width, int *error, int j);
void			check_error_int(t_fdf *fdf, int *error, int aux_width, int j);
int				*get_return_value(char *line, char **char_matrix);
t_fdf			*handle_diferent_length(t_fdf *fdf, int j);

void			isometric(int z, t_fdf *fdf, t_axes *axe);
void			apply_perspecive(t_fdf *fdf, t_axes *first, t_axes *second);
void			bresenham(t_axes first, t_axes second, t_aux *src);
int				apply_palette(float y, float x, t_fdf *fdf);
void			apply_rotation(t_axes *first, t_axes *second, t_fdf *fdf);
void			apply_zoom(t_axes *first, t_axes *second, t_fdf *fdf);
void			my_mlx_pixel_put(t_fdf *fdf, float x, float y, int color);
void			move_map(t_axes *first, t_axes *second, t_fdf *fdf);

t_fdf			*to_be_free(t_fdf *fdf);

void			leaks(void);

#endif
