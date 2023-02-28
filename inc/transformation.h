/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:26 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 18:39:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

/* 
====== FUNCTIONS ======
 */

t_point	mat_mult(float_t matrix[3][3], t_point prjct);
void	rotate_x(t_map *map, float_t angle, int point_count);
void	rotate_y(t_map *map, float_t angle, int point_count);
void	rotate_z(t_map *map, float_t angle, int point_count);
void	orthographic_prjct(t_map *map, int point_count);

#endif