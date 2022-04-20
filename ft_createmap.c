/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:32:35 by jperras           #+#    #+#             */
/*   Updated: 2022/04/06 18:57:42 by jeremyperras     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *path, t_data *data)
{
	ft_readmapc(data, path);
}

void	ft_readmapc(t_data *data, char *path)
{
	int			fd;
	int			i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 1)
		data->error.error = 0;
	if (data->error.error)
	{
		tmp = get_next_line(fd);
		tmp2 = get_next_line(fd);
		i = 0;
		while (tmp2[0] != '\n')
		{
			tmp = ft_strjoin(tmp, tmp2);
			tmp2 = get_next_line(fd);
			i++;
		}
		ft_readmapp(data, fd);
		close(fd);
		data->map.mapsc = ft_split(tmp, '\n');
	}
}

void	ft_readmapp(t_data *data, int fd)
{
	int			i;
	char		*tmp;
	char		*tmp2;
	char		**tmp3;

	i = 0;
	tmp = get_next_line(fd);
	tmp2 = get_next_line(fd);
	i = 0;
	while (tmp2[0] != '\n')
	{
		tmp = ft_strjoin(tmp, tmp2);
		tmp2 = get_next_line(fd);
		i++;
	}
	data->map.line = i;
	data->map.mapsp = ft_split(tmp, '\n');
	data->map.col = ft_strlen(*(data->map.mapsp));
	tmp2 = get_next_line(fd);
	tmp3 = ft_split(tmp2, ' ');
	data->player.array = malloc(sizeof(char) * (tmp3[0][0] - '0'));
	data->player.len1 = ft_atoi(tmp3[1]);
	data->player.len2 = ft_atoi(tmp3[2]);
	data->player.len3 = ft_atoi(tmp3[3]);
	data->player.len = tmp3[0][0] - '0';
	i = 0;
	while (i < 4)
	{
		data->player.array[i] = malloc(sizeof(char) * 4);
		data->player.array[0][i] = malloc(sizeof(char) * (data->player.len1));
		i++;
	}
	data->player.R = tmp3[4][0];
	data->player.G = tmp3[5][0];
	data->player.B = tmp3[6][0];
}
