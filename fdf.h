/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:03:00 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/06 17:11:45 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* 
		====== LIBRARIES ======
*/

# include <fcntl.h>			/* required for opening files */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>			/* required for specific error messages */
# include <math.h>
# include <stdbool.h>
# include <time.h>			/* required to measure time passed in CPU cycles*/
# include <X11/X.h>			
/* required for macros related to event names & masks */
# include <X11/keysym.h>
/* required for values of all available key symbols */
# include "mlx_linux/mlx.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line_bonus.h"

/* 
		====== DEFINITIONS ======
*/

// Window & Coordinates
# define WINX 				1920
# define WINY 				1080
# define X 					0
# define Y 					1
# define Z 					2
# define MENU_WIDTH			350
# define FIT_MARGIN			50

# define DEFAULT_COLOUR		ORANGE
# define BOTTOM_COLOUR		BLUE
# define TOP_COLOUR			BRICK_RED
# define ZERO_LV_COLOUR		FUCHSIA
# define BACKGROUND_COLOUR	CARBON
# define MENU_COLOUR		DISCO
# define TEXT_COLOUR		GREY
# define NUMBER_COLOUR		SAFFRON

// Colours
# define RED 				0xC1272D
# define GREEN				0x33CC55
# define FUCHSIA 			0xFF255C
# define BLUE				0x1B8EFA
# define SUPERBLUE			0x0000FF
# define CARBON				0x151515
# define WHITE				0xBBBBBB
# define DISCO				0x9A1F6A
# define BRICK_RED			0xC2294E
# define FLAMINGO			0xEC4B27
# define ORANGE				0xEF8633
# define SAFFRON			0xF3AF3D
# define GREY				0xEAEAEA

/* 
		====== STRUCTS ======
*/

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
	double	increment_pos[3];
	double	increment_neg[3];
}	t_colours;

typedef struct s_point
{
	int		coord[3];
	int		colour;
	bool	paint;
}	t_point;

typedef struct s_map
{
	t_point		*point;
	t_point		limits;
	t_point		origin;
	t_colours	colours;
	char		*buf;
	char		**lines;
	int			z_min;
	int			point_count;
	double		angle[3];
	double		perf;
	int			render_count;
	double		scale;

}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}	t_data;

#endif
