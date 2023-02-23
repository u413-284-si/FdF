/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:14 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/23 10:45:41 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/transformation.h"

/* This function performs a matrix multiplication of a 3D-vector with a
3x3 matrix. */

void	mat_mult(float matrix[3][3], t_point *prjct)
{
	prjct->x = matrix[0][0] * prjct->x + matrix[0][1] * prjct->y + \
		matrix[0][2] * prjct->z;
	prjct->y = matrix[1][0] * prjct->x + matrix[1][1] * prjct->y + \
		matrix[1][2] * prjct->z;
	prjct->z = matrix[2][0] * prjct->x + matrix[2][1] * prjct->y + \
		matrix[2][2] * prjct->z;
}

/* This function performs a rotation in positive direction of the given
vectors around the x-axis by the given angle. */

void	rotate_x(t_point *prjct, double angle, int point_count)
{
	int		i;
	double	rad;
	float	rotate[3][3];

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
		mat_mult(rotate, &prjct[i]);
}

/* This function performs a rotation in positive direction of the given
vectors around the y-axis by the given angle. */

void	rotate_y(t_point *prjct, double angle, int point_count)
{
	int		i;
	double	rad;
	float	rotate[3][3];

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
		mat_mult(rotate, &prjct[i]);
}

/* This function performs a rotation in positive direction of the given
vectors around the z-axis by the given angle. */

void	rotate_z(t_point *prjct, double angle, int point_count)
{
	int		i;
	double	rad;
	float	rotate[3][3];

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
		mat_mult(rotate, &prjct[i]);
}

/* This function performs an orthographic projection - therefore
representing a 3D object in 2D. The projection is parallel with
all projection lines orthogonal to the projection plane. */

void	orthographic_prjct(t_point *prjct, int point_count)
{
	int		i;
	float	ortho[3][3];

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
		mat_mult(ortho, &prjct[i]);
}
