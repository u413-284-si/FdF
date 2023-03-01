/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:26:52 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/01 12:50:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/error.h"
#include "../inc/initiate.h"
#include "../inc/window.h"
#include "../inc/image.h"
#include "../inc/events_bonus.h"
#include "../inc/manip.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc != 2)
		terminate(ERR_ARGC);
	system_boot(&data.map, argv[1]);
	put_i_persp(&data);
	scale(&data.map);
	if (load_gui(&data) < 0)
		terminate(ERR_MLX);
	ft_printf("\nInitiating rendering.\n");
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, joder, &data);
	mlx_hook(data.win_ptr, KeyPress, 1, handle_keypress, &data);
	mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop(data.mlx_ptr);
	return (0);
}
