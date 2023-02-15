/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:36:02 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/15 17:17:09 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_H
# define MANIP_H

/*
====== FUNCTIONS ======
*/

t_point	vec_add(t_point vec1, t_point vec2);
t_point	vec_scalarmult(t_point vec, int scalar);

#endif