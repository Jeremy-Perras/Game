/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:53:14 by jperras           #+#    #+#             */
/*   Updated: 2022/04/06 18:47:00 by jeremyperras     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../printf/includes/ft_printf.h"
# include <math.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include "get_next_line.h"
# include <fcntl.h>
# define Height 50
# define Width 50
# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_error
{
	int	check;
	int	rect;
	int num;
	int start;
	int	error;
}	t_error;

typedef struct s_windows
{
	void		*ref;
	t_vector	size;
}	t_windows;

typedef struct s_image
{
	void		*ref;
	t_vector	size;
	int			height;
	int			width;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_map
{
	char	**mapsc;
	char	**mapsp;
	int		line;
	int		col;
	int		items;
	int		itemsc;
	int		win;
	int 	lose;

}	t_map;

typedef struct s_player
{
	char ***array;
	int a1[4];
	int a2[4];
	int a3[4];
	int	len;
	int	len1;
	int	len2;
	int	len3;
	int	R;
	int	G;
	int	B;

} t_player;

typedef struct s_data
{
	void		*mlx;
	t_map		map;
	t_windows	window;
	t_image		*image;
	t_vector	position;
	t_error		error;
	t_player	player;

}	t_data;
typedef void	(*t_choose2)(t_data*, int*);
typedef void	(*t_choose3)(t_data*, int*, int);
/*
 *ft_createmap.c
 *
 */
void	ft_readmapc(t_data *data, char *path);
void	ft_readmapp(t_data *data, int fd);
void	ft_read_map(char *path, t_data *data);
/*
 *ft_image.c
 *
 */
void	ft_put_back_ground(t_data *data);
void	ft_put_image(t_data *data);
void	ft_put_sprite(t_data *data);
void	ft_put_background(t_data *data);
/*
 *ft_image2.c
 *
 */
void	my_mlx_pixel_put(t_data *data, int color, int p);
void	my_mlx_pixel_put_border(t_data *data, int color, int p);
void	ft_put_sprite3(t_data *data);
/*
 *ft_windows.c
 *
 */
t_windows	ft_windows(void *mlx, int widht, int height, char *title);
void	ft_clean_window(t_data *data);
void	ft_put_set(t_data *data);
int		ft_update (t_data *data);
/*
 *ft_hooks.c
 *
 */
int	ft_input_mouse(int button, int x, int y, t_data *data);
int	ft_input_key(int key, t_data *data);
/*
 *ft_hooks3.c
 *
 */
void	ft_put_to_window(t_data *data);
void	ft_put_setting_color(int x, int y, t_data *data);
void	ft_put_setting_arrow(int x, int y, t_data *data);
/*
 *ft_algo.c
 *
 */
void	ft_algo(t_data *data);
#endif
