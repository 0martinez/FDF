/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:54:12 by omartine          #+#    #+#             */
/*   Updated: 2022/02/12 19:31:14 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
//#include "my_fdf.h"

/*
int main(void)
{
	float	x;
	float	y;
	float	x2;
	float	y2;
	char str[8] = "0xffffff";

	x = 0;
	y = 0;
	x2 = 1;
	y2 = 0;

	printf("%lu", (unsigned long int)"0xffffff");
	return (0);
}*/
/*
void	isometric(float *x, float *y, float z)
{
	*x = ((int)*x - (int)*y) * cos(0.8);
	*y = ((int)*x + (int)*y) * sin(0.8) - z;
}

int	main(void)
{
	float	x;
	float	y;
	float	z;

	x = 2;
	y = 3;
	z = 4;
	isometric(&x, &y, z);
	printf("(%f)---(%f)---(%f)", x, y, z);
	return (0);
}*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_hexa(char *str)
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

int main(void)
{
	int	a = 0x00ff00;

	a = ft_hexa("0x00ff00");
	printf("%d", a);
	return (0);
}
