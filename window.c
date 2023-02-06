/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:30:58 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/06 16:43:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"
#include "image.h"
#include "events.h"

/* This function initiates and controls the graphical window handling all
key and mouse events while the window is opened. It serves as a meta
function assembling all sub-functions executing the image generation.*/

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
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

/* This function is responsible for the rendering of the image. */

int	render(t_data *data)
{
	t_point	*prjct;
	clock_t	t;
	int		i;

	if (data->win_ptr == NULL)
		return (1);
	t = clock();
	prjct = (t_point *) malloc (data->map.point_count * sizeof(t_point));
	if (!prjct)
		terminate(ERR_MEM);
	i = -1;
	while (++i < data->map.point_count)
		prjct[i] = data->map.point[i];
	render_background(&data->img, data->map.colours.background_colour, \
		data->map.colours.menu_colour);
	render_map(&data->map, &data->img, prjct);
	data->map.render_count += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
		0, 0);
	free(prjct);
	t = clock() - t;
	data->map.perf = (double)t / CLOCKS_PER_SEC;
	return (0);
}
