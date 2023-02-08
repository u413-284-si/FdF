/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:48:12 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/07 18:54:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "image.h"
#include "transformation.h"
#include "algo.h"

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

void	render_map(t_map *map, t_img *img, t_point *prjct)
{
	rotate_z(prjct, map->angle[Z], map->point_count);
	rotate_x(prjct, map->angle[X], map->point_count);
	orthographic_prjct(prjct, map->point_count);
	while ()
		line_draw(start, end);
}
