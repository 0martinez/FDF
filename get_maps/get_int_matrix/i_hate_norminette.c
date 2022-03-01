/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_hate_norminette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:40:45 by omartine          #+#    #+#             */
/*   Updated: 2022/03/01 13:12:06 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

void	check_error_int(t_fdf *fdf, int *error, int aux_width, int j)
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

int	*get_return_value(char *line, char **char_matrix)
{
	int	*to_return;

	write(1, "5\n", 2);
	getchar();
	if (char_matrix[wordcount(line, ' ') - 1][0] == '\n')
		to_return = (int *) malloc(sizeof(int) * wordcount(line, ' ') - 1);
	else
		to_return = (int *) malloc(sizeof(int) * wordcount(line, ' '));
	return (to_return);
}
