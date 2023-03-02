/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:53:31 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/02 14:13:17 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// LIBRARIES
# include <errno.h>

// DEFINITIONS
# define ERR_ARGC "Incorrect number of arguments passed to program; \
    expected 1.\n"
# define ERR_OPEN "Error occured upon opening the file.\n"
# define ERR_MEM  "Memory allocation failed.\n"
# define ERR_READ "Read error occured while reading the file.\n"
# define ERR_MAP_UNIFORMITY "Line length in file not uniform.\n"
# define ERR_DATA_FORMAT "Point data not correctly formatted.\n"
# define ERR_MLX "Minilib failed.\n"

// FUNCTIONS
void	terminate(char *s);
int		point_check(char *s);

#endif