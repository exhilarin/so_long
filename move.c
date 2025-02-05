/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:07:51 by iguney            #+#    #+#             */
/*   Updated: 2025/02/05 05:36:06 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_data *data)
{
    if(data->map[data->player->y][data->player->x] != '1' && marker())
        data->map[data->player->y][data->player->x] = 'X';
    
    flood_fill(++data->player->y);
    flood_fill(++data->player->x);
    flood_fill(--data->player->y);
    flood_fill(--data->player->x);
}

void marker(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (++data->i < data->vertical)
    {	
        data->j = -1;
        while (++data->j < data->horizontal)
        {
            if (data->map[i][j] != '1')
                data->map[i][j] = 'X';
        }
    }
}

