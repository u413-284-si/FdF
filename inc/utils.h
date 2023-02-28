/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:06 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 16:39:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// FUNCTIONS

void	free_arr(char **arr);
int		upper_case(char *s);
int		roundme(float_t n);
void	put_str(t_data *data, int x, int y, char *str);
void	put_nbr(t_data *data, int x, int y, int n);

#endif