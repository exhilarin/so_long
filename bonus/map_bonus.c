/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:41:10 by iguney            #+#    #+#             */
/*   Updated: 2025/02/15 13:56:13 by iguney           ###   ########.fr       */
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
			error("Map file's name should end with the \".ber\"!");
	}
	else
		error("Wrong Input!");
}

void	map_read(t_data *data)
{
	int	fd;
	int i;
	i = 0;
	data->vertical = 0;
	data->horizontal = 0;
	fd = open(data->path, O_RDONLY);
	if (fd == -1)
		error("File does not open!");
	while (get_next_line(fd) != NULL)
		data->vertical++;
	close(fd);
	fd = open(data->path, O_RDONLY);
	if (fd == -1)
		error("File does not open!");
	data->map = malloc(sizeof(char *) * data->vertical);
	if (!data->map)
		return (close(fd), free(data->map), error("Allocation Failed!"));
	while (i < data->vertical)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map)
			return (close(fd), free(data->map), error("Get Line Failed!"));
		i++;
	}
	data->horizontal = s_strlen(data->map[0]);
}

void	map_includes(t_data *data)
{
	int 	i;
    int 	j;
    char 	*keys;
    i = 0;
    j = 0;
    keys = "10PCE";
    while (i < data->vertical)
    {	
        j = 0;
        while (j < data->horizontal)
        {
			if (!s_strchr(keys, data->map[i][j]))
				return(free(data->map), error("Invalid map input!"));
            j++;
        }
        i++;
    }
}

void	map_valid(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < data->horizontal)
	{
		if (data->map[0][j] != '1' || data->map[data->vertical - 1][j] != '1')
			return(free(data->map), error("The map conditions must be closed!"));
		j++;
	}
	while (i < data->vertical)
	{
		if (data->map[i][0] != '1' || data->map[i][data->horizontal - 1] != '1')
			return(free(data->map), error("The map conditions must be closed!"));
		else if (data->horizontal != s_strlen(data->map[i]))
			return(free(data->map), error("All map lines must be same!"));
		i++;
	}
	data->player = malloc(sizeof(t_data));
	if (!data->player)
		return(free(data->player), error("Allocation Failed!"));
}

void	map_requirements(t_data *data)
{
	data->check_p = 0;
	data->check_c = 0;
	data->check_e = 0;
	data->i = -1;
	while (++data->i < data->vertical)
    {	
        data->j = -1;
        while (++data->j < data->horizontal)
        {
            if (data->map[data->i][data->j] == 'P')
			{
            	data->check_p++;
				data->player->x = data->j;
				data->player->y = data->i;
			}
			if (data->map[data->i][data->j] == 'C')
                data->check_c++;
            if (data->map[data->i][data->j] == 'E')
				data->check_e++;
        }
    }
    if(data->check_p != 1 || data->check_c == 0 || data->check_e != 1)
        return (free(data->player), error("Invalid character input!"));
}
