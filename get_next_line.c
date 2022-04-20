/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:17:56 by jperras           #+#    #+#             */
/*   Updated: 2022/03/22 11:15:36 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_read(int fd, char *buff, char *str, int res);

char	*get_next_line(int fd)
{
	static int	res;
	static char	buff[BUFFER_SIZE / BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (res == 0)
	{
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	if (res > 0 && buff[0] != '\0')
		str = ft_read(fd, buff, str, res);
	else
		return (NULL);
	return (str);
}

static char	*ft_read(int fd, char *buff, char *str, int res)
{
	while (res > 0 && ft_strchrgnl(str, '\n'))
	{
		str = ft_strjoingnl(str, buff);
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	return (str);
}
