/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:07:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/02 11:11:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/events_bonus.h"
#include "../inc/manip_bonus.h"
#include "../inc/manip.h"
#include "../inc/manip2.h"
#include "../inc/transformation.h"
#include "../inc/window.h"
#include "../inc/initiate.h"

/* This function handles all keypress events assigning individual actions
to each key being pressed. */

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		joder(data);
	if (keysym == XK_plus)
		zoom(data->map.point, &data->map, ZOOM_FACTOR);
	if (keysym == XK_minus)
		zoom(data->map.point, &data->map, 1 / ZOOM_FACTOR);
	if (keysym == XK_Left)
		shift(&data->map, (t_point){-10, 0, 0, 0x0});
	if (keysym == XK_Right)
		shift(&data->map, (t_point){10, 0, 0, 0x0});
	if (keysym == XK_Up)
		shift(&data->map, (t_point){0, -10, 0, 0x0});
	if (keysym == XK_Down)
		shift(&data->map, (t_point){0, 10, 0, 0x0});
	if (keysym == XK_w)
	{
		rotate_x(data, 5);
		data->map.cur_angle[X] += 5;
	}
	else
		handle_keypress2(keysym, data);
	return (0);
}

/* This function is the continuation of handling all keypress
events assigning individual actions to each key being pressed. */

int	handle_keypress2(int keysym, t_data *data)
{
	if (keysym == XK_s)
	{
		rotate_x(data, -5);
		data->map.cur_angle[X] += -5;
	}
	if (keysym == XK_a)
	{
		rotate_y(data, -5);
		data->map.cur_angle[Y] += -5;
	}
	if (keysym == XK_d)
	{
		rotate_y(data, 5);
		data->map.cur_angle[Y] += 5;
	}
	if (keysym == XK_q)
		scale_z(data, 1.05);
	if (keysym == XK_e)
		scale_z(data, 1 / 1.05);
	else
		handle_keypress3(keysym, data);
	return (0);
}

/* This function is the continuation of handling all keypress
events assigning individual actions to each key being pressed. */

int	handle_keypress3(int keysym, t_data *data)
{
	if (keysym == XK_r)
	{
		reset(data);
		data->map.initial = 1;
		put_i_persp(data);
		scale(&data->map);
		data->map.cur_angle[X] = data->map.angle[X];
		data->map.cur_angle[Y] = data->map.angle[Y];
		data->map.cur_angle[Z] = data->map.angle[Z];
		data->map.cur_scale = data->map.scale;
	}
	if (keysym == XK_t)
	{
		reset(data);
		scale(&data->map);
		data->map.cur_angle[X] = 0;
		data->map.cur_angle[Y] = 0;
		data->map.cur_angle[Z] = 0;
		data->map.cur_scale = data->map.scale;
	}
	else
		handle_keypress4(keysym, data);
	return (0);
}

/* This function is the continuation of handling all keypress
events assigning individual actions to each key being pressed. */

int	handle_keypress4(int keysym, t_data *data)
{
	if (keysym == XK_y)
	{
		rotate_z(data, -5);
		data->map.cur_angle[Z] += -5;
	}
	if (keysym == XK_x)
	{
		rotate_z(data, 5);
		data->map.cur_angle[Z] += 5;
	}
	return (0);
}
