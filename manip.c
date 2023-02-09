/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:35:54 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/09 11:52:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "manip.h"

/* This function applies a vector addition of vec2 on vec1 altering the
values of vec1. */

void	vec_add(t_point vec1, t_point vec2)
{
	vec1.coord[X] = vec1.coord[X] + vec2.coord[X];
	vec1.coord[Y] = vec1.coord[Y] + vec2.coord[Y];
	vec1.coord[Z] = vec1.coord[Z] + vec2.coord[Z];
}

/* This function multiplies the vector with a scalar. */

void	vec_scalarmult(t_point vec, int scalar)
{
	vec.coord[X] = vec.coord[X] * scalar;
	vec.coord[Y] = vec.coord[Y] * scalar;
	vec.coord[Z] = vec.coord[Z] * scalar;
}
