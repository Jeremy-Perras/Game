/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:23:45 by jperras           #+#    #+#             */
/*   Updated: 2022/04/06 18:51:15 by jeremyperras     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static t_image	ft_new_image(void *mlx, char *path);


void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y * Height < data->window.size.y)
	{
		x = 0;
		while (x * Width < data->window.size.x)
		{
			mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[0].ref, Width * x, Height* y);
			x++;
		}
		y++;
	}
}

static void	ft_put_sprite2(t_data *data, int i, int j)
{
	if (data->map.mapsc[i][j] == 'R')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[1].ref, Width * j, Height* i);
	else if (data->map.mapsc[i][j] == 'G')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[2].ref, Width * j, Height * i);
	else if (data->map.mapsc[i][j] == 'B')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[3].ref, Width * j, i * Height);
	else if (data->map.mapsc[i][j] == 'U')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[9].ref, Width * j, i * Height);
	else if (data->map.mapsc[i][j] == 'D')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[11].ref, Width * j, i * Height + Height / 4);
	else if (data->map.mapsc[i][j] == 'L')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[12].ref, Width * j, i * Height + Height / 4);
	else if (data->map.mapsc[i][j] == 'T')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[13].ref, Width * j, Height * i + 4);
	else if (data->map.mapsc[i][j] == 'H')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[14].ref, Width * j, Height * i + 4);
	else if (data->map.mapsc[i][j] == 'N')
		mlx_put_image_to_window(data->mlx, data->window.ref,
			data->image[15].ref, Width * j, Height * i + 4);
	else if (data->map.mapsc[i][j] == 'E')
			mlx_string_put(data->mlx, data->window.ref, Width * j+ Width / 4,
			i * Height + (Height /2), 0xFFFFFF, "F1");
	else if (data->map.mapsc[i][j] == 'F')
			mlx_string_put(data->mlx, data->window.ref, Width * j+ Width / 4,
			i * Height + (Height /2), 0xFFFFFF, "F2");
	else if (data->map.mapsc[i][j] == 'V')
			mlx_string_put(data->mlx, data->window.ref, Width * j+ Width / 4,
			i * Height + (Height /2), 0xFFFFFF, "F3");
}

void	ft_put_sprite(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.mapsc[i])
	{
		while (data->map.mapsc[i][j])
		{
			if (data->map.mapsc[i][j] == 'R' || data->map.mapsc[i][j] == 'G' || data->map.mapsc[i][j] == 'B')
				ft_put_sprite2(data, i, j);
			else if (data->map.mapsc[i][j] == 'U' || data->map.mapsc[i][j] == 'D' || data->map.mapsc[i][j] == 'L')
				ft_put_sprite2(data, i, j);
			else if (data->map.mapsc[i][j] == 'T' || data->map.mapsc[i][j] == 'H' || data->map.mapsc[i][j] == 'N')
				ft_put_sprite2(data, i, j);
			else if (data->map.mapsc[i][j] == 'E' || data->map.mapsc[i][j] == 'F' || data->map.mapsc[i][j] == 'V')
				ft_put_sprite2(data, i, j);

			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_put_image(t_data *data)
{
	data->image = malloc(sizeof(t_image) * 16);

	data->image[0] = ft_new_image(data->mlx, "image/Whitesquare.xpm");
	data->image[1] = ft_new_image(data->mlx, "image/Redsquare.xpm");
	data->image[2] = ft_new_image(data->mlx, "image/Greensquare.xpm");
	data->image[3] = ft_new_image(data->mlx, "image/Bluesquare.xpm");
	data->image[4] = ft_new_image(data->mlx, "image/Playerup.xpm");
	data->image[5] = ft_new_image(data->mlx, "image/Playerleft.xpm");
	data->image[6] = ft_new_image(data->mlx, "image/Playerright.xpm");
	data->image[7] = ft_new_image(data->mlx, "image/Playerdown.xpm");
	data->image[8] = ft_new_image(data->mlx, "image/Star.xpm");
	data->image[9] = ft_new_image(data->mlx, "image/Arrowup.xpm");
	data->image[10] = ft_new_image(data->mlx, "image/Arrowdown.xpm");
	data->image[11] = ft_new_image(data->mlx, "image/Arrowright.xpm");
	data->image[12] = ft_new_image(data->mlx, "image/Arrowleft.xpm");
	data->image[13] = ft_new_image(data->mlx, "image/Paintr.xpm");
	data->image[14] = ft_new_image(data->mlx, "image/Paintg.xpm");
	data->image[15] = ft_new_image(data->mlx, "image/Paintb.xpm");
}

static t_image	ft_new_image(void *mlx, char *path)
{
	t_image	image;

	image.ref = mlx_xpm_file_to_image(mlx, path, &image.size.x, &image.size.y);
	return (image);
}
