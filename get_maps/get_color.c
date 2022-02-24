/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:55:06 by omartine          #+#    #+#             */
/*   Updated: 2022/02/24 17:39:21 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

int	hex_to_dec(char *str)
{
	int	l;
	int	dec;
	int	base;

	l = ft_strlen(str);
	base = 1;
	dec = 0;
	while (l-- > 0)
	{
		if (str[l] >= '0' && str[l] <= '9')
			dec += (str[l] - 48) * base;
		else if (str[l] >= 'A' && str[l] <= 'F')
			dec += (str[l] - 55) * base;
		else if (str[l] >= 'a' && str[l] <= 'f')
			dec += (str[l] - 87) * base;
		base *= 16;
	}
	return (dec);
}

int	management_color(char *str)
{
	int		color;
	char	**color_str;
	int		i;

	i = 0;
	color_str = ft_split(str, ',');
	if (!color_str)
		return (0);
	color = hex_to_dec(color_str[1]);
	while (color_str[i] != 0)
	{
		free(color_str[i]);
		i++;
	}
	free(color_str);
	return (color);
}

int	get_color(int j, int i, t_fdf *fdf)
{
	int		color;
	int		len;
	char	**split;

	len = 0;
	split = ft_split(fdf->char_matrix[j], ' ');
	if (!split)
		return (0);
	if (wordcount(split[i], ',') == 2)
		color = management_color(split[i]);
	else if (wordcount(split[i], ',') == 1)
		color = 0xffffff;
	else
		printf("wtf");
	while (split[len] != 0)
	{
		free(split[len]);
		len++;
	}
	free(split);
	return (color);
}

int	*get_color_pointer(t_fdf *fdf, int j)
{
	int	*color_str;
	int	i;

	color_str = (int *) malloc(sizeof(int) * fdf->width);
	if (!color_str)
		return (0);
	i = 0;
	while (i < fdf->width)
	{
		color_str[i] = get_color(j, i, fdf);
		i++;
	}
	return (color_str);
}

void	get_color_matrix(t_fdf *fdf)
{
	int	j;

	j = 0;
	fdf->color_matrix = (int **) malloc(sizeof(int *) * fdf->height);
	if (!fdf->color_matrix)
		return ;
	while (j < fdf->height)
	{
		fdf->color_matrix[j] = get_color_pointer(fdf, j);
		j++;
	}
}
