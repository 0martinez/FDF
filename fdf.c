/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:08:26 by omartine          #+#    #+#             */
/*   Updated: 2022/02/19 17:44:12 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

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

struct s_fdf	init_struct(void)
{
	t_fdf	fdf;

	fdf.height = 0;
	fdf.width = 0;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "first_try");
	fdf.zoom = 5;
	return (fdf);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		aux_width;
	t_fdf	fdf;

	i = 0;
	j = 0;
	fdf = init_struct();
	if (argc != 2)
		return (0);
	fdf = get_char_matrix(fdf, argv[1], &i);
	fdf.int_matrix = (int **) malloc(sizeof(int *) * (i));
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
	//fdf.int_matrix = rotate_matrix__90(&fdf);
	//fdf.int_matrix = rotate_matrix__90(&fdf);
	//fdf.int_matrix = rotate_matrix__90(&fdf);
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
