/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:53:19 by omartine          #+#    #+#             */
/*   Updated: 2022/02/28 13:43:41 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

int	check_color_error(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	if (c >= 'A' && c <= 'F')
		return (0);
	if (c >= 'a' && c <= 'f')
		return (0);
	if (c == 'x' || c == '\n')
		return (0);
	return (1);
}

int	hex_to_dec_error(int *error)
{
	*error = ERROR_COLOR;
	return (0);
}

int	hex_to_dec(char *str, int *error)
{
	int	l;
	int	dec;
	int	base;

	l = ft_strlen(str);
	base = 1;
	dec = 0;
	if (l > 9 || l <= 2)
		return (hex_to_dec_error(error));
	while (l-- > 0)
	{
		if (check_color_error(str[l]) == 1 && l != 0)
		{
			*error = ERROR_COLOR;
			return (0);
		}
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
