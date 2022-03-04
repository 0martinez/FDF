/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:52:16 by omartine          #+#    #+#             */
/*   Updated: 2022/03/04 14:16:40 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_fdf.h"

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((str[i] != 0 && str[i] != ',') || num * simb > 2147483647 || num * simb < -2147483648)
	{
		*error = ATOI_ERROR;
		return (0);
	}
	return (simb * num);
}
