/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:01:17 by sqiu              #+#    #+#             */
/*   Updated: 2023/01/16 16:20:40 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "initiate.h"
#include "error.h"

void	system_boot(t_map *map, char *file)
{
	int		fd;
	int		sz;
	int		len;
	
	initiate(map);
	fd = open(file, O_RDONLY);
	if (fd < 3)
		terminate(ERR_OPEN);
	len = 0;
	while (sz > 0)
	{
		sz = read(fd, 0, READ_SIZE);
		if (sz < 0)
			exit(0);
		len += sz;
	}
	buf = malloc (sizeof(char) * len + 1);
	if (!buf)
		terminate(ERR_MEM);
}

void	initiate(t_map *map)
{
	map->len = 0;
	map->limits.coord[X] = 0;
	map->limits.coord[Y] = 0;
	map->limits.coord[Z] = 0;
	map->origin.coord[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->origin.coord[Y] = WINY / 2;
	map->origin.coord[Z] = 0;
	map->angle[X] = 0; 
	map->angle[Y] = 0;
	map->angle[Z] = 0;
	map->z_min = 0;
	map->scale = 1;
	map->z_divisor = 1;
	map->colours.top_colour = TOP_COLOUR;
	map->colours.zero_lv_colour = ZERO_LV_COLOUR;
	map->colours.bottom_colour = BOTTOM_COLOUR;
	map->colours.background_colour = BACKGROUND_COLOUR;
	map->colours.menu_colour = MENU_COLOUR;
}

