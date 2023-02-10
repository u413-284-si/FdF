/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:26:52 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/10 13:19:57 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/error.h"
#include "../inc/initiate.h"
#include "../inc/window.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		terminate(ERR_ARGC);
	system_boot(&data.map, argv[1]);
	load_gui(&data);
	free(data.map.point);
	free(data.map.buf);
	return (0);
}
