/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:50:46 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/01 14:12:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

// FUNCTIONS
void	read_file(t_map *map, int fd);
void	extract_points(t_map *map, char *line, int line_pos);
void	extract_lines(t_map *map);
int		colour_given(char *s);
int		upper_case(char *s);
int		ft_atoi_base(char *str, char *base);

#endif