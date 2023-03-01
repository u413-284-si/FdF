/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:38:19 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/01 13:32:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip2.h"
#include "../inc/transformation.h"

/* This function resets the map vectors to its original state after reading
the file. */

void	reset(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = data->map.prjct[i];
	data->map.base_i = (t_point){1, 0, 0, 0x0};
	data->map.base_j = (t_point){0, 1, 0, 0x0};
	data->map.base_k = (t_point){0, 0, 1, 0x0};
}

/* This function performs the transformation required by the given
matrix "mat" on the points and the base vectors of the map. */

void	transf(t_data *data, t_mat mat)
{
	int		i;

	i = -1;
	while (++i < data->map.point_count)
		data->map.point[i] = mat_mult(mat, data->map.point[i]);
	data->map.base_i = mat_mult(mat, data->map.base_i);
	data->map.base_j = mat_mult(mat, data->map.base_j);
	data->map.base_k = mat_mult(mat, data->map.base_k);
}
