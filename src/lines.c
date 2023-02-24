/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:10:43 by frafal            #+#    #+#             */
/*   Updated: 2023/02/24 14:04:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/manip.h"
#include "../inc/image.h"

float_t	get_percentage(int start, int end, int cur)
{
	float_t	position;
	float_t	delta;

	delta = end - start;
	if (delta == 0)
		return (1.0);
	position = cur - start;
	return (position / delta);
}

int	calc_color_channel(int start, int end, float_t percentage)
{
	int	color_channel;

	color_channel = (1 - percentage) * start + percentage * end;
	return (color_channel);
}

int	get_color(t_point cur, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	if (cur.colour == end.colour)
		return (cur.colour);
	if (delta.x > delta.y)
		percentage = get_percentage(start.x, end.x, cur.x);
	else
		percentage = get_percentage(start.y, end.y, cur.y);
	red = calc_color_channel((start.colour >> 16) & 0xFF,
			(end.colour >> 16) & 0xFF, percentage);
	green = calc_color_channel((start.colour >> 8) & 0xFF,
			(end.colour >> 8) & 0xFF, percentage);
	blue = calc_color_channel(start.colour & 0xFF, end.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	draw_line_low(t_img *img, t_point start, t_point end)
{
	int		err;
	int		yi;
	t_point	delta;
	t_point	cur;

	delta = vec_sub(end, start);
	yi = 1;
	if (delta.y < 0)
		yi = -1;
	delta.y = abs(delta.y);
	err = 2 * delta.y - delta.x;
	cur = start;
	while (cur.x < end.x)
	{
		img_pix_put(img, cur.x, cur.y, cur.colour);
		if (err > 0)
			cur.y += yi;
		if (err > 0)
			err = err + (2 * (delta.y - delta.x));
		else
			err = err + 2 * delta.y;
		cur.colour = get_color(cur, start, end, delta);
		cur.x++;
	}
	return (0);
}

int	draw_line_high(t_img *img, t_point start, t_point end)
{
	int		err;
	int		xi;
	t_point	delta;
	t_point	cur;

	delta = vec_sub(end, start);
	xi = 1;
	if (delta.x < 0)
		xi = -1;
	delta.x = abs(delta.x);
	err = 2 * delta.x - delta.y;
	cur = start;
	while (cur.y < end.y)
	{
		img_pix_put(img, cur.x, cur.y, cur.colour);
		if (err > 0)
			cur.x += xi;
		if (err > 0)
			err = err + (2 * (delta.x - delta.y));
		else
			err = err + 2 * delta.x;
		cur.colour = get_color(cur, start, end, delta);
		cur.y++;
	}
	return (0);
}

int	draw_line(t_img *img, t_point start, t_point end)
{
	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
			return (draw_line_low(img, end, start));
		return (draw_line_low(img, start, end));
	}
	if (start.y > end.y)
		return (draw_line_high(img, end, start));
	return (draw_line_high(img, start, end));
	return (-1);
}
