/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:53:31 by sqiu              #+#    #+#             */
/*   Updated: 2023/01/18 14:50:12 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// Libraries
# include <errno.h>

// Definitions
# define ERR_ARGC "Incorrect number of arguments passed to program; expected 1."
# define ERR_OPEN "Error occured upon opening the file."
# define ERR_MEM  "Memory allocation failed."
# define ERR_READ "Read error occured while reading the file."

// Functions
void	terminate(char *s);

#endif