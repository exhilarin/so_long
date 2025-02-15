/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:06:36 by iguney            #+#    #+#             */
/*   Updated: 2025/02/15 13:55:08 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mlx_creat(t_data *data)
{
    data->mlx = malloc(sizeof(t_data));
    if (!data->mlx)
        return (free(data->mlx), error("Memory allocation failed for mlx structure!"));
    data->mlx->init = mlx_init();
    if (!data->mlx->init)
        return (free(data->mlx->init), error("MLX initialization failed!"));
    data->mlx->window = mlx_new_window(data->mlx->init, data->horizontal * 64, data->vertical * 64, "so_long");
    if (!data->mlx->window)
        return (free(data->mlx->init), free(data->mlx), error("Failed to open window!"));
}

void mlx_graphical_convert(t_data *data)
{
    int width = 64;
	int height = 64;
	data->grass = mlx_xpm_file_to_image(data->mlx->init, "./textures/floor/grass.xpm", &width, &height);
	if(!data->grass)
		return(free(data->mlx->bojack), error("Image does not render!"));
	data->daisy = mlx_xpm_file_to_image(data->mlx->init, "./textures/collectable/daisy.xpm", &width, &height);
	if(!data->daisy)
		return(free(data->mlx->daisy), error("Image does not render!"));
	data->bush = mlx_xpm_file_to_image(data->mlx->init, "./textures/wall/bush_one.xpm", &width, &height);
	if(!data->bush)
		return(free(data->mlx->bush), error("Image does not render!"));
	data->princess = mlx_xpm_file_to_image(data->mlx->init, "./textures/exit/princess_one.xpm", &width, &height);
	if(!data->princess)
		return(free(data->mlx->princess), error("Image does not render!"));
	data->bojack = mlx_xpm_file_to_image(data->mlx->init, "./textures/player/bojack_one.xpm", &width, &height);
	if(!data->bojack)
		return(free(data->mlx->bojack), error("Image does not render!"));
	// mlx_loop_hook(data->mlx->init, mlx_bojack_animation, data);
}

void	mlx_photo_fill(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < data->vertical)
	{
		x = 0;
		j = -1;
		while (++j < data->horizontal)
		{
			if (data->map[i][j] != '1')
				mlx_put_image_to_window(data->mlx->init, data->mlx->window, data->grass, x, y);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx->init, data->mlx->window, data->bush, x, y);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx->init, data->mlx->window, data->princess, x, y);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx->init, data->mlx->window, data->daisy, x, y);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx->init, data->mlx->window, data->bojack, x, y);
			x += 64;
		}
		y += 64;
	}
}

// int mlx_bojack_animation(t_data *data)
// {
//     int width = 64;
//     int height = 64;
//     int current_frame = 0;
	
//     char *frames[F_NUM] = 
// 	{
//         "./textures/player/bojack_one.xpm", "./textures/player/bojack_two.xpm",
//         "./textures/player/bojack_three.xpm", "./textures/player/bojack_four.xpm",
//         "./textures/player/bojack_five.xpm", "./textures/player/bojack_six.xpm",
//         "./textures/player/bojack_seven.xpm", "./textures/player/bojack_eight.xpm"
//     };
//     while (1) 
//     {
//         data->bojack = mlx_xpm_file_to_image(data->mlx->init, frames[current_frame], &width, &height);
// 		if(!data->bojack)
// 			return(free(data->mlx->bojack), error("Image does not render!"), 0);
//         mlx_put_image_to_window(data->mlx->init, data->mlx->window, data->bojack, data->player->x * 64, data->player->y * 64);
//         current_frame++;
//         if (current_frame >= F_NUM)
//             current_frame = 0;
//         usleep(100000);
//     }
// 	return 0;
// }