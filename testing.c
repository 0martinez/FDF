/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:54:12 by omartine          #+#    #+#             */
/*   Updated: 2022/02/11 15:44:14 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

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
int	ft_strlen(char	*str)
{
	int	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
static char	to_char(unsigned long long num, int flg)
{
	char	hexa;

	if (num > 9)
	{
		if (flg == 1)
			hexa = 'A' + (num - 10);
		else
			hexa = 'a' + (num - 10);
	}
	else
		hexa = '0' + num;
	return (hexa);
}

static int	count_chars(unsigned long long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static int	run_reverse(int count, char *str)
{
	count--;
	while (count >= 0)
	{
		write(1, &str[count], 1);
		count--;
	}
	return (ft_strlen(str));
}



int	ft_hexa(unsigned long int a, int flg)
{
	int		count;
	char	*str;
	int		i;
	unsigned long long num = a;
	i = 0;
	if (num == 0)
		return (1);
	count = count_chars(num);
	str = (char *) malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	str[count] = 0;
	while (num != 0)
	{
		str[i] = to_char(num % 16, flg);
		num = num / 16;
		i++;
	}
	count = run_reverse(count, str);
	free(str);
	return (count);
}

int main(void)
{
	int a = 0x00ff00;
	ft_hexa(a, 0);
	return (0);
}
