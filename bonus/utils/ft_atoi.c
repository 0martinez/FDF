/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:52:16 by omartine          #+#    #+#             */
/*   Updated: 2022/03/04 17:28:33 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

int	atoi_error(int *error)
{
	*error = ATOI_ERROR;
	return (0);
}

int	check_no_color(const char *str, int i)
{
	if (str[i] != 0)
	{
		if (str[i] == ',' && str[i + 1] == 0)
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, int *error)
{
	int		simb;
	long	num;
	int		i;

	i = 0;
	num = 0;
	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
		i++;
	}
	if (str[i] == 0 || str[i] == ',')
		return (atoi_error(error));
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((str[i] != 0 && str[i] != ',')
		|| num * simb > 2147483647 || num * simb < -2147483648
		|| check_no_color(str, i) == 1)
		return (atoi_error(error));
	return (simb * num);
}
