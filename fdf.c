/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/12 20:12:01 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

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

int	*to_int_matrix(char *line, t_fdf *fdf)
{
	char	**char_matrix;
	int		*to_return;
	int		i;

	i = 0;
	char_matrix = ft_split(line, ' ');
	if (!char_matrix)
		return (0);
	if (char_matrix[wordcount(line, ' ') - 1][0] == '\n')
	{
		fdf->width = wordcount(line, ' ') - 1;
		to_return = malloc(sizeof(int) * wordcount(line, ' ') - 1);
		char_matrix[wordcount(line, ' ') - 1] = 0;
	}
	else
	{
		to_return = (int *) malloc(sizeof(int) * wordcount(line, ' '));
		fdf->width = wordcount(line, ' ');
	}
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
		i++;
	}
	char_matrix = free_split(char_matrix, wordcount(line, ' '));
	return (to_return);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		j;
	char	*line;
	int		aux_width;
	t_fdf	fdf;

	i = 0;
	j = 0;
	fdf.height = 0;
	fdf.width = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != 0)
	{
		fdf.char_matrix = matrix_splited(line, fdf.char_matrix);
		fdf.height++;
		if (!fdf.char_matrix)
			return (0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	fdf.int_matrix = (int **) malloc(sizeof(int *) * (i + 1));
	if (!fdf.int_matrix)
		return (0);
	fdf.int_matrix[j] = to_int_matrix(fdf.char_matrix[j], &fdf);
	if (!fdf.int_matrix[j])
		return (0);
	aux_width = fdf.width;
	j++;
	while (j < i)
	{
		fdf.int_matrix[j] = to_int_matrix(fdf.char_matrix[j], &fdf);
		if (!fdf.int_matrix[j])
			return (0);
		if (aux_width != fdf.width)
		{
			printf("map error");
			return (0);
		}
		j++;
	}
	i = 0;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "first_try");
	fdf.zoom = 2;
	j = 0;
	i = 0;
	while (j < fdf.height)
	{
		i = 0;
		while (i < fdf.width)
		{
			if (i < fdf.width - 1)
				print_bresenham(i, j, i + 1, j, &fdf);
			if (j < fdf.height - 1)
				print_bresenham(i, j, i, j + 1, &fdf);
			i++;
		}
		j++;
	}
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
