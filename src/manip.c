/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:35:54 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/27 12:18:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip.h"

/* This function applies a vector addition of vec2 on vec1 altering the
values of vec1. */

t_point	vec_add(t_point vec1, t_point vec2)
{
	t_point	rtrn;

	rtrn.x = vec1.x + vec2.x;
	rtrn.y = vec1.y + vec2.y;
	rtrn.z = vec1.z + vec2.z;
	rtrn.colour = vec1.colour;
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
	return (rtrn);
}

/* This function creates the effect of zooming in/out of the picture by
multiplying the individual vectors with a factor. */

t_point	*zoom(t_point *point, t_map *map, float_t factor)
{
	int		i;
	t_point	*rtrn;

	rtrn = point;
	i = -1;
	while (++i < map->point_count)
		rtrn[i] = vec_scalarmult(point[i], factor);
	return (rtrn);
}
