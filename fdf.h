/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:03:00 by sqiu              #+#    #+#             */
/*   Updated: 2023/01/12 14:53:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Libraries

# include <fcntl.h>			/* required for opening files */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>			/* required for specific error messages */
# include <math.h>
# include <stdbool.h>

# include <X11/X.h>
/* required for macros related to event names & masks */
# include <X11/keysym.h>
/* required for values of all available key symbols */

# include "mlx_linux/mlx.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line_bonus.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Structs

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}	t_data;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_colours
{
	int		top_colour;
	int		zero_lv_colour;
	int		bottom_colour;
	int		background_colour;
	int		menu_colour;
}	t_colours;

typedef struct s_point
{
	int		coord[3];
	int		colour;
	bool	paint;
}	t_point;

typedef struct s_map
{
	t_point		*pixel;
	t_point		limits;
	t_colours	colours;
	char		*buf;
	char		**lines;
	int			z_min;
}	t_map;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Check char functions

#endif
