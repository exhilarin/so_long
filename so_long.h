#ifndef SO_LONG_H
#define SO_LONG_H

#include "./get_next_line/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include "./mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define	UP		65362
#define	RIGHT	65363
#define LEFT	65361
#define	DOWN	65364
#define	ESC 	65307
#define	W		119
#define	A		97
#define	S		115
#define	D		100


typedef struct s_data
{
	struct	s_data	*player;
	struct	s_data	*exit;
	struct	s_data	*mlx;
	
	char	**map_reachable;
    char    **map;
    char    *path;

	void	*init;
	void	*window;

    int     vertical;
    int     horizontal;

	void	*bojack;
	void	*princess;
	void	*bush;
	void	*daisy;
	void	*grass;

    int		check_p;
	int		check_c;
    int		check_e;

    int		i;
	int		j;

	int		x;
	int		y;

	int		c;
	int		p;
	int		e;

}   t_data;

void	map_checks(t_data *data, int ac);
void	file_control(int ac, t_data *data);
void	map_read(t_data *data);
void	map_includes(t_data *data);
void	map_valid(t_data *data);
void	map_requirements(t_data *data);
void	error(char *error);
void	disable_exit(t_data *data);
void	flood_fill(t_data *data, int i, int j);
void	check_reachable(t_data *data);
void	mlx_creat(t_data *data);
void	mlx_photo_fill(t_data *data, int x, int y);
void	mlx_graphical_convert(t_data *data);
void	map_copy(t_data *data);
void	mlx_checks(t_data *data);
void	free_map(t_data *data);
int		key_hook(int keycode, t_data *data);
int		handle_close(t_data *data);
int		quit_game(t_data *game);
int		s_strchr(char *str, char c);
int		s_strlen(char *str);

// void	player_move(t_data *data);

#endif
