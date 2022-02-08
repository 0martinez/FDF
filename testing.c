/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:54:12 by omartine          #+#    #+#             */
/*   Updated: 2022/02/08 17:05:03 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

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

int	ft_atoi(const char *str, t_stack_gen *st)
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
		if (str[i] == 0)
		{
			st->error = 2;
			return (0);
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (str[i] != 0 || num * simb > 2147483647 || num * simb < -2147483648)
		st->error = 2;
	return ((int )num * simb);
}

int main(void)
{
	float x = cos(0.8);
	printf("%f", x);
	return (0);
}
