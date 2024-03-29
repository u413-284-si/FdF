/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/01 13:47:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_BONUS_H
# define MANIP_BONUS_H

/* ====== FUNCTIONS ====== */

void	shift(t_map *map, t_point offset);
void	scale_z(t_data *data, float_t increment);

#endif