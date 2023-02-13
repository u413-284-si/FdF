/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:01:17 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/13 15:55:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/initiate.h"
#include "../inc/error.h"
#include "../inc/parse.h"
#include "../inc/colour.h"

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
	ft_printf("\nMap reading terminated.\nInitiating GUI.\n");
}

/* This function initiates all the variables declared in t_map with
default values. */

void	initiate(t_map *map)
{
	map->point_count = 0;
	map->limits.coord[X] = 0;
	map->limits.coord[Y] = 0;
	map->limits.coord[Z] = 0;
	map->origin.coord[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->origin.coord[Y] = WINY / 2;
	map->origin.coord[Z] = 0;
	map->angle[X] = atan(sqrt(2));
	map->angle[Y] = 0;
	map->angle[Z] = 45;
	map->space = 10;
	map->z_min = 0;
	map->scale = 1;
	map->perf = 0;
	map->render_count = 0;
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
			map->limits.coord[Y]++;
			if (map->limits.coord[X] != 0 && map->limits.coord[X] != x_dim)
				terminate(ERR_MAP_UNIFORMITY);
			else
				map->limits.coord[X] = x_dim;
			x_dim = 0;
		}
	}
	if (map->limits.coord[X] != 0 && map->limits.coord[X] != x_dim)
		terminate(ERR_MAP_UNIFORMITY);
	map->limits.coord[Y]++;
	map->point_count = map->limits.coord[X] * map->limits.coord[Y];
}
