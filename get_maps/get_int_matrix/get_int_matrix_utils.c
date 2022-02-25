/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_matrix_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:35:43 by omartine          #+#    #+#             */
/*   Updated: 2022/02/25 18:40:12 by omartine         ###   ########.fr       */
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

void	handle_error(t_fdf *fdf, int aux_width, int *error, int j)
{
	if (!fdf->int_matrix[j])
		return ;
	if (aux_width != fdf->width || *error != 0)
	{
		*error = MAP_ERROR;
		fdf = handle_diferent_length(fdf, j);
		return ;
	}
}
