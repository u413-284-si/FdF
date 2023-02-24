/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/24 21:20:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip_bonus.h"
#include "../inc/manip.h"
#include "../inc/image.h"

/* This function moves the map in the window by adding an offset
to the individual vectors of the map. */

void	shift(t_map *map, t_point offset)
{
	int	i;

	i = -1;
	while (++i < map->point_count)
		map->point[i] = vec_add(map->point[i], offset);
}

/* This function manipulates the z-value of the map vectors.*/

void	scale_z(t_map *map, t_point increment)
{
	int	i;

	i = -1;
	while (++i < map->point_count)
		map->point[i] = vec_add(map->point[i], increment);
}

/* This function resets the map vectors to its original state after reading
the file. */

void	reset(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = data->map.prjct[i];
	put_i_persp(data);
}
