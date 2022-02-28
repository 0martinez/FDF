/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:02:07 by omartine          #+#    #+#             */
/*   Updated: 2022/02/28 12:59:29 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

int	get_int_to_return(char *char_matrix, int *error)
{
	char	*line_aux;
	int		to_return;

	if (check_if_jump(char_matrix) == 0)
		to_return = ft_atoi(char_matrix, error);
	else
	{
		line_aux = no_jump_line(char_matrix);
		to_return = ft_atoi(line_aux, error);
		free(line_aux);
	}
	return (to_return);
}

char	**handle_char_matrix_value(t_fdf *fdf, char *line, int *error)
{
	char	**char_matrix;

	char_matrix = ft_split(line, ' ');
	if (!char_matrix)
		return (0);
	if (char_matrix[wordcount(line, ' ') - 1][0] == '\n')
	{
		fdf->width = wordcount(line, ' ') - 1;
		if (fdf->width == 0)
		{
			free_aux(char_matrix);
			*error = MAP_ERROR;
			return (0);
		}
		char_matrix[wordcount(line, ' ') - 1] = 0;
	}
	else
		fdf->width = wordcount(line, ' ');
	return (char_matrix);
}

int	*to_int_matrix(char *line, t_fdf *fdf, int *error)
{
	char	**char_matrix;
	int		*to_return;
	int		i;

	i = 0;
	char_matrix = handle_char_matrix_value(fdf, line, error);
	if (*error != 0 || !char_matrix)
		return (0);
	to_return = get_return_value(line, char_matrix);
	if (!to_return)
		return (0);
	while (char_matrix[i] != 0)
	{
		if (check_if_jump(char_matrix[i]) == 0 || char_matrix[i][0] != '\n')
			to_return[i] = get_int_to_return(char_matrix[i], error);
		i++;
	}
	free_aux(char_matrix);
	return (to_return);
}

t_fdf	*handle_diferent_length(t_fdf *fdf, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(fdf->int_matrix[i]);
		i++;
	}
	free(fdf->int_matrix);
	return (fdf);
}

void	get_int_matrix(t_fdf *fdf, int i, int *error)
{
	int	aux_width;
	int	j;

	j = 1;
	fdf->int_matrix = (int **) malloc(sizeof(int *) * (i + 1));
	if (!fdf->int_matrix)
		return ;
	fdf->int_matrix[j - 1] = to_int_matrix(fdf->char_matrix[j - 1], fdf, error);
	if (!fdf->int_matrix[j - 1] || *error != 0)
	{
		free(fdf->int_matrix);
		*error = MAP_ERROR;
		return ;
	}
	aux_width = fdf->width;
	while (j < i)
	{
		fdf->int_matrix[j] = to_int_matrix(fdf->char_matrix[j], fdf, error);
		if (!fdf->int_matrix[j] || aux_width != fdf->width || *error != 0)
		{
			handle_error(fdf, aux_width, error, j);
			return ;
		}
		j++;
	}
}
