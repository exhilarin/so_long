/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:13:25 by iguney            #+#    #+#             */
/*   Updated: 2025/02/17 20:38:45 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		move(data, 0, -1);
	if (keycode == A || keycode == LEFT)
		move(data, -1, 0);
	if (keycode == S || keycode == DOWN)
		move(data, 0, 1);
	if (keycode == D || keycode == RIGHT)
		move(data, 1, 0);
	if (keycode == ESC)
		handle_close(data);
	draw_map(data);
	return (0);
}

void	move(t_data *data, int lr, int ud)
{
	int	new_x;
	int	new_y;

	new_x = data->player->x + lr;
	new_y = data->player->y + ud;
	if (data->map[new_y][new_x] == '1')
		return ;
	if (data->map[new_y][new_x] == 'C')
	{
		data->collected++;
		data->map[new_y][new_x] = '0';
	}
	data->player->x = new_x;
	data->player->y = new_y;
	data->moves++;
	win_check(data, new_x, new_y);
}

int	win_check(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'E' && (data->collected == data->check_c))
	{
		write(1, "Congratulations! You got the princess!!\n", 38);
		quit_game(data);
		exit(0);
	}
	return (0);
}

int	quit_game(t_data *data)
{
	if (data->map)
		free_map(data);
	if (data->mlx->window)
	{
		if (data->bush)
			mlx_destroy_image(data->mlx->init, data->bush);
		if (data->grass)
			mlx_destroy_image(data->mlx->init, data->grass);
		if (data->bojack)
			mlx_destroy_image(data->mlx->init, data->bojack);
		if (data->daisy)
			mlx_destroy_image(data->mlx->init, data->daisy);
		if (data->princess)
			mlx_destroy_image(data->mlx->init, data->princess);
		mlx_destroy_window(data->mlx->init, data->mlx->window);
	}
	return (0);
}

void	free_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (i < data->vertical && data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
