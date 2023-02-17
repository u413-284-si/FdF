/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:35:54 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/17 12:22:56 by sqiu             ###   ########.fr       */
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
	return (rtrn);
}

/* This function multiplies the vector with a scalar. */

t_point	vec_scalarmult(t_point vec, double scalar)
{
	t_point	rtrn;

	rtrn.x = vec.x * scalar;
	rtrn.y = vec.y * scalar;
	rtrn.z = vec.z * scalar;
	return (rtrn);
}
