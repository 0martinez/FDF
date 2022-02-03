/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/03 16:09:37 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = 100;
	int		y = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (x != 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		x++;
	}
	while (y != 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		y++;
	}
	while (x != 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		x--;
	}
	while (y != 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		y--;
	}
	x = 300;
	y = 300;
	while (x != 450)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		my_mlx_pixel_put(&img, x, y + 1, 0x0000FF00);
		x++;
		y += 2;
	}
	while (x != 150)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		x--;
	}
	while (x != 300)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		my_mlx_pixel_put(&img, x, y - 1, 0x0000FF00);
		x++;
		y -= 2;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


/*
char	*copy_lane(char *line)
{
	char	*line_return;
	int		i;

	i = 0;
	line_return = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!line_return)
		return (0);
	line_return[ft_strlen(line)] = 0;
	while (line[i] != 0)
	{
		line_return[i] = line[i];
		i++;
	}
	return (line_return);
}

char	**matrix_splited(char *line, char **char_matrix)
{
	char	**new_matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!char_matrix)
	{
		new_matrix = (char **) malloc(sizeof(char *) * (i + 2));
		new_matrix[i + 1] = 0;
		new_matrix[i] = copy_lane(line);
		return (new_matrix);
	}
	while (char_matrix[i] != 0)
		i++;
	new_matrix = (char **) malloc(sizeof(char *) * (i + 2));
	if (!new_matrix)
		return (0);
	new_matrix[i + 1] = 0;
	while (char_matrix[j] != 0)
	{
		new_matrix[j] = copy_lane(char_matrix[j]);
		j++;
	}
	new_matrix[i] = copy_lane(line);
	char_matrix = free_split(char_matrix, i);
	return (new_matrix);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;
	char	**char_matrix;

	i = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		char_matrix = matrix_splited(line, char_matrix);
		printf("%s", char_matrix[i]);
		if (!char_matrix)
			return (0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (0);
}*/
