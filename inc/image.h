/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:48:21 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/09 17:28:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

/* 
====== FUNCTIONS ======
*/

void	img_pix_put(t_img *img, int x, int y, int colour);
void	render_background(t_img *img, int background_col, int menu_col);
void	render_map(t_map *map, t_img *img, t_point *prjct);
void	line_draw(t_point *prjct, t_img *img, t_map *map);

#endif