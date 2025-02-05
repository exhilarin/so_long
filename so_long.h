#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_data
{
	struct	s_data	*player;
	char	**map_copy;
    char    **map;
    char    *path;
    int     vertical;
    int     horizontal;
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

void	map_control(int ac, t_data *data);
void	map_read(t_data *data);
void	map_includes(t_data *data);
void	map_valid(t_data *data);
void	map_requirements(t_data *data);
void	a(t_data *data);
int		s_strchr(char *str, char c);
int		s_strlen(char *str);
void	error(char *error);
void 	flood_fill(t_data *data);
void 	marker(t_data *data);



#endif
