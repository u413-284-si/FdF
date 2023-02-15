/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:35:54 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/15 17:17:14 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip.h"

/* This function applies a vector addition of vec2 on vec1 altering the
values of vec1. */

t_point	vec_add(t_point vec1, t_point vec2)
{
	t_point	rtrn;

	rtrn.coord[X] = vec1.coord[X] + vec2.coord[X];
	rtrn.coord[Y] = vec1.coord[Y] + vec2.coord[Y];
	rtrn.coord[Z] = vec1.coord[Z] + vec2.coord[Z];
	return (rtrn);
}

/* This function multiplies the vector with a scalar. */

t_point	vec_scalarmult(t_point vec, int scalar)
{
	t_point	rtrn;

	rtrn.coord[X] = vec.coord[X] * scalar;
	rtrn.coord[Y] = vec.coord[Y] * scalar;
	rtrn.coord[Z] = vec.coord[Z] * scalar;
	return (rtrn);
}
