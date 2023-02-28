/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 18:37:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip_bonus.h"
#include "../inc/manip.h"
#include "../inc/image.h"
#include "../inc/transformation.h"

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

void	scale_z(t_data *data, t_point increment)
{
	int		i;
	float_t	cur[3][3];

	cur[0][0] = data->map.base_i.x;
	cur[1][0] = data->map.base_i.y;
	cur[2][0] = data->map.base_i.z;
	cur[0][1] = data->map.base_j.x;
	cur[1][1] = data->map.base_j.y;
	cur[2][1] = data->map.base_j.z;
	cur[0][2] = data->map.base_k.x;
	cur[1][2] = data->map.base_k.y;
	cur[2][2] = data->map.base_k.z;
	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = data->map.prjct[i];
	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = vec_add(data->map.point[i], increment);
	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = mat_mult(cur, data->map.point[i]);
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

/* This function displays the map in top view. */

void	top(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = data->map.prjct[i];
}
