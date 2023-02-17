/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:07:08 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/17 14:09:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/events_bonus.h"
#include "../inc/manip_bonus.h"
#include "../inc/transformation.h"

/* This function handles all keypress events assigning individual actions
to each key being pressed. */

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (keysym == XK_plus)
		zoom(&data->map, ZOOM_FACTOR);
	else if (keysym == XK_minus)
		zoom(&data->map, 1 / ZOOM_FACTOR);
	else if (keysym == XK_Left)
		shift(&data->map, (t_point){-10, 0, 0, 0x0});
	else if (keysym == XK_Right)
		shift(&data->map, (t_point){10, 0, 0, 0x0});
	else if (keysym == XK_Up)
		shift(&data->map, (t_point){0, -10, 0, 0x0});
	else if (keysym == XK_Down)
		shift(&data->map, (t_point){0, 10, 0, 0x0});
	else if (keysym == XK_w)
		rotate_x(data->map.prjct, -1.5, data->map.point_count);
	else if (keysym == XK_s)
		rotate_x(data->map.prjct, 1.5, data->map.point_count);
	else
		handle_keypress2(keysym, data);
	return (0);
}

int	handle_keypress2(int keysym, t_data *data)
{
	if (keysym == XK_a)
		rotate_y(data->map.prjct, 1.5, data->map.point_count);
	else if (keysym == XK_d)
		rotate_y(data->map.prjct, -1.5, data->map.point_count);
	else if (keysym == XK_q)
		scale_z(&data->map, (t_point){0, 0, 5, 0x0});
	else if (keysym == XK_e)
		scale_z(&data->map, (t_point){0, 0, -5, 0x0});
	else if (keysym == XK_r)
		reset(&data->map);
	return (0);
}
