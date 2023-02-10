/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:45 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/10 12:03:17 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

/* 
		====== FUNCTIONS ======
*/

void	colour(t_map *map);
void	increment(t_map *map);
int		gradient(double *increment, int start_colour, int pos);
int		gradient_interpoints(t_point start, t_point end, int pos);

#endif