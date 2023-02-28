/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:53:31 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 17:23:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// LIBRARIES
# include <errno.h>

// DEFINITIONS
# define ERR_ARGC "Incorrect number of arguments passed to program; expected 1."
# define ERR_OPEN "Error occured upon opening the file."
# define ERR_MEM  "Memory allocation failed."
# define ERR_READ "Read error occured while reading the file."
# define ERR_MAP_UNIFORMITY "Line length in file not uniform."
# define ERR_DATA_FORMAT "Point data not correctly formatted."
# define ERR_MLX "Minilib failed."

// FUNCTIONS
void	terminate(char *s);
int		point_check(char *s);

#endif