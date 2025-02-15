/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:13:25 by iguney            #+#    #+#             */
/*   Updated: 2025/02/15 20:12:44 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int quit_game(t_data *data)
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
int handle_close(t_data *data)
{
    quit_game(data);
    exit(0);
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


int key_hook(int keycode, t_data *data)
{
    // if (keycode == W || keycode == UP)
		
	// if (keycode == A || keycode == LEFT)

	// if (keycode == S || keycode == DOWN)

	// if (keycode == D || keycode == RIGHT)

	if (keycode == ESC)
		handle_close(data);
	return 0;
	
}

