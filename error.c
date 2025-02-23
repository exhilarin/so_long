/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:10:03 by iguney            #+#    #+#             */
/*   Updated: 2025/02/22 23:13:37 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *error, t_data *data)
{
	int	i;

	i = -1;
	perror(error);
	while (++i < data->vertical && data->map[i])
		free(data->map[i]);
	free(data->map);
	free(data);
	exit(0);
}

void	player_error(char *error, t_data *data)
{
	int	i;

	i = -1;
	perror(error);
	while (++i < data->vertical && data->map[i])
		free(data->map[i]);
	free(data->map);
	free(data->player);
	free(data);
	exit(0);
}

void	reachable_error(char *error, t_data *data)
{
	int	i;

	i = -1;
	perror(error);
	while (++i < data->vertical && data->map[i])
		free(data->map[i]);
	i = -1;
	while (++i < data->vertical && data->map_reachable[i])
		free(data->map_reachable[i]);
	free(data->map);
	free(data->map_reachable);
	free(data->player);
	free(data);
	exit(0);
}

void	exit_error(char *error, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->vertical && data->map[i])
		free(data->map[i]);
	free(data->map);
	i = -1;
	while (++i < data->vertical && data->map_reachable[i])
		free(data->map_reachable[i]);
	free(data->map_reachable);
	free(data->player);
	free(data->exit);
	free(data->mlx->init);
	free(data->mlx);
	perror(error);
	free(data);
	exit(0);
}

void	mlx_error(char *error, t_data *data)
{
	mlx_destroy_image(data->mlx->init, data->bush);
	mlx_destroy_image(data->mlx->init, data->grass);
	mlx_destroy_image(data->mlx->init, data->bojack);
	mlx_destroy_image(data->mlx->init, data->daisy);
	mlx_destroy_image(data->mlx->init, data->princess);
	mlx_destroy_window(data->mlx->init, data->mlx->window);
	mlx_destroy_display(data->mlx->init);
	free(data->mlx->init);
	free(data->mlx);
	exit_error(error, data);
}
