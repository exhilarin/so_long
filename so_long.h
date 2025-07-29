/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:38:44 by iguney            #+#    #+#             */
/*   Updated: 2025/02/22 18:46:33 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define TILE_SIZE		64
# define UP				65362
# define RIGHT			65363
# define LEFT			65361
# define DOWN			65364
# define ESC			65307
# define W				119
# define A				97
# define S				115
# define D				100

typedef struct s_data
{
	struct s_data	*player;
	struct s_data	*exit;
	struct s_data	*mlx;

	char			**map_reachable;
	char			**map;
	char			*path;

	char			*gnl;	

	void			*init;
	void			*window;

	int				vertical;
	int				horizontal;

	void			*bojack;
	void			*princess;
	void			*bush;
	void			*daisy;
	void			*grass;

	int				check_p;
	int				check_c;
	int				check_e;

	int				collected;
	int				moves;

	int				i;
	int				j;

	int				x;
	int				y;

	int				c;
	int				p;
	int				e;
}	t_data;

void	map_checks(t_data *data, int ac);
void	file_control(int ac, t_data *data);
void	map_read(t_data *data);
void	map_includes(t_data *data);
void	map_valid(t_data *data);
void	map_requirements(t_data *data);
void	disable_exit(t_data *data);
void	flood_fill(t_data *data, int i, int j);
void	check_reachable(t_data *data);
void	mlx_creat(t_data *data);
void	calculate_gnl(t_data *data);
void	mlx_photo_fill(t_data *data, int x, int y);
void	mlx_graphical_convert(t_data *data);
void	draw_pixel(t_data *data, int x, int y);
void	draw_map(t_data *data);
void	free_mlx(t_data *data);
void	map_copy(t_data *data);
void	mlx_checks(t_data *data);
void	move(t_data *data, int lr, int ud);
void	quit_game(t_data *data);
void	map_error(char *error, t_data *data);
void	player_error(char *error, t_data *data);
void	reachable_error(char *error, t_data *data);
void	exit_error(char *error, t_data *data);
void	free_main(t_data *data);
void	free_mlx(t_data *data);
void	error(char *error, t_data *data);
int		win_check(t_data *data, int x_new, int y_new);
int		key_hook(int keycode, t_data *data);
int		handle_close(t_data *data);
int		s_strchr(char *str, char c);
int		s_strlen(char *str);

#endif
