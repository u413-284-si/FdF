/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:12:53 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 18:19:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/initiate2.h"

void	set_min_max(t_map *map)
{
	int		i;
	t_point	*cur;

	map->x_min = 0;
	map->x_max = 0;
	map->y_min = 0;
	map->y_max = 0;
	i = -1;
	while (++i < map->point_count)
	{
		cur = map->point + i;
		if (cur->x < map->x_min)
			map->x_min = cur->x;
		if (cur->x > map->x_max)
			map->x_max = cur->x;
		if (cur->y < map->y_min)
			map->y_min = cur->y;
		if (cur->y > map->y_max)
			map->y_max = cur->y;
	}
}
