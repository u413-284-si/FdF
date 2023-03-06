/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/06 10:56:20 by sqiu             ###   ########.fr       */
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
	t_mat	cur;
	t_mat	incr;

	cur = (t_mat){data->map.base_i.x, data->map.base_j.x, data->map.base_k.x, \
		data->map.base_i.y, data->map.base_j.y, data->map.base_k.y, \
		data->map.base_i.z, data->map.base_j.z, data->map.base_k.z};
	incr = (t_mat){1, 0, 0, 0, 1, 0, 0, 0, increment};
	if (data->map.initial == 0)
		reset(data);
	transf(data, incr);
	if (data->map.initial == 0)
		transf(data, cur);
}
