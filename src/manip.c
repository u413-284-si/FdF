/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:35:54 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/03 09:53:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip.h"
#include "../inc/transformation.h"

/* This function applies a vector addition of vec2 on vec1 altering the
values of vec1. */

t_point	vec_add(t_point vec1, t_point vec2)
{
	t_point	rtrn;

	rtrn.x = vec1.x + vec2.x;
	rtrn.y = vec1.y + vec2.y;
	rtrn.z = vec1.z + vec2.z;
	rtrn.colour = vec1.colour;
	rtrn.hex_given = vec1.hex_given;
	return (rtrn);
}

/* This function applies a vector subtraction of vec2 on vec1 altering the
values of vec1. */

t_point	vec_sub(t_point vec1, t_point vec2)
{
	t_point	rtrn;

	rtrn.x = vec1.x - vec2.x;
	rtrn.y = vec1.y - vec2.y;
	rtrn.z = vec1.z - vec2.z;
	rtrn.colour = vec1.colour;
	rtrn.hex_given = vec1.hex_given;
	return (rtrn);
}

/* This function multiplies the vector with a scalar. */

t_point	vec_scalarmult(t_point vec, float_t scalar)
{
	t_point	rtrn;

	rtrn.x = vec.x * scalar;
	rtrn.y = vec.y * scalar;
	rtrn.z = vec.z * scalar;
	rtrn.colour = vec.colour;
	rtrn.hex_given = vec.hex_given;
	return (rtrn);
}

/* This function creates the effect of zooming in/out of the picture by
multiplying the individual vectors with a factor. */

t_point	*zoom(t_point *point, t_map *map, float_t factor)
{
	int		i;

	i = -1;
	while (++i < map->point_count)
		point[i] = vec_scalarmult(point[i], factor);
	map->cur_scale *= factor;
	map->base_i = vec_scalarmult(map->base_i, factor);
	map->base_j = vec_scalarmult(map->base_j, factor);
	map->base_k = vec_scalarmult(map->base_k, factor);
	return (point);
}

/* This function rotates the map into the required perspective. */

void	put_i_persp(t_data *data)
{
	rotate_z(data, data->map.angle[Z]);
	rotate_x(data, data->map.angle[X]);
	orthographic_prjct(data);
	data->map.initial = 0;
}
