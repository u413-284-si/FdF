/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:49:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/09 17:20:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "algo.h"
#include "image.h"

/* This function is an implementation of the signum function.*/

int	sgn(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}

/* This function draws a line between two points 'start' and 'end' by 
applying Bresenham's algorithm.
To cover all octants of a cartesian coordinate system, the sign
of the movement direction and the respective 'velocities' of dx
and dy need to be considered. 

Fast direction: -greater delta to be covered, leading step, parallel
				step
Slow direction: -smaller delta to be covered, following, diagonal step,
				only executed if error < 0

*/

void	bham(t_point start, t_point end, t_img *img)
{
	t_bham	algo;

	algo = (t_bham){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	assign_roles(start, end, algo);
	radetzky(start, end, algo, img);
}

/* This function determines the direction of the movement of the line_draw
as well as which coordinate (x or y) takes on the 'fast' role. 

dx > dy: x is the fast direction
dx < dy: y is the fast direction

*/

void	assign_roles(t_point start, t_point end, t_bham algo)
{
	algo.dx = end.coord[X] - start.coord[X];
	algo.dy = end.coord[Y] - start.coord[Y];
	algo.incx = sgn(algo.dx);
	algo.incy = sgn(algo.dy);
	if (algo.dx < 0)
		algo.dx *= -1;
	if (algo.dy < 0)
		algo.dy *= -1;
	algo.ddx = algo.incx;
	algo.ddy = algo.incy;
	if (algo.dx > algo.dy)
	{
		algo.pdx = algo.incx;
		algo.pdy = 0;
		algo.delta_fast_direction = algo.dx;
		algo.delta_slow_direction = algo.dy;
	}
	else
	{
		algo.pdx = 0;
		algo.pdy = algo.incy;
		algo.delta_fast_direction = algo.dy;
		algo.delta_slow_direction = algo.dx;
	}
}

/* This function executes the march of the algorithm pixel by pixel
in direction of the end point whilst colouring the pixels on its
path. 

err < 0: diagonal step ddx and ddy
err >= 0: parallel step pdx and pdy

*/

void	radetzky(t_point start, t_point end, t_bham algo, t_img *img)
{
	algo.x = start.coord[X];
	algo.y = start.coord[Y];
	algo.err = algo.delta_fast_direction / 2;
	set_pixel(algo, img);
	while (++algo.i < algo.delta_fast_direction)
	{
		algo.err -= algo.delta_slow_direction;
		if (algo.err < 0)
		{
			algo.err += algo.delta_fast_direction;
			algo.x += algo.ddx;
			algo.y += algo.ddy;
		}
		else
		{
			algo.x += algo.pdx;
			algo.y += algo.pdy;
		}
		set_pixel(algo, img);
	}
}

/* This function determines if the current pixel has already a colour
assigned. If not, it assigns the background colour. It then puts
the according colour to the image. */

void	set_pixel(t_bham algo, t_img *img)
{
	t_point	cur;

	cur.coord[X] = algo.x;
	cur.coord[Y] = algo.y;
	if (cur.colour == 0)
		cur.colour == BACKGROUND_COLOUR;
	img_pix_put(img, cur.coord[X], cur.coord[Y], cur.colour);
}
