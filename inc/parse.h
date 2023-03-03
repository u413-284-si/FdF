/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:50:46 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/03 09:50:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

// FUNCTIONS
void	read_file(t_map *map, int fd);
void	extract_points(t_map *map, char *line, int line_pos);
void	extract_lines(t_map *map);
void	set_z_minmax(t_map *map, int point_index);
void	check_hex(t_point *point, char *str);

#endif