/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:04:23 by iguney            #+#    #+#             */
/*   Updated: 2025/02/06 18:44:54 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int ac, char *av[])
{
    t_data *data;

    data = malloc(sizeof(t_data));
    data->path = av[1];
    map_control(ac, data);
    map_read(data);
    map_includes(data);
    map_valid(data);
    map_requirements(data);
    flood_fill(data, data->player->x, data->player->y);
    check_reachable(data);
}

