/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:14 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/03 09:52:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/transformation.h"
#include "../inc/manip2.h"

/* This function performs a matrix multiplication of a 3D-vector with a
3x3 matrix. */

t_point	mat_mult(t_mat matrix, t_point point)
{
	t_point	rtrn;

	rtrn.x = matrix.r0c0 * point.x + matrix.r0c1 * point.y + \
		matrix.r0c2 * point.z;
	rtrn.y = matrix.r1c0 * point.x + matrix.r1c1 * point.y + \
		matrix.r1c2 * point.z;
	rtrn.z = matrix.r2c0 * point.x + matrix.r2c1 * point.y + \
		matrix.r2c2 * point.z;
	rtrn.colour = point.colour;
	rtrn.hex_given = point.hex_given;
	return (rtrn);
}

/* This function performs a rotation in positive direction of the given
vectors around the x-axis by the given angle. */

void	rotate_x(t_data *data, float_t angle)
{
	float_t	rad;
	t_mat	cur;
	t_mat	rotate;

	rad = angle * M_PI / 180;
	cur = (t_mat){data->map.base_i.x, data->map.base_j.x, data->map.base_k.x, \
		data->map.base_i.y, data->map.base_j.y, data->map.base_k.y, \
		data->map.base_i.z, data->map.base_j.z, data->map.base_k.z};
	rotate = (t_mat){1, 0, 0, 0, cos(rad), -sin(rad), 0, sin(rad), cos(rad)};
	if (data->map.initial == 0)
		reset(data);
	transf(data, rotate);
	if (data->map.initial == 0)
		transf(data, cur);
}

/* This function performs a rotation in positive direction of the given
vectors around the y-axis by the given angle. */

void	rotate_y(t_data *data, float_t angle)
{
	float_t	rad;
	t_mat	cur;
	t_mat	rotate;

	rad = angle * M_PI / 180;
	cur = (t_mat){data->map.base_i.x, data->map.base_j.x, data->map.base_k.x, \
		data->map.base_i.y, data->map.base_j.y, data->map.base_k.y, \
		data->map.base_i.z, data->map.base_j.z, data->map.base_k.z};
	rotate = (t_mat){cos(rad), 0, sin(rad), 0, 1, 0, -sin(rad), 0, cos(rad)};
	if (data->map.initial == 0)
		reset(data);
	transf(data, rotate);
	if (data->map.initial == 0)
		transf(data, cur);
}

/* This function performs a rotation in positive direction of the given
vectors around the z-axis by the given angle. */

void	rotate_z(t_data *data, float_t angle)
{
	float_t	rad;
	t_mat	cur;
	t_mat	rotate;

	rad = angle * M_PI / 180;
	cur = (t_mat){data->map.base_i.x, data->map.base_j.x, data->map.base_k.x, \
		data->map.base_i.y, data->map.base_j.y, data->map.base_k.y, \
		data->map.base_i.z, data->map.base_j.z, data->map.base_k.z};
	rotate = (t_mat){cos(rad), -sin(rad), 0, sin(rad), cos(rad), 0, 0, 0, 1};
	if (data->map.initial == 0)
		reset(data);
	transf(data, rotate);
	if (data->map.initial == 0)
		transf(data, cur);
}

/* This function performs an orthographic projection - therefore
representing a 3D object in 2D. The projection is parallel with
all projection lines orthogonal to the projection plane. */

void	orthographic_prjct(t_data *data)
{
	int		i;
	t_mat	ortho;

	ortho = (t_mat){1, 0, 0, 0, 1, 0, 0, 0, 0};
	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = mat_mult(ortho, data->map.point[i]);
}
