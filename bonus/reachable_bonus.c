/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachable_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:00:37 by iguney            #+#    #+#             */
/*   Updated: 2025/02/15 13:55:51 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_copy(t_data *data)
{
	int	fd;
	int i;
	
	data->map_reachable = malloc(sizeof(char *) * data->vertical);
    if (!data->map_reachable)
		return(free(data->map_reachable), error("Allocation Failed!"));
	i = 0;
	fd = open(data->path, O_RDONLY);
	if (fd == -1)
		error("File does not open!");
	data->map_reachable = malloc(sizeof(char *) * data->vertical);
	if (!data->map)
		return (close(fd), free(data->map_reachable), error("Allocation Failed!"));
	while (i < data->vertical)
	{
		data->map_reachable[i] = get_next_line(fd);
		if (!data->map_reachable)
			return (close(fd), free(data->map_reachable), error("Get Line Failed!"));
		i++;
	}
}

void disable_exit(t_data *data)
{
	data->exit = malloc(sizeof(t_data));
	if (!data->exit)
		return(free(data->exit), error("Allocation Failed!"));
	data->i = 0;
	while (data->i < data->vertical)
    {	
        data->j = -1;
        while (++data->j < data->horizontal)
        {
            if (data->map[data->i][data->j] == 'E')
			{
				data->check_e++;
				data->exit->x = data->j;
				data->exit->y = data->i;
			}
			data->j++;
        }
		data->i++;
    }
	data->map_reachable[data->exit->y][data->exit->x] = '1'; 
}

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
	int i;
	int j;

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
