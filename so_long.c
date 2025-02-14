/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:04:23 by iguney            #+#    #+#             */
/*   Updated: 2025/02/14 19:44:05 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void map_checks(t_data *data, int ac)
{
    file_control(ac, data);
    map_read(data);
    map_includes(data);
    map_valid(data);
    map_requirements(data);
	disable_exit(data);
    flood_fill(data, data->player->x, data->player->y);
    check_reachable(data);
}

int main(int ac, char *av[])
{
    t_data *data;

    data = malloc(sizeof(t_data));
    data->path = av[1];
    map_checks(data, ac);
    ft_printf("%s", "Game started!\n");
    mlx_creat(data);
    mlx_graphical_convert(data);
    mlx_photo_fill(data, 0, 0);
    mlx_loop(data->mlx->init);
}
