/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:57:18 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/24 13:59:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINES_H
# define LINES_H

/* ====== FUNCTIONS ====== */

int	draw_line(t_img *img, t_point start, t_point end);
int	draw_line_high(t_img *img, t_point start, t_point end);
int	draw_line_low(t_img *img, t_point start, t_point end);
int	get_color(t_point cur, t_point start, t_point end, t_point delta);
int	calc_color_channel(int start, int end, float_t percentage);
float_t	get_percentage(int start, int end, int cur);

#endif