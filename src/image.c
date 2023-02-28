/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:48:12 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 17:45:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/image.h"
#include "../inc/transformation.h"
#include "../inc/algo.h"
#include "../inc/colour.h"
#include "../inc/manip.h"
#include "../inc/utils.h"

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

/* This function calls the Bresenham algorithm in order to draw a
line between to given points only when two conditions are met:

* The starting point does not draw a line to the right neighbour, if
it lies on the right outer edge of the map
* The starting point does not draw a line to its lower neighbour, if
it lies on the lower edge of the map

The given points are shifted to the origin of the map to be rendered.
*/

void	render_map(t_point *point, t_data *data)
{
	int		i;
	t_point	cur;
	t_point	right;
	t_point	below;

	i = -1;
	while (++i < data->map.point_count)
	{
		cur = vec_add(point[i], data->map.origin);
		if ((i + 1) % (int)data->map.limits.x != 0)
		{
			right = vec_add(point[i + 1], data->map.origin);
			bham(cur, right, data);
		}
		if (i < data->map.point_count - data->map.limits.x)
		{
			below = vec_add(point[i + (int)data->map.limits.x], \
				data->map.origin);
			bham(cur, below, data);
		}
	}
}


/* This function renders a menu unto the window.*/

void	render_menu(t_data *data)
{
	int	y;

	y = RENDER_INFO;
	put_str(data, LINE_START, y, ">>> RENDERING DATA <<<");
	put_str(data, LINE_START, y + LINE_HEIGHT, "Render count:");
	put_nbr(data, LINE_START + 100, y + LINE_HEIGHT, data->map.render_count);
	put_str(data, LINE_START, y + 2 * LINE_HEIGHT, "Performance [ms]:");
	put_nbr(data, LINE_START + 110, y + 2 * LINE_HEIGHT, data->map.perf * 1000);
	put_str(data, LINE_START, y + 3 * LINE_HEIGHT, "Angle position:");
	put_str(data, LINE_START, y + 4 * LINE_HEIGHT, "X Y: [     ] [     ]");
	put_nbr(data, LINE_START + 40, y + 4 * LINE_HEIGHT, data->map.cur_angle[X]);
	put_nbr(data, LINE_START + 90, y + 4 * LINE_HEIGHT, data->map.cur_angle[Y]);
	put_str(data, LINE_START, y + 5 * LINE_HEIGHT, "Zoom:");
	put_nbr(data, LINE_START + 40, y + 5 * LINE_HEIGHT, data->map.scale);
	y = MAP_INFO;
	put_str(data, LINE_START, y, ">>> MAP DATA <<<");
	put_str(data, LINE_START, y + LINE_HEIGHT, "Amount of points:");
	put_nbr(data, LINE_START + 110, y + LINE_HEIGHT, data->map.point_count);
	put_str(data, LINE_START, y + 2 * LINE_HEIGHT, "X_max:");
	put_nbr(data, LINE_START + 50, y + 2 * LINE_HEIGHT, data->map.limits.x);
	put_str(data, LINE_START, y + 3 * LINE_HEIGHT, "Y_max:");
	put_nbr(data, LINE_START + 50, y + 3 * LINE_HEIGHT, data->map.limits.y);
	put_str(data, LINE_START, y + 4 * LINE_HEIGHT, "Z_max:");
	render_menu2(data, y);
}

/* This function is a continuation of render_menu.*/

void	render_menu2(t_data *data, int y)
{
	put_nbr(data, LINE_START + 50, y + 4 * LINE_HEIGHT, data->map.limits.z);
	put_str(data, LINE_START, y + 5 * LINE_HEIGHT, "Z_min:");
	put_nbr(data, LINE_START + 50, y + 5 * LINE_HEIGHT, data->map.z_min);
	y = CONTROL_INFO;
	put_str(data, LINE_START, y, ">>> CONTROLS <<<");
	put_str(data, LINE_START, y + LINE_HEIGHT, "Zoom: +/-");
	put_str(data, LINE_START, y + 2 * LINE_HEIGHT, "Rotate: WASD");
	put_str(data, LINE_START, y + 3 * LINE_HEIGHT, "Move: Arrow keys");
	put_str(data, LINE_START, y + 4 * LINE_HEIGHT, "Scale z-value: Q/E");
	put_str(data, LINE_START, y + 5 * LINE_HEIGHT, "Reset: R");
	put_str(data, LINE_START, y + 6 * LINE_HEIGHT, "Top view: T");
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

/* void	alpha_pix_put(t_data *data, int x, int y, int colour)
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
} */
