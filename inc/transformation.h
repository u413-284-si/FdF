/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:26 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/01 12:32:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

/* 
====== FUNCTIONS ======
 */

t_point	mat_mult(t_mat matrix, t_point prjct);
void	rotate_x(t_data *data, float_t angle);
void	rotate_y(t_data *data, float_t angle);
void	rotate_z(t_data *data, float_t angle);
void	orthographic_prjct(t_data *data);

#endif