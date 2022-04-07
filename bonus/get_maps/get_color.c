/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:55:06 by omartine          #+#    #+#             */
/*   Updated: 2022/02/28 13:17:19 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

int	management_color(char *str, int *error)
{
	int		color;
	char	**color_str;
	int		i;

	i = 0;
	color_str = ft_split(str, ',');
	if (!color_str)
		return (0);
	if (color_str[1][0] != 0)
		color = hex_to_dec(color_str[1], error);
	else
	{
		color = 0;
		*error = COLOR_ERROR;
	}
	while (color_str[i] != 0)
	{
		free(color_str[i]);
		i++;
	}
	free(color_str);
	return (color);
}

int	get_color(int j, int i, t_fdf *fdf, int *error)
{
	int		color;
	int		len;
	char	**split;

	len = 0;
	split = ft_split(fdf->char_matrix[j], ' ');
	if (!split)
		return (0);
	if (wordcount(split[i], ',') == 2)
		color = management_color(split[i], error);
	else if (wordcount(split[i], ',') == 1)
		color = 0xffffff;
	else
		return (0);
	while (split[len] != 0)
	{
		free(split[len]);
		len++;
	}
	free(split);
	return (color);
}

int	*get_color_pointer(t_fdf *fdf, int j, int *error)
{
	int	*color_str;
	int	i;

	color_str = (int *) malloc(sizeof(int) * fdf->width);
	if (!color_str)
		return (0);
	i = 0;
	while (i < fdf->width && *error == 0)
	{
		color_str[i] = get_color(j, i, fdf, error);
		i++;
	}
	return (color_str);
}

void	get_color_matrix(t_fdf *fdf, int *error)
{
	int	j;

	j = 0;
	fdf->color_matrix = (int **) malloc(sizeof(int *) * fdf->height);
	if (!fdf->color_matrix)
		return ;
	while (j < fdf->height && *error == 0)
	{
		fdf->color_matrix[j] = get_color_pointer(fdf, j, error);
		j++;
	}
}
