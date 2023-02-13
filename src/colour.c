/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:37 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/10 13:20:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/colour.h"
#include "../inc/utils.h"

/* This function applies colour to the respective points according to their
z-value (height).*/

void	colour(t_map *map)
{
	static int	point_index = -1;

	increment(map);
	while (++point_index < map->point_count)
	{
		if (map->point[point_index].colour == DEFAULT_COLOUR)
		{
			if (map->point[point_index].coord[Z] == map->limits.coord[Z])
				map->point[point_index].colour = map->colours.top_colour;
			else if (map->point[point_index].coord[Z] == map->z_min)
				map->point[point_index].colour = map->colours.bottom_colour;
			else if (map->point[point_index].coord[Z] == 0)
				map->point[point_index].colour = map->colours.zero_lv_colour;
			else if (map->point[point_index].coord[Z] > 0)
				map->point[point_index].colour = \
				gradient(map->colours.increment_pos, \
				map->colours.zero_lv_colour, \
				map->point[point_index].coord[Z]);
			else
				map->point[point_index].colour = \
				gradient(map->colours.increment_neg, \
				map->colours.bottom_colour, \
				-map->point[point_index].coord[Z]);
		}
	}
}

/* This function calculates the dimension of the colour increments according to
the max and min z-value of the given map. The higher the respective values,
the larger the covered range of the colour spectrum, therefore the smaller
the increment has to be in order to be able to differentiate between each
height value.*/

void	increment(t_map *map)
{
	map->colours.increment_pos[0] = \
		(double)((map->colours.top_colour >> 16) - \
		(map->colours.zero_lv_colour >> 16)) / (double)map->limits.coord[Z];
	map->colours.increment_pos[1] = \
		(double)(((map->colours.top_colour >> 8) & 0xFF) - \
		((map->colours.zero_lv_colour >> 8) & 0xFF)) / \
		(double)map->limits.coord[Z];
	map->colours.increment_pos[2] = \
		(double)((map->colours.top_colour & 0xFF) - \
		(map->colours.zero_lv_colour & 0xFF)) / (double)map->limits.coord[Z];
	map->colours.increment_neg[0] = \
		(double)((map->colours.zero_lv_colour >> 16) - \
		(map->colours.bottom_colour >> 16)) / (double)-map->z_min;
	map->colours.increment_neg[1] = \
		(double)(((map->colours.zero_lv_colour >> 8) & 0xFF) - \
		((map->colours.bottom_colour >> 8) & 0xFF)) / (double)-map->z_min;
	map->colours.increment_neg[2] = \
		(double)((map->colours.zero_lv_colour & 0xFF) - \
		(map->colours.bottom_colour & 0xFF)) / (double)-map->z_min;
}

/* This function uses the calculated colour increment and applies the
appropriate colour value to each point - via the RGB colour model - 
according to its height value. */

int	gradient(double *increment, int start_colour, int pos)
{
	int		new[3];
	int		new_colour;

	new[0] = (start_colour >> 16) + roundme(increment[0] * pos);
	new[1] = ((start_colour >> 8) & 0xFF) + roundme(increment[1] * pos);
	new[2] = (start_colour & 0xFF) + roundme(increment[2] * pos);
	new_colour = (new[0] << 16) + (new[1] << 8) + new[2];
	return (new_colour);
}

/* This function calculates the dimension of the colour increments according to
the distance between two points and their respective colours. 
It then assigns the appropriate colour according to the position
along that distance.*/

int	gradient_interpoints(t_point start, t_point end, int pos)
{
	int		distance;
	double	increment[3];
	int		new[3];
	int		new_colour;

	distance = roundme(sqrt(pow(end.coord[Y] - start.coord[Y], 2) \
		+ pow(end.coord[X] - start.coord[X], 2)));
	increment[0] = (double)((end.colour >> 16) - (start.colour >> 16)) \
		/ (double)distance;
	increment[1] = (double)(((end.colour >> 8) & 0xFF) - \
		((start.colour >> 8) & 0xFF)) / (double)distance;
	increment[2] = (double)((end.colour & 0xFF) - (start.colour & 0xFF)) \
		/ (double)distance;
	new[0] = (start.colour >> 16) + roundme(increment[0] * pos);
	new[1] = ((start.colour >> 8) & 0xFF) + roundme(increment[1] * pos);
	new[2] = (start.colour & 0xFF) + roundme(increment[2] * pos);
	new_colour = (new[0] << 16) + (new[1] << 8) + new[2];
	return (new_colour);
}