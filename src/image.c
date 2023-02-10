/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:48:12 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/10 13:20:52 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/image.h"
#include "../inc/transformation.h"
#include "../inc/algo.h"

/* This function is responsible for rendering the background of the image.*/

void	render_background(t_img *img, int background_col, int menu_col)
{
	int	i;
	int	j;

	j = 0;
	while (j < WINY)
	{
		i = 0;
		while (i < WINX)
		{
			if (i < MENU_WIDTH)
				img_pix_put(img, i++, j, menu_col);
			else
				img_pix_put(img, i++, j, background_col);
		}
		++j;
	}
}

/* This function executes the attribution of a given colour to the specified
pixel (specified by coordinates x and y). 
	endian = 1 --> Most significant byte first (= alpha)
	endian = 0 --> Least significant byte first (= blue)
*/

void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (colour >> i) & 0xFF;
		else
			*pixel++ = (colour >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/* This function rotates the map into the required perspective
and draws lines between the points of the map. */

void	render_map(t_map *map, t_img *img, t_point *prjct)
{
	rotate_z(prjct, map->angle[Z], map->point_count);
	rotate_x(prjct, map->angle[X], map->point_count);
	orthographic_prjct(prjct, map->point_count);
	line_draw(prjct, img, map);
}

/* This function calls the Bresenham algorithm in order to draw a
line between to given points only when two conditions are met:

* The starting point does not draw a line to the right neighbour, if
it lies on the right outer edge of the map
* The starting point does not draw a line to its lower neighbour, if
it lies on the lower edge of the map

*/

void	line_draw(t_point *prjct, t_img *img, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->point_count)
	{
		if ((i + 1) % map->limits.coord[X] != 0)
			bham(prjct[i], prjct[i + 1], img);
		if (i < map->limits.coord[X] * map->limits.coord[Y] \
			- map->limits.coord[X])
			bham(prjct[i], prjct[i + map->limits.coord[X]], img);
	}
}
