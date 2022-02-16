/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:46:04 by omartine          #+#    #+#             */
/*   Updated: 2022/02/16 13:55:22 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

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

char	**char_matrix_management(t_fdf fdf, char **argv)
{
	char	*line;
	int		fd;

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
