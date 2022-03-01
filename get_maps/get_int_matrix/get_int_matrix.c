/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:02:07 by omartine          #+#    #+#             */
/*   Updated: 2022/03/01 19:51:26 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

void	handle_jump_line(char **char_matrix, char *line,
	t_fdf *fdf, int *to_return)
{
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
}

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

int	*to_return_value(char **char_matrix, int *to_return, int *error)
{
	int	i;

	i = 0;
	while (char_matrix[i] != 0)
	{
		if (check_if_jump(char_matrix[i]) == 0 || char_matrix[i][0] != '\n')
			to_return[i] = get_int_to_return(char_matrix[i], error);
		i++;
	}
	free_aux(char_matrix);
	return (to_return);
}

int	*to_int_matrix(char *line, t_fdf *fdf, int *error)
{
	char	**char_matrix;
	int		*to_return;

	char_matrix = ft_split(line, ' ');
	if (!char_matrix)
		return (0);
	if (char_matrix[wordcount(line, ' ') - 1][0] == '\n')
	{
		fdf->width = wordcount(line, ' ') - 1;
		if (fdf->width == 0)
			return (handle_error_int(fdf, char_matrix, error));
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
	to_return = to_return_value(char_matrix, to_return, error);
	return (to_return);
}

void	get_int_matrix(t_fdf *fdf, int i, int *error)
{
	int	aux_width;
	int	j;

	j = 1;
	init_int_matrix(fdf, error, i);
	if (!fdf->int_matrix[0] || *error != 0)
		return ;
	aux_width = fdf->width;
	while (j < i)
	{
		fdf->int_matrix[j] = to_int_matrix(fdf->char_matrix[j], fdf, error);
		if (!fdf->int_matrix[j])
			return ;
		if (aux_width != fdf->width)
		{
			*error = MAP_ERROR;
			return ;
		}
		j++;
	}
}
