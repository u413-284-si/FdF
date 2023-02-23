/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:26 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/23 10:44:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

/* 
====== FUNCTIONS ======
 */

void	mat_mult(float matrix[3][3], t_point *prjct);
void	rotate_x(t_point *prjct, double angle, int point_count);
void	rotate_y(t_point *prjct, double angle, int point_count);
void	rotate_z(t_point *prjct, double angle, int point_count);
void	orthographic_prjct(t_point *prjct, int point_count);

#endif