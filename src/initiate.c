/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:01:17 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/03 09:51:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/initiate.h"
#include "../inc/initiate2.h"
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
	map->initial = 1;
	map->cur_scale = map->scale;
	fd = open(file, O_RDONLY);
	if (fd < 3)
		terminate(ERR_OPEN);
	read_file(map, fd);
	close(fd);
	map_dim(map);
	extract_lines(map);
	colour(map);
	copy(map);
	ft_printf("\nMap reading terminated.\n");
}

/* This function initiates all the variables declared in t_map with
default values. */

void	initiate(t_map *map)
{
	map->point_count = 0;
	map->limits = (t_point){0, 0, 0, 0x0, 0};
	map->origin.x = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->origin.y = WINY / 2;
	map->origin.z = 0;
	map->base_i = (t_point){1, 0, 0, 0x0, 0};
	map->base_j = (t_point){0, 1, 0, 0x0, 0};
	map->base_k = (t_point){0, 0, 1, 0x0, 0};
	map->angle[X] = atan(sqrt(2)) * 180 / M_PI;
	map->angle[Y] = 0;
	map->angle[Z] = 45;
	map->cur_angle[X] = map->angle[X];
	map->cur_angle[Y] = map->angle[Y];
	map->cur_angle[Z] = map->angle[Z];
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

	set_min_max(map);
	scale_x = (((WINX - MENU_WIDTH) / 2) - FIT_MARGIN) / fmaxf(abs(map->x_max), \
		abs(map->x_min));
	scale_y = (WINY / 2 - FIT_MARGIN) / fmaxf(abs(map->y_max), abs(map->y_min));
	map->scale = fminf(scale_x, scale_y);
	map->point = zoom(map->point, map, map->scale);
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
