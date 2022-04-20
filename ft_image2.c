/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:21:18 by jperras           #+#    #+#             */
/*   Updated: 2022/04/06 18:51:41 by jeremyperras     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_put_sprite3(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.mapsp[i])
	{
		while (data->map.mapsp[i][j])
		{
			if (data->map.mapsp[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->window.ref,
						data->image[4].ref, Width  * j  + (Width / 6) , i * Height + 2);
				data->position.x = j;
				data->position.y = i;
			}
			if (data->map.mapsp[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window.ref,
						data->image[8].ref, Width  * j  + (Width / 6) , i * Height + (Height / 6));
			j++;
		}
		j = 0;
		i++;
	}
}
