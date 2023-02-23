/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:48:12 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/23 17:01:42 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/image.h"
#include "../inc/transformation.h"
#include "../inc/algo.h"
#include "../inc/colour.h"
#include "../inc/manip.h"

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
	if (x < 0 || x >= WINX || y < 0 || y >= WINY)
		return ;
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

/* This function executes the attribution of a given colour to the specified
pixel (specified by coordinates x and y). It factors in the alpha value.
*/

void	alpha_pix_put(t_data *data, int x, int y, int colour)
{
	char	*pixel;
	int		alpha;

	alpha = 0;
	if (x < MENU_WIDTH)
		alpha = -10;
	else if (x < 0 || x >= WINX || y < 0 || y >= WINY)
		return ;
	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	if (data->img.bpp != 32)
		colour = mlx_get_color_value(data->mlx_ptr, colour);
	set_colour(pixel, data->img.endian, colour, alpha);
}

/* This function rotates the map into the required perspective. */

void	put_i_persp(t_data *data)
{
	rotate_z(data->map.prjct, data->map.angle[Z], data->map.point_count);
	rotate_x(data->map.prjct, data->map.angle[X], data->map.point_count);
	//orthographic_prjct(data->map.prjct, data->map.point_count);
}

/* This function calls the Bresenham algorithm in order to draw a
line between to given points only when two conditions are met:

* The starting point does not draw a line to the right neighbour, if
it lies on the right outer edge of the map
* The starting point does not draw a line to its lower neighbour, if
it lies on the lower edge of the map

The given points are shifted to the origin of the map to be rendered.
*/

void	render_map(t_point *prjct, t_data *data)
{
	int		i;
	t_point	cur;
	t_point	right;
	t_point	below;

	i = -1;
	while (++i < data->map.point_count)
	{
		cur = vec_add(prjct[i], data->map.origin);
		if ((i + 1) % data->map.limits.x != 0)
		{
			right = vec_add(prjct[i + 1], data->map.origin);
			bham(cur, right, data);
		}
		else if (i < data->map.point_count - data->map.limits.x)
		{
			below = vec_add(prjct[i + data->map.limits.x], \
				data->map.origin);
			bham(cur, below, data);
		}
	}
}
