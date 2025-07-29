/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:08:00 by iguney            #+#    #+#             */
/*   Updated: 2025/02/22 23:01:22 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	s_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	s_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (c == '\0' || c == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	free_main(t_data *data)
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
}

void	free_mlx(t_data *data)
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
	free(data);
}

void	error(char *error, t_data *data)
{
	perror(error);
	free(data);
	exit(0);
}
