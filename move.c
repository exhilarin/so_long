/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:00:37 by iguney            #+#    #+#             */
/*   Updated: 2025/02/06 17:11:42 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_data *data, int y, int x)
{
    x = data->player->x;
    y = data->player->y; 
    if(data->map_reachable[y][x] != '1')
        data->map_reachable[y][x] = 'X';
    if (data->map_reachable[y][x] == '1' 
        || data->map_reachable[y][x] == 'X')
		return ;
    
    // flood_fill(y + 1);
    // flood_fill(x + 1);
    // flood_fill(y - 1);
    // flood_fill(x - 1);
}

void check_reachable(t_data *data)
{
    data->i = -1;
	data->j = -1;
    while (++data->i < data->vertical)
    {	
        data->j = -1;
        while (++data->j < data->horizontal)
        {
            if (data->map_reachable[data->i][data->j] != '1' 
				&& data->map_reachable[data->i][data->j] != 'X')
				return (free(data->map_reachable), error("All character must be reachable!"));
        }
    }
}
