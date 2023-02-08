/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:11 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/08 19:20:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/* This function frees an array which has been malloced with
subarrays which themselves have been malloced. */

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/* This function checks whether the given string contains upper
case characters. Upon success 1 is returned, else 0. */

int	upper_case(char *s)
{
	while (*s)
	{
		if (*s >= 65 || *s <= 90)
			return (1);
		s++;
	}
	return (0);
}
