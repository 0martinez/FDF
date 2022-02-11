/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:55:06 by omartine          #+#    #+#             */
/*   Updated: 2022/02/11 17:47:52 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"
/*
char	*management_color(char *str)
{
	int		i;
	char	**color;

	i = 0;
	color = ft_split(str, ',');
	if (!color)
		return (0);
	return (color[1]);
}

char	*get_string(int j, int i, t_fdf *fdf)
{
	int		len;
	int		itr;
	char	*str_color;

	len = i;
	itr = 0;
	while (fdf->char_matrix[j][len] != ' ')
		len++;
	str_color = (char *) malloc(sizeof(char) * (len - i) + 1);
	if (!str_color)
		return (0);
	str_color[len - i] = 0;
	while (fdf->char_matrix[j][i] != ' ' && i < len)
	{
		str_color[itr] = fdf->char_matrix[j][i];
		i++;
		itr++;
	}
	return (str_color);
}

char	*no_color(void)
{
	char	*color;

	color = malloc(sizeof(char) * (8 + 1));
	if (!color)
	color[0] = '0';
	color[1] = 'x';
	color[2] = '0';
	color[3] = '0';
	color[4] = 'f';
	color[5] = 'f';
	color[6] = '0';
	color[7] = '0';
	color[8] = 0;
	return (color);
}

char	*get_color(int j, int i, t_fdf *fdf)
{
	char	*str_color;
	char	*color;

	str_color = get_string(j, i, fdf);
	if (!str_color)
		return (0);
	if (wordcount(str_color, ',') == 2)
	{
		color = management_color(str_color);
		if (!color)
			return (0);
		return (color);
	}
	else if (wordcount(str_color, ',') == 1)
	{
		color = no_color();
		return (color);
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}*/
