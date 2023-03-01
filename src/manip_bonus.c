/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/01 13:47:12 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip_bonus.h"
#include "../inc/manip.h"
#include "../inc/manip2.h"
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

void	scale_z(t_data *data, float_t increment)
{
	int		i;
	t_mat	cur;
	t_mat	incr;

	cur = (t_mat){data->map.base_i.x, data->map.base_j.x, data->map.base_k.x, \
		data->map.base_i.y, data->map.base_j.y, data->map.base_k.y, \
		data->map.base_i.z, data->map.base_j.z, data->map.base_k.z};
	incr = (t_mat){1, 0, 0, 0, 1, 0, 0, 0, increment};
	reset(data);
	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = mat_mult(incr, data->map.point[i]);
	data->map.base_i = mat_mult(incr, data->map.base_i);
	data->map.base_j = mat_mult(incr, data->map.base_j);
	data->map.base_k = mat_mult(incr, data->map.base_k);
	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = mat_mult(cur, data->map.point[i]);
	data->map.base_i = mat_mult(cur, data->map.base_i);
	data->map.base_j = mat_mult(cur, data->map.base_j);
	data->map.base_k = mat_mult(cur, data->map.base_k);
}
