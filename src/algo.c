/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:49:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/23 13:39:03 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/algo.h"
#include "../inc/image.h"
#include "../inc/colour.h"
#include "../inc/utils.h"

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

void	bham(t_point start, t_point end, t_data *data)
{
	t_bham	algo;

	algo = (t_bham){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	assign_roles(start, end, &algo);
	radetzky(start, end, &algo, data);
}

/* This function determines the direction of the movement of the line_draw
as well as which coordinate (x or y) takes on the 'fast' role. 

dx > dy: x is the fast direction
dx < dy: y is the fast direction

*/

void	assign_roles(t_point start, t_point end, t_bham *algo)
{
	algo->dx = end.x - start.x;
	algo->dy = end.y - start.y;
	algo->incx = sgn(algo->dx);
	algo->incy = sgn(algo->dy);
	if (algo->dx < 0)
		algo->dx *= -1;
	if (algo->dy < 0)
		algo->dy *= -1;
	algo->ddx = algo->incx;
	algo->ddy = algo->incy;
	if (algo->dx > algo->dy)
	{
		algo->pdx = algo->incx;
		algo->pdy = 0;
		algo->delta_fast_direction = algo->dx;
		algo->delta_slow_direction = algo->dy;
	}
	else
	{
		algo->pdx = 0;
		algo->pdy = algo->incy;
		algo->delta_fast_direction = algo->dy;
		algo->delta_slow_direction = algo->dx;
	}
}

/* This function executes the march of the algorithm pixel by pixel
in direction of the end point whilst colouring the pixels on its
path. 

err < 0: diagonal step ddx and ddy
err >= 0: parallel step pdx and pdy

*/

void	radetzky(t_point start, t_point end, t_bham *algo, t_data *data)
{
	algo->x = start.x;
	algo->y = start.y;
	algo->err = algo->delta_fast_direction / 2;
	set_pixel(algo, data, start, end);
	while (++algo->i < algo->delta_fast_direction)
	{
		algo->err -= algo->delta_slow_direction;
		if (algo->err < 0)
		{
			algo->err += algo->delta_fast_direction;
			algo->x += algo->ddx;
			algo->y += algo->ddy;
		}
		else
		{
			algo->x += algo->pdx;
			algo->y += algo->pdy;
		}
		set_pixel(algo, data, start, end);
	}
}

/* This function assigns the appropriate colour to the current pixel 
according to the gradient between the starting and ending point. */

void	set_pixel(t_bham *algo, t_data *data, t_point start, t_point end)
{
	t_point	cur;
	int		pos;

	(void) end;
	cur.x = algo->x;
	cur.y = algo->y;
	pos = roundme(sqrt(pow(cur.y - start.y, 2) + \
		pow(cur.x - start.x, 2)));
	//cur.colour = DEFAULT_COLOUR;
	cur.colour = gradient_interpoints(start, end, pos);
	alpha_pix_put(data, cur.x, cur.y, cur.colour);
}
