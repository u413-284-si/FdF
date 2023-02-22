/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:30:58 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/22 14:00:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/window.h"
#include "../inc/error.h"
#include "../inc/image.h"

/* This function initiates and controls the graphical window handling all
key and mouse events while the window is opened. It serves as a meta
function assembling all sub-functions executing the image generation.*/

int	load_gui(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINX, WINY, \
					"Get Schwifty by u413");
	if (!data->win_ptr)
	{
		//free(data->win_ptr);
		return (-1);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINX, WINY);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
					&data->img.line_len, &data->img.endian);
	return (0);
}

/* This function is responsible for the rendering of the image. */

int	render(t_data *data)
{
	clock_t	t;

	if (data->win_ptr == NULL)
		return (1);
	t = clock();
	data->map.prjct = ft_calloc (data->map.point_count, sizeof(t_point));
	if (!data->map.prjct)
		terminate(ERR_MEM);
	ft_memcpy(data->map.prjct, data->map.point, \
		(size_t)(data->map.point_count * sizeof(t_point)));
	render_background(&data->img, data->map.colours.background_colour, \
		data->map.colours.menu_colour);
	render_map(data);
	data->map.render_count += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
		0, 0);
	free(data->map.prjct);
	t = clock() - t;
	data->map.perf = (double)t / CLOCKS_PER_SEC;
	return (0);
}

/* This function is responsible for a clean shutdown of the GUI and any
occupied memory. */

int	shutdown(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
		{			
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data->map.point);
	free(data->map.buf);
	return (0);
}
