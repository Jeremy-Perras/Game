/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:40:39 by jperras           #+#    #+#             */
/*   Updated: 2022/04/04 09:47:07 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_put_to_window(t_data *data)
{
	mlx_string_put(data->mlx, data->window.ref, Width / 2, data->map.line  * Height + Height / 2, 0xFFFFFF, "F1");
	if (data->player.len >= 2)
		mlx_string_put(data->mlx, data->window.ref, Width * (data->player.len1) + Width / 2, data->map.line * Height + (Height / 2), 0xFFFFFF, "F2");
	if (data->player.len >= 3)
		mlx_string_put(data->mlx, data->window.ref, Width * (data->player.len2 + 1) + Width / 2, data->map.line * Height + (Height /2), 0xFFFFFF, "F3");
}

void	ft_put_setting_color(int x, int y, t_data *data)
{
	if (data->map.mapsc[y / Height][x / Width] == 'R')
	{
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[1].ref, Width * (data->player.a1[0] + 1), data->map.line * (Height + 1/2));
		data->player.array[0][0][data->player.a1[0]] = 'R';
		data->player.a1[0] = data->player.a1[0] + 1;
	}
	else if (data->map.mapsc[y / Height][x / Width] == 'G')
	{	
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[2].ref, Width * (data->player.a1[0] + 1), data->map.line * (Height + 1/2));
		data->player.array[0][0][data->player.a1[0]] = 'G';
		data->player.a1[0] = data->player.a1[0] + 1;
	}
	else if (data->map.mapsc[y / Height][x / Width] == 'B')
	{
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[3].ref, Width * (data->player.a1[0] + 1), data->map.line * (Height + 1/2));
		data->player.array[0][0][data->player.a1[0]] = 'B';
		data->player.a1[0] = data->player.a1[0] + 1;
	}
}

void	ft_put_setting_arrow(int x, int y, t_data *data)
{
	if (data->map.mapsc[y / Height][x / Width] == 'U')
	{
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[9].ref, Width * (data->player.a1[1] + 1) + Width /5, data->map.line * (Height + 3 / 2));
		data->player.array[0][1][data->player.a1[1]] = 'U';
		data->player.a1[1] = data->player.a1[1] + 1;
	}
	else if (data->map.mapsc[y / Height][x / Width] == 'D')
	{	
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[11].ref, Width * (data->player.a1[1] + 1) + Width / 7, data->map.line * (Height + 5 / 2));
		data->player.array[0][1][data->player.a1[1]] = 'D';
		data->player.a1[1] = data->player.a1[1] + 1;
	}
	else if (data->map.mapsc[y / Height][x / Width] == 'L')
	{
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[12].ref, Width * (data->player.a1[1] + 1) + Width /7, data->map.line * (Height) + Height / 6);
		data->player.array[0][1][data->player.a1[1]] = 'L';
		data->player.a1[1] = data->player.a1[1] + 1;
	}
}
