/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:36:15 by jperras           #+#    #+#             */
/*   Updated: 2022/04/08 20:42:55 by jeremyperras     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static int	ft_close(void)
{
	exit(0);
}

t_windows	ft_windows(void *mlx, int widht, int height, char *title)
{
	t_windows	windows;

	windows.ref = mlx_new_window(mlx, widht, height, title);
	windows.size.x = widht;
	windows.size.y = height;
	mlx_hook(windows.ref, 17, 0, ft_close, 0);
	return (windows);
}

void	ft_clean_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->window.ref);
	ft_put_background(data);
	ft_put_sprite(data);
	ft_put_sprite3(data);
	ft_put_to_window(data);
}

static void	ft_put_sprite4(char c, int i, int j, t_data *data)
{
	if (c == 'R')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[1].ref, Width * j, (Height + 1 / 2)* i);
	else if (c == 'G')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[2].ref, Width * j, (Height + 1 / 2) * i);
	else if (c == 'B')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[3].ref, Width * j, i * (Height+ 1 / 2));
	else if (c == 'U')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[9].ref, Width * j, i * Height);
	else if (c == 'D')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[11].ref, Width * j, i * Height + Height / 4);
	else if (c == 'L')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[12].ref, Width * j, i * Height + Height / 4);
	else if (c == 'T')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[13].ref, Width * j, Height * i + 4);
	else if (c == 'H')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[14].ref, Width * j, Height * i + 4);
	else if (c == 'N')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[15].ref, Width * j, Height * i + 4);
	else if (c == 'E')
			mlx_string_put(data->mlx, data->window.ref, Width * j+ Width / 4,
			i * Height + (Height /2), 0xFFFFFF, "F1");
	else if (c == 'F')
			mlx_string_put(data->mlx, data->window.ref, Width * j+ Width / 4,
			i * Height + (Height /2), 0xFFFFFF, "F2");
	else if (c == 'V')
			mlx_string_put(data->mlx, data->window.ref, Width * j+ Width / 4,
			i * Height + (Height /2), 0xFFFFFF, "F3");
}

void	ft_put_set(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->player.a1[0])
	{
		ft_put_sprite4(data->player.array[0][0][i], data->map.line, i + 1, data);
		i++;
	}
	i = 0;
	while (i < data->player.a1[1])
	{
		ft_put_sprite4(data->player.array[0][1][i], data->map.line, i + 1, data);
		i++;
	}
}

int	ft_update (t_data *data)
{
	static int	frame;
	int			i;

	frame++;
	i = 0;
	if (frame == ANIMATION_FRAMES)
		i += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		i -= 1;
		frame = 0;
		ft_clean_window(data);
		ft_put_set(data);
	}

	mlx_put_image_to_window(data->mlx, data->window.ref,
		data->image[4].ref, Width  * data->position.x  + (Width / 6) ,
		data->position.y * Height + 2 + i);
	return (0);
}
