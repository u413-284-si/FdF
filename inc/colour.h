/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:45 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/03 09:50:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

/* 
		====== FUNCTIONS ======
*/

void	colour(t_map *map);
void	increment(t_map *map);
int		gradient(float_t *increment, int start_colour, float_t pos);
int		gradient_interpoints(t_point start, t_point end, float_t pos);
int		colour_given(char *s);
int		ft_atoi_base(char *str, char *base);
//void	set_colour(char *address, int endian, int colour, int alpha);

#endif