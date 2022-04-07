/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:52:29 by omartine          #+#    #+#             */
/*   Updated: 2022/02/02 13:56:14 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *container, char *str)
{
	char	*new_container;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = (ft_strlen(container) + ft_strlen(str));
	new_container = (char *) malloc(sizeof(char) * i + 1);
	if (!new_container)
		return (0);
	new_container[i] = 0;
	i = 0;
	while (container[i] != 0)
	{
		new_container[i] = container[i];
		i++;
	}
	while (str[j] != 0)
	{
		new_container[i] = str[j];
		i++;
		j++;
	}
	free(container);
	return (new_container);
}

char	*line_no_jump(char *str)
{
	int		i;
	char	*to_return;

	if (str[0] == 0)
		return (0);
	i = 0;
	i = ft_strlen(str);
	to_return = malloc(sizeof(char) * i + 1);
	if (!to_return)
		return (0);
	to_return[i] = 0;
	i = 0;
	while (str[i] != 0)
	{
		to_return[i] = str[i];
		i++;
	}
	return (to_return);
}

int	check_container(char *container)
{
	int	i;

	i = 0;
	if (!container)
		return (0);
	while (container[i] != 0)
	{
		if (container[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
