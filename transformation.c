/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:14 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/06 17:11:57 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "transformation.h"

/* This function performs a matrix multiplication of a 3D-vector with a
3x3 matrix. */

void	mat_mult(float matrix[3][3], t_point prjct)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			prjct.coord[i] += matrix[i][j] * prjct.coord[j];
	}
}

void	rotate_x(t_point *prjct, double angle, int point_count)
{
	int		i;
	double	rad;
	float	rotate[3][3];

	rad = angle * M_PI / 180;
	
}
