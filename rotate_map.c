/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:15:00 by omartine          #+#    #+#             */
/*   Updated: 2022/02/19 17:41:50 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"
/*
void	rotate_matrix(t_fdf *fdf)
{
	int	row;
	int	height;
	int	width;
	int	col;
	int	prev;
	int	curr;
	int	i;

	height = fdf->height;
	width = fdf->width;
	row = 0;
	col = 0;
	while (row < height && col < width)
	{
		if (row + 1 == height || col + 1 == width)
			break ;
		prev = fdf->int_matrix[row + 1][col];
		i = col;
		while (i < width)
		{
			curr = fdf->int_matrix[row][i];
			fdf->int_matrix[row][i] = prev;
			prev = curr;
			i++;
		}
		row++;
		i = row;
		while (i < height)
		{
			curr = fdf->int_matrix[i][width - 1];
			fdf->int_matrix[i][width - 1] = prev;
			prev = curr;
			i++;
		}
		width--;
		if (row < height)
		{
			i = width - 1;
			while (i >= col)
			{
				curr = fdf->int_matrix[height - 1][i];
				fdf->int_matrix[height - 1][i] = prev;
				prev = curr;
				i--;
			}
		}
		height--;
		if (col < width)
		{
			i = height - 1;
			while (i >= row)
			{
				curr = fdf->int_matrix[i][col];
				fdf->int_matrix[i][col] = prev;
				prev = curr;
				i--;
			}
		}
		col++;
	}
}*/

int	**rotate_matrix__90(t_fdf *fdf)
{
	int	i;
	int	j;
	int	**new_matrix;

	new_matrix = (int **) malloc(sizeof(int *) * (fdf->width));
	if (!new_matrix)
		return (0);
	i = 0;
	while (i < fdf->width)
	{
		new_matrix[i] = (int *) malloc(sizeof(int) * (fdf->height));
		i++;
	}
	i = 0;
	j = 0;
	while (i < fdf->width)
	{
		j = 0;
		while (j < fdf->height)
		{
			new_matrix[j][fdf->height - 1 - i] = fdf->int_matrix[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < fdf->height)
	{
		free(fdf->int_matrix[i]);
		i++;
	}
	free(fdf->int_matrix);
	return (new_matrix);
}


/*
int	**rotate_matrix__90(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x = 0;
	int	y = 0;
	int	**new_matrix;

	new_matrix = (int **) malloc(sizeof(int *) * (fdf->width));
	if (!new_matrix)
		return (0);
	i = 0;
	while (i < fdf->width)
	{
		new_matrix[i] = (int *) malloc(sizeof(int) * (fdf->height));
		i++;
	}
	i = 0;
	j = 0;
	while (j < fdf->width)
	{
		i = 0;
		y = 0;
		while (i < fdf->height)
		{
			new_matrix[j][i] = fdf->int_matrix[y][x];
			y++;
			i++;
		}
		x++;
		j++;
		if (i == fdf->height && j == fdf->width)
			break ;
	}
	i = 0;
	while (i < fdf->height)
	{
		free(fdf->int_matrix[i]);
		i++;
	}
	free(fdf->int_matrix);
	return (new_matrix);
}*/
