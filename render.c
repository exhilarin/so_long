/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:06:36 by iguney            #+#    #+#             */
/*   Updated: 2025/02/28 23:44:41 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_creat(t_data *data)
{
	data->i = -1;
	data->j = -1;
	data->collected = 0;
	data->mlx = malloc(sizeof(t_data));
	if (!data->mlx)
		return (exit_error("Memory allocation failed for mlx structure!",
				data));
	data->mlx->init = mlx_init();
	if (!data->mlx->init)
		return (exit_error("MLX initialization failed!", data),
			free(data->mlx));
	data->mlx->window = mlx_new_window(data->mlx->init,
			data->horizontal * 64, data->vertical * 64, "so_long");
	if (!data->mlx->window)
		return (exit_error("Failed to open window!", data), free(data->mlx),
			free(data->mlx->init));
}

void	mlx_graphical_convert(t_data *data)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	data->grass = mlx_xpm_file_to_image(data->mlx->init,
			"./textures/floor/grass.xpm", &width, &height);
	data->daisy = mlx_xpm_file_to_image(data->mlx->init,
			"./textures/collectable/daisy.xpm", &width, &height);
	data->bush = mlx_xpm_file_to_image(data->mlx->init,
			"./textures/wall/bush_one.xpm", &width, &height);
	data->princess = mlx_xpm_file_to_image(data->mlx->init,
			"./textures/exit/princess_one.xpm", &width, &height);
	data->bojack = mlx_xpm_file_to_image(data->mlx->init,
			"./textures/player/bojack_one.xpm", &width, &height);
}

void	mlx_photo_fill(t_data *data, int x, int y)
{
	while (++data->i < data->vertical)
	{
		x = 0;
		data->j = -1;
		while (++data->j < data->horizontal)
		{
			if (data->map[data->i][data->j] != '1')
				mlx_put_image_to_window(data->mlx->init,
					data->mlx->window, data->grass, x, y);
			if (data->map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx->init,
					data->mlx->window, data->bush, x, y);
			else if (data->map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx->init,
					data->mlx->window, data->princess, x, y);
			else if (data->map[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->mlx->init,
					data->mlx->window, data->daisy, x, y);
			else if (data->map[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->mlx->init,
					data->mlx->window, data->bojack, x, y);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->vertical)
	{
		j = -1;
		while (++j < data->horizontal)
		{
			draw_pixel(data, j, i);
		}
	}
}

void	draw_pixel(t_data *data, int x, int y)
{
	char	current;

	mlx_put_image_to_window(data->mlx->init,
		data->mlx->window, data->grass, x * TILE_SIZE, y * TILE_SIZE);
	current = data->map[y][x];
	if (current == '1')
		mlx_put_image_to_window(data->mlx->init,
			data->mlx->window, data->bush, x * TILE_SIZE, y * TILE_SIZE);
	else if (current == 'C')
		mlx_put_image_to_window(data->mlx->init,
			data->mlx->window, data->daisy, x * TILE_SIZE, y * TILE_SIZE);
	else if (current == 'E')
		mlx_put_image_to_window(data->mlx->init,
			data->mlx->window, data->princess, x * TILE_SIZE, y * TILE_SIZE);
	if (x == data->player->x && y == data->player->y)
		mlx_put_image_to_window(data->mlx->init,
			data->mlx->window, data->bojack, x * TILE_SIZE, y * TILE_SIZE);
}
