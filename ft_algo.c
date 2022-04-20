/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:27:16 by jperras           #+#    #+#             */
/*   Updated: 2022/04/17 19:18:47 by jeremyperras     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_algo(t_data *data)
{
	if (data->player.array[0][1][i] == 'U')
	{
		if (data->player.array[0][0][j] == data->map.mapsc[data->position.y - 1 ][data->position.x])
		{
			flag = 0;
			data->map.mapsp[data->position.y][data->position.x] = '0';
			data->position.x = data->position.x;
			data->position.y = data->position.y - 1;
			data->map.mapsp[data->position.y][data->position.x] = 'P';
			ft_clean_window(data);
			j++;
		}
	}
	if (data->player.array[0][1][i] == 'D')
	{
		if (data->player.array[0][0][j] == data->map.mapsc[data->position.y][data->position.x + 1])
		{
			flag = 0;
			data->map.mapsp[data->position.y][data->position.x] = '0';
			data->position.x = data->position.x + 1;
			data->position.y = data->position.y;
			data->map.mapsp[data->position.y][data->position.x] = 'P';
			ft_clean_window(data);
			j++;
		}
	}
	if (data->player.array[0][1][i] == 'L')
	{
		if (data->player.array[0][0][j] == data->map.mapsc[data->position.y][data->position.x - 1])
		{
			flag = 0;
			data->map.mapsp[data->position.y][data->position.x] = '0';
			data->position.x = data->position.x - 1;
			data->position.y = data->position.y;
			data->map.mapsp[data->position.y][data->position.x] = 'P';
			ft_clean_window(data);
			j++;
		}
	}
}
