/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:49:55 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/10 12:17:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

/* 
====== DEFINITIONS ======
 */

typedef struct s_bham
{
	int	x;
	int	y;
	int	i;
	int	dx;
	int	dy;
	int	incx;
	int	incy;
	int	pdx;
	int	pdy;
	int	ddx;
	int	ddy;
	int	delta_slow_direction;
	int	delta_fast_direction;
	int	err;
}	t_bham;

/* 
====== FUNCTIONS ======
*/

int		sgn(int x);
void	bham(t_point start, t_point end, t_img *img);
void	assign_roles(t_point start, t_point end, t_bham algo);
void	radetzky(t_point start, t_point end, t_bham algo, t_img *img);
void	set_pixel(t_bham algo, t_img *img, t_point start, t_point end);

#endif
