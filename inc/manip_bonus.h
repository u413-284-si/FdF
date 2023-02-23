/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:24:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/23 17:25:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_BONUS_H
# define MANIP_BONUS_H

/* ====== FUNCTIONS ====== */

void	zoom(t_map *map, double factor);
void	shift(t_map *map, t_point offset);
void	reset(t_data *data);
void	scale_z(t_map *map, t_point increment);

#endif