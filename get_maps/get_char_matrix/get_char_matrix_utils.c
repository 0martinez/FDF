/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_matrix_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:22:37 by omartine          #+#    #+#             */
/*   Updated: 2022/03/04 15:26:36 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_fdf.h"

int	new_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

int	check_if_jump_alone(char *str)
{
	int	jump;

	jump = new_strlen(str);
	if (str[jump - 1] == ' ')
		return (1);
	return (0);
}

char	*new_line_value(char *str)
{
	int		jump;
	int		i;
	char	*new_line;

	jump = new_strlen(str);
	i = 0;
	while (str[jump] == ' ' || str[jump] == '\n')
		jump--;
	new_line = (char *) malloc(sizeof(char) * jump + 2);
	if (!new_line)
		return (0);
	new_line[jump + 1] = 0;
	while (i <= jump)
	{
		new_line[i] = str[i];
		i++;
	}
	free(str);
	return (new_line);
}
