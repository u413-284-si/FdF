/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:37 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/27 12:30:11 by sqiu             ###   ########.fr       */
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
			if (map->point[point_index].z == map->limits.z)
				map->point[point_index].colour = map->colours.top_colour;
			else if (map->point[point_index].z == map->z_min)
				map->point[point_index].colour = map->colours.bottom_colour;
			else if (map->point[point_index].z == 0)
				map->point[point_index].colour = map->colours.zero_lv_colour;
			else if (map->point[point_index].z > 0)
				map->point[point_index].colour = \
				gradient(map->colours.increment_pos, \
				map->colours.zero_lv_colour, \
				map->point[point_index].z);
			else
				map->point[point_index].colour = \
				gradient(map->colours.increment_neg, \
				map->colours.bottom_colour, \
				-map->point[point_index].z);
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
		(float_t)((map->colours.top_colour >> 16) - \
		(map->colours.zero_lv_colour >> 16)) / (float_t)map->limits.z;
	map->colours.increment_pos[1] = \
		(float_t)(((map->colours.top_colour >> 8) & 0xFF) - \
		((map->colours.zero_lv_colour >> 8) & 0xFF)) / \
		(float_t)map->limits.z;
	map->colours.increment_pos[2] = \
		(float_t)((map->colours.top_colour & 0xFF) - \
		(map->colours.zero_lv_colour & 0xFF)) / (float_t)map->limits.z;
	map->colours.increment_neg[0] = \
		(float_t)((map->colours.zero_lv_colour >> 16) - \
		(map->colours.bottom_colour >> 16)) / (float_t)-map->z_min;
	map->colours.increment_neg[1] = \
		(float_t)(((map->colours.zero_lv_colour >> 8) & 0xFF) - \
		((map->colours.bottom_colour >> 8) & 0xFF)) / (float_t)-map->z_min;
	map->colours.increment_neg[2] = \
		(float_t)((map->colours.zero_lv_colour & 0xFF) - \
		(map->colours.bottom_colour & 0xFF)) / (float_t)-map->z_min;
}

/* This function uses the calculated colour increment and applies the
appropriate colour value to each point - via the RGB colour model - 
according to its height value. */

int	gradient(float_t *increment, int start_colour, float_t pos)
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

int	gradient_interpoints(t_point start, t_point end, float_t pos)
{
	int		distance;
	float_t	increment[3];
	int		new[3];
	int		new_colour;

	distance = roundme(sqrt(pow(end.y - start.y, 2) \
		+ pow(end.x - start.x, 2)));
	increment[0] = (float_t)((end.colour >> 16) - (start.colour >> 16)) \
		/ (float_t)distance;
	increment[1] = (float_t)(((end.colour >> 8) & 0xFF) - \
		((start.colour >> 8) & 0xFF)) / (float_t)distance;
	increment[2] = (float_t)((end.colour & 0xFF) - (start.colour & 0xFF)) \
		/ (float_t)distance;
	new[0] = (start.colour >> 16) + roundme(increment[0] * pos);
	new[1] = ((start.colour >> 8) & 0xFF) + roundme(increment[1] * pos);
	new[2] = (start.colour & 0xFF) + roundme(increment[2] * pos);
	new_colour = (new[0] << 16) + (new[1] << 8) + new[2];
	return (new_colour);
}

/* This function fills the 4 bytes of the given address with the given
colour values depending on the endian
	endian = 1 --> Most significant byte first (= alpha)
    endian = 0 --> Least significant byte first (= blue)
*/

void	set_colour(char *address, int endian, int colour, int alpha)
{
	if (endian == 1)
	{
		address[0] = alpha;
		address[1] = (colour >> 16) & 0xFF;
		address[2] = (colour >> 8) & 0xFF;
		address[3] = (colour) & 0xFF;
	}
	else
	{
		address[0] = (colour) & 0xFF;
		address[1] = (colour >> 8) & 0xFF;
		address[2] = (colour >> 16) & 0xFF;
		address[3] = alpha;
	}
}
