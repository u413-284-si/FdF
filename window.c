/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:30:58 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/03 15:24:49 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"
#include "image.h"

void	load_gui(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		terminate(ERR_MLX);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINX, WINY, \
					"Get Schwifty by u413");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		terminate(ERR_MLX);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINX, WINY);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
					&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx_ptr, &render, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, data->map.colours.background_colour);
	render_map(); //need to define
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
		0, 0);
	return (0);
}
