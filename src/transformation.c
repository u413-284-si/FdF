/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:14 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 18:39:12 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/transformation.h"

/* This function performs a matrix multiplication of a 3D-vector with a
3x3 matrix. */

t_point	mat_mult(float_t matrix[3][3], t_point point)
{
	t_point	rtrn;

	rtrn.x = matrix[0][0] * point.x + matrix[0][1] * point.y + \
		matrix[0][2] * point.z;
	rtrn.y = matrix[1][0] * point.x + matrix[1][1] * point.y + \
		matrix[1][2] * point.z;
	rtrn.z = matrix[2][0] * point.x + matrix[2][1] * point.y + \
		matrix[2][2] * point.z;
	rtrn.colour = point.colour;
	return (rtrn);
}

/* This function performs a rotation in positive direction of the given
vectors around the x-axis by the given angle. */

void	rotate_x(t_map *map, float_t angle, int point_count)
{
	int		i;
	float_t	rad;
	float_t	rotate[3][3];

	rad = angle * M_PI / 180;
	rotate[0][0] = 1;
	rotate[0][1] = 0;
	rotate[0][2] = 0;
	rotate[1][0] = 0;
	rotate[1][1] = cos(rad);
	rotate[1][2] = -sin(rad);
	rotate[2][0] = 0;
	rotate[2][1] = sin(rad);
	rotate[2][2] = cos(rad);
	i = -1;
	while (++i < point_count)
		map->point[i] = mat_mult(rotate, map->point[i]);
	map->base_i = mat_mult(rotate, map->base_i);
	map->base_j = mat_mult(rotate, map->base_j);
	map->base_k = mat_mult(rotate, map->base_k);
}

/* This function performs a rotation in positive direction of the given
vectors around the y-axis by the given angle. */

void	rotate_y(t_map *map, float_t angle, int point_count)
{
	int		i;
	float_t	rad;
	float_t	rotate[3][3];

	rad = angle * M_PI / 180;
	rotate[0][0] = cos(rad);
	rotate[0][1] = 0;
	rotate[0][2] = sin(rad);
	rotate[1][0] = 0;
	rotate[1][1] = 1;
	rotate[1][2] = 0;
	rotate[2][0] = -sin(rad);
	rotate[2][1] = 0;
	rotate[2][2] = cos(rad);
	i = -1;
	while (++i < point_count)
		map->point[i] = mat_mult(rotate, map->point[i]);
	map->base_i = mat_mult(rotate, map->base_i);
	map->base_j = mat_mult(rotate, map->base_j);
	map->base_k = mat_mult(rotate, map->base_k);
}

/* This function performs a rotation in positive direction of the given
vectors around the z-axis by the given angle. */

void	rotate_z(t_map *map, float_t angle, int point_count)
{
	int		i;
	float_t	rad;
	float_t	rotate[3][3];

	rad = angle * M_PI / 180;
	rotate[0][0] = cos(rad);
	rotate[0][1] = -sin(rad);
	rotate[0][2] = 0;
	rotate[1][0] = sin(rad);
	rotate[1][1] = cos(rad);
	rotate[1][2] = 0;
	rotate[2][0] = 0;
	rotate[2][1] = 0;
	rotate[2][2] = 1;
	i = -1;
	while (++i < point_count)
		map->point[i] = mat_mult(rotate, map->point[i]);
	map->base_i = mat_mult(rotate, map->base_i);
	map->base_j = mat_mult(rotate, map->base_j);
	map->base_k = mat_mult(rotate, map->base_k);
}

/* This function performs an orthographic projection - therefore
representing a 3D object in 2D. The projection is parallel with
all projection lines orthogonal to the projection plane. */

void	orthographic_prjct(t_map *map, int point_count)
{
	int		i;
	float_t	ortho[3][3];

	ortho[0][0] = 1;
	ortho[0][1] = 0;
	ortho[0][2] = 0;
	ortho[1][0] = 0;
	ortho[1][1] = 1;
	ortho[1][2] = 0;
	ortho[2][0] = 0;
	ortho[2][1] = 0;
	ortho[2][2] = 0;
	i = -1;
	while (++i < point_count)
		map->point[i] = mat_mult(ortho, map->point[i]);
}
