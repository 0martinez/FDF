/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:02:07 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 17:54:59 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

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
	char	*line_aux;
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
			{
				line_aux = no_jump_line(char_matrix[i]);
				to_return[i] = ft_atoi(line_aux);
				free(line_aux);
			}
		}
		i++;
	}
	i = 0;
	while (char_matrix[i] != 0)
	{
		free(char_matrix[i]);
		i++;
	}
	free(char_matrix);
	return (to_return);
}

void	get_int_matrix(t_fdf *fdf, int i)
{
	int	aux_width;
	int	j;

	j = 0;
	fdf->int_matrix = (int **) malloc(sizeof(int *) * (i + 1));
	if (!fdf->int_matrix)
		return ;
	fdf->int_matrix[j] = to_int_matrix(fdf->char_matrix[j], fdf);
	if (!fdf->int_matrix[j])
		return ;
	aux_width = fdf->width;
	j++;
	while (j < i)
	{
		fdf->int_matrix[j] = to_int_matrix(fdf->char_matrix[j], fdf);
		if (!fdf->int_matrix[j])
			return ;
		if (aux_width != fdf->width)
		{
			printf("map error");
			return ;
		}
		j++;
	}
}
