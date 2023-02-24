/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:01:37 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/24 15:13:12 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIATE_H
# define INITIATE_H

// DEFINTIONS
# define READ_SIZE 10000

// FUNCTIONS
void	system_boot(t_map *map, char *file);
void	initiate(t_map *map);
void	map_dim(t_map *map);
void	scale(t_map *map);
void	copy(t_map *map);

#endif