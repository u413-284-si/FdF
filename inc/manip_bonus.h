/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 18:07:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_BONUS_H
# define MANIP_BONUS_H

/* ====== FUNCTIONS ====== */

void	shift(t_map *map, t_point offset);
void	reset(t_data *data);
void	scale_z(t_data *data, t_point increment);
void	top(t_data *data);

#endif