/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:18:12 by jperras           #+#    #+#             */
/*   Updated: 2022/03/21 12:08:22 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlengnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchrgnl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoingnl(char *str, char *buff)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlengnl(str) + ft_strlengnl(buff) + 1);
	if (!res)
		return (NULL);
	if (str)
	{
		while (str[i])
		{
			res[i] = str[i];
			i++;
		}
	}
	while (buff[j])
		res[i++] = buff[j++];
	res[i] = '\0';
	free(str);
	return (res);
}
