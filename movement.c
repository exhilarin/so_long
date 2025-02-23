/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:13:25 by iguney            #+#    #+#             */
/*   Updated: 2025/02/23 12:59:12 by iguney           ###   ########.fr       */
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
	ft_printf("Step:%d\n", data->moves);
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
	if (data->map[new_y][new_x] == 'E' && data->collected != data->check_c)
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

void	quit_game(t_data *data)
{
	free_main(data);
	free_mlx(data);
}

int	win_check(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'E' && (data->collected == data->check_c))
	{
		ft_printf("%s", "Congratulations! You got the princess!!\n");
		ft_printf("In the steps. %d\n", data->moves);
		quit_game(data);
		exit(0);
	}
	return (0);
}
