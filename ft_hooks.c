/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:54:42 by jperras           #+#    #+#             */
/*   Updated: 2022/04/06 18:49:46 by jeremyperras     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input_mouse(int button, int x, int y, t_data *data)
{
	if (button == 1 && data->player.a1[0] < data->player.len1 && ((data->map.mapsc[y / Height][x / Width] == 'R'
			|| data->map.mapsc[y / Height][x / Width] == 'G') || data->map.mapsc[y / Height][x / Width] == 'B'))
		ft_put_setting_color(x, y, data);
	if (button == 1 && data->player.a1[1] < data->player.len1 && ((data->map.mapsc[y / Height][x / Width] == 'U'
			|| data->map.mapsc[y / Height][x / Width] == 'D') || data->map.mapsc[y / Height][x / Width] == 'L'))
		ft_put_setting_arrow(x, y, data);
	return (0);
}

int	ft_input_key(int key, t_data *data)
{
	if (key == 49)
	{
		ft_algo(data);

	}
	if (key == 51 && data->player.a1[0] > 0)
	{
		data->player.a1[0] = 0;
		data->player.a1[1] = 0;
		ft_clean_window(data);
	}
	return (0);
}
