/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:03:11 by omartine          #+#    #+#             */
/*   Updated: 2022/03/04 17:56:38 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

void	free_char_matrix(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->char_matrix[i] != 0)
	{
		free(fdf->char_matrix[i]);
		i++;
	}
	free(fdf->char_matrix);
}

void	free_int_matrix(t_fdf *fdf, int error)
{
	int	i;

	i = 0;
	if (error == 5)
		return ;
	while (i < fdf->height)
	{
		free(fdf->int_matrix[i]);
		i++;
	}
}

void	handle_map_error(t_fdf *fdf, int flg, int error)
{
	int	i;

	i = 0;
	if (!fdf->char_matrix)
	{
		write(1, "MAP ERROR...\n", 13);
		write(1, "EXIT SUCCES\n", 12);
		exit (0);
	}
	if (flg != 0 && error != 0)
	{
		if (error == EMPTY_LINE || error == ATOI_ERROR || error == 5)
			free_int_matrix(fdf, error);
		write(1, "MAP ERROR", 9);
		exit (0);
	}
}

void	get_maps(t_fdf *fdf, char *str)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	write(1, "READING MAP...\n", 15);
	get_char_matrix(fdf, str, &i);
	handle_map_error(fdf, 1, error);
	write(1, "CONVERTING MAP...\n", 18);
	get_int_matrix(fdf, i, &error);
	handle_map_error(fdf, 2, error);
	write(1, "APPLYING THE COLORS...\n", 23);
	get_color_matrix(fdf, &error);
	handle_map_error(fdf, 3, error);
	write(1, "--PRINTING MAP--\n", 17);
}
