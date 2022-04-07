/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_matrix_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:35:43 by omartine          #+#    #+#             */
/*   Updated: 2022/03/04 16:52:26 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

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

void	free_aux(char **char_matrix)
{
	int	i;

	i = 0;
	while (char_matrix[i] != 0)
	{
		free(char_matrix[i]);
		i++;
	}
	free(char_matrix);
}

int	*handle_error_int(t_fdf *fdf, char **char_matrix, int *error)
{
	if (fdf->width == 0)
	{
		free_aux(char_matrix);
		*error = MAP_ERROR;
	}
	return (0);
}

void	init_int_matrix(t_fdf *fdf, int *error, int i)
{
	fdf->int_matrix = (int **) malloc(sizeof(int *) * (i + 1));
	if (!fdf->int_matrix)
		return ;
	fdf->int_matrix[0] = to_int_matrix(fdf->char_matrix[0], fdf, error);
	if (!fdf->int_matrix[0] || *error != 0)
	{
		if (*error == 0)
			*error = MAP_ERROR;
		if (*error == ATOI_ERROR)
			*error = 5;
	}
}
