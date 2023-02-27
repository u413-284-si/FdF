/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:01:17 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/27 12:17:17 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/initiate.h"
#include "../inc/error.h"
#include "../inc/parse.h"
#include "../inc/colour.h"
#include "../inc/manip.h"

/* This function starts up the program, reads and transforms data providing
the required input for the following graphical display functions. */

void	system_boot(t_map *map, char *file)
{
	int		fd;

	initiate(map);
	fd = open(file, O_RDONLY);
	if (fd < 3)
		terminate(ERR_OPEN);
	read_file(map, fd);
	close(fd);
	map_dim(map);
	extract_lines(map);
	colour(map);
	scale(map);
	copy(map);
	ft_printf("\nMap reading terminated.\n");
}

/* This function initiates all the variables declared in t_map with
default values. */

void	initiate(t_map *map)
{
	map->point_count = 0;
	map->limits.x = 0;
	map->limits.y = 0;
	map->limits.z = 0;
	map->origin.x = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->origin.y = WINY / 2;
	map->origin.z = 0;
	map->angle[X] = atan(sqrt(2)) * 180 / M_PI;
	map->angle[Y] = 0;
	map->angle[Z] = 45;
	map->space = 10;
	map->z_min = 0;
	map->scale = 1;
	map->perf = 0;
	map->render_count = 0;
	map->z_scale = 1;
	map->colours.top_colour = TOP_COLOUR;
	map->colours.zero_lv_colour = ZERO_LV_COLOUR;
	map->colours.bottom_colour = BOTTOM_COLOUR;
	map->colours.background_colour = BACKGROUND_COLOUR;
	map->colours.menu_colour = MENU_COLOUR;
}

/* This function identifies the size of the map
		x-value = line length
		y-value = line count
Line length should be consistent, otherwise an error occurs and 
the program terminates. */

void	map_dim(t_map *map)
{
	static int	i = -1;
	static int	x_dim = 0;

	while (map->buf[++i])
	{
		if (map->buf[i] == '\n' && map->buf[i + 1] == '\0')
			break ;
		else if (map->buf[i] >= 33 && map->buf[i] <= 126
			&& (map->buf[i + 1] == ' ' || map->buf[i + 1] == '\n'
				|| map->buf[i + 1] == '\0'))
			x_dim++;
		else if (map->buf[i] == '\n')
		{
			map->limits.y++;
			if (map->limits.x != 0 && map->limits.x != x_dim)
				terminate(ERR_MAP_UNIFORMITY);
			else
				map->limits.x = x_dim;
			x_dim = 0;
		}
	}
	if (map->limits.x != 0 && map->limits.x != x_dim)
		terminate(ERR_MAP_UNIFORMITY);
	map->limits.y++;
	map->point_count = map->limits.x * map->limits.y;
}

/* This functions scales the values of the points in dependance of the
proportion towards the window size. */

void	scale(t_map *map)
{
	float_t	scale_x;
	float_t	scale_y;
	t_point	*cur;
	int		i;

	map->x_min = 0;
	map->x_max = 0;
	map->y_min = 0;
	map->y_max = 0;
	i = -1;
	while (++i < map->point_count)
	{
		cur = map->point + i;
		if (cur->x < map->x_min)
			map->x_min = cur->x;
		if (cur->x > map->x_max)
			map->x_max = cur->x;
		if (cur->y < map->y_min)
			map->y_min = cur->y;
		if (cur->y > map->y_max)
			map->y_max = cur->y;
	}
	scale_x = (((WINX - MENU_WIDTH) / 2) - FIT_MARGIN) / fmaxf(abs(map->x_max), \
		abs(map->x_min));
	scale_y = (WINY / 2 - FIT_MARGIN) / fmaxf(abs(map->y_max), abs(map->y_min));
	map->point = zoom(map->point, map, fminf(scale_x, scale_y));
}

/* This function creates a working copy of the original points
given in the input. */

void	copy(t_map *map)
{
	map->prjct = malloc(map->point_count * sizeof(t_point));
	if (!map->prjct)
		terminate(ERR_MEM);
	ft_memcpy(map->prjct, map->point, \
		(size_t)(map->point_count * sizeof(t_point)));
}
