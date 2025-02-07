/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:00:37 by iguney            #+#    #+#             */
/*   Updated: 2025/02/07 19:06:26 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_data *data, int x, int y)
{
	if (y < 0 || y >= data->vertical || x < 0 || x >= data->horizontal)
		return ;
	if (data->map_reachable[y][x] == '1' || data->map_reachable[y][x] == 'X')
		return ;

	data->map_reachable[y][x] = 'X';
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
}

void check_reachable(t_data *data)
{
	int i, j;

	j = 0;
	while (j < data->vertical)
	{
		i = 0;
		while (i < data->horizontal)
		{
			if (data->map_reachable[j][i] != '1' && data->map_reachable[j][i] != 'X')
				return(free(data->map_reachable), error("The map has an unreachable point!"));
			i++;
		}
		j++;
	}
}
