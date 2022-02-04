/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/04 19:32:32 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"
/*
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
*/

int	ft_atoi(const char *str)
{
	int	simb;
	int	num;
	int	i;

	i = 0;
	num = 0;
	simb = 1;
	while (str[i] != 0 && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (simb * num);
}

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

char	**matrix_splited(char *line, char **char_matrix, t_fdf *fdf)
{
	char	**new_matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fdf->width = 0;
	if (!char_matrix)
	{
		new_matrix = (char **) malloc(sizeof(char *) * (i + 2));
		new_matrix[i + 1] = 0;
		new_matrix[i] = copy_lane(line);
		fdf->height++;
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
		fdf->width++;
	}
	new_matrix[i] = copy_lane(line);
	char_matrix = free_split(char_matrix, i);
	fdf->height++;
	return (new_matrix);
}

int	check_if_jump(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*no_jump_line(char *line)
{
	char	*new_line;
	int		i;

	new_line = (char *) malloc(sizeof(char) * ft_strlen(line));
	if (!new_line)
		return (0);
	i = 0;
	while (line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = 0;
	return (new_line);
}

int	*to_int_matrix(char *line)
{
	char	**char_matrix;
	int		*to_return;
	int		i;

	i = 0;
	char_matrix = ft_split(line, ' ');
	if (!char_matrix)
		return (0);
	if (char_matrix[wordcount(line, 0, 0, ' ') - 1][0] == '\n')
	{
		to_return = malloc(sizeof(int) * wordcount(line, 0, 0, ' ') - 1);
		char_matrix[wordcount(line, 0, 0, ' ') - 1] = 0;
	}
	else
		to_return = (int *) malloc(sizeof(int) * wordcount(line, 0, 0, ' '));
	if (!to_return)
		return (0);
	while (char_matrix[i] != 0)
	{
		if (check_if_jump(char_matrix[i]) == 0)
			to_return[i] = ft_atoi(char_matrix[i]);
		else
		{
			if (char_matrix[i][0] != '\n')
				to_return[i] = ft_atoi(no_jump_line(char_matrix[i]));
		}
		printf("%d ", to_return[i]);
		i++;
	}
	printf("\n");
	char_matrix = free_split(char_matrix, wordcount(line, 0, 0, ' '));
	return (to_return);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		j;
	char	*line;
	char	**char_matrix;
	int		**int_matrix;
	t_fdf	fdf;

	i = 0;
	j = 0;
	fdf.height = 0;
	fdf.width = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		char_matrix = matrix_splited(line, char_matrix, &fdf);
		if (!char_matrix)
			return (0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (fdf.height != fdf.width)
	{
		printf("%d\n\n\n%d", fdf.height, fdf.width);
		return (0);
	}

	int_matrix = (int **) malloc(sizeof(int *) * (i + 1));
	if (!int_matrix)
		return (0);
	while (j < i)
	{
		int_matrix[j] = to_int_matrix(char_matrix[j]);
		if (!int_matrix)
			return (0);
		j++;
	}
	printf("\n\n\n%d", fdf.height);
	return (0);
}
