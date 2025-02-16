/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:00:37 by iguney            #+#    #+#             */
/*   Updated: 2025/02/16 13:34:02 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_control(int ac, t_data *data)
{
	int		bend;
	int		end;
	char	*ber = ".ber";

	end = 0;
	bend = 3;
	if (ac == 2)
	{
		while (data->path[end] != '\0')
			end++;
		end--;
		while (data->path[end] == ber[bend])
		{
			end--;
			bend--;
		}
		if  (bend != -1)
			error("Map file's name must end with the \".ber\"!");
	}
	else
		error("Wrong Input!");
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
