/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:07:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/23 17:23:52 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/events_bonus.h"
#include "../inc/manip_bonus.h"
#include "../inc/transformation.h"
#include "../inc/window.h"

/* This function handles all keypress events assigning individual actions
to each key being pressed. */

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		joder(data);
	if (keysym == XK_plus)
		zoom(&data->map, ZOOM_FACTOR);
	if (keysym == XK_minus)
		zoom(&data->map, 1 / ZOOM_FACTOR);
	if (keysym == XK_Left)
		shift(&data->map, (t_point){-10, 0, 0, 0x0});
	if (keysym == XK_Right)
		shift(&data->map, (t_point){10, 0, 0, 0x0});
	if (keysym == XK_Up)
		shift(&data->map, (t_point){0, -10, 0, 0x0});
	if (keysym == XK_Down)
		shift(&data->map, (t_point){0, 10, 0, 0x0});
	if (keysym == XK_w)
		rotate_x(data->map.prjct, -1.5, data->map.point_count);
	if (keysym == XK_s)
		rotate_x(data->map.prjct, 1.5, data->map.point_count);
	else
		handle_keypress2(keysym, data);
	return (0);
}

/* This function is the continuation of handling all keypress
events assigning individual actions to each key being pressed. */

int	handle_keypress2(int keysym, t_data *data)
{
	if (keysym == XK_a)
		rotate_y(data->map.prjct, 1.5, data->map.point_count);
	if (keysym == XK_d)
		rotate_y(data->map.prjct, -1.5, data->map.point_count);
	if (keysym == XK_q)
		scale_z(&data->map, (t_point){0, 0, 5, 0x0});
	if (keysym == XK_e)
		scale_z(&data->map, (t_point){0, 0, -5, 0x0});
	if (keysym == XK_r)
		reset(data);
	return (0);
}
