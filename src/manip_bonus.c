/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/16 15:28:45 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip_bonus.h"
#include "../inc/manip.h"

/* This function creates the effect of zooming in/out of the picture by
multiplying the individual vectors with a factor. */

void	zoom(t_map *map, double factor)
{
	int	i;

	i = -1;
	while (++i < map->point_count)
		map->prjct[i] = vec_scalarmult(map->prjct[i], factor);
}

/* This function moves the map in the window by adding an offset
to the individual vectors of the map. */

void	shift(t_map *map, t_point offset)
{
	int	i;

	i = -1;
	while (++i < map->point_count)
		map->prjct[i] = vec_add(map->prjct[i], offset);
}

/* This function manipulates the z-value of the map vectors.*/

void	scale_z(t_map *map, t_point increment)
{
	int	i;

	i = -1;
	while (++i < map->point_count)
		map->prjct[i] = vec_add(map->prjct[i], increment);
}

/* This function resets the map vectors to its original state after reading
the file. */

void	reset(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->point_count)
		map->prjct[i] = map->point[i];
}
