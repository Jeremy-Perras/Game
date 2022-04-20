/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:25:35 by jperras           #+#    #+#             */
/*   Updated: 2022/04/04 09:43:37 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_initialisation(t_data *data)
{
	data->map.itemsc = 0;
	data->map.items = 0;
	data->map.win = 0;
	data->map.lose = 0;
	data->error.check = 1;
	data->error.rect = 1;
	data->error.num = 1;
	data->error.start = 0;
	data->error.error = 1;
	data->player.a1[0] = 0;
	data->player.a1[1] = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	(void) argc;
	(void) argv;

	data.mlx = mlx_init();
	ft_initialisation(&data);
	
	if (argc < 2 || ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printf("Error");
		return (0);
	}
	ft_read_map(argv[1], &data);
	data.window = ft_windows(data.mlx, data.map.col * Width, (data.map.line + 1) * Height, "Test");
	ft_put_image(&data);
	ft_clean_window(&data);
	mlx_mouse_hook(data.window.ref, *ft_input_mouse, &data);	
	mlx_key_hook(data.window.ref, *ft_input_key, &data);
	mlx_loop_hook(data.mlx, *ft_update, &data);
	mlx_loop(data.mlx);
}
