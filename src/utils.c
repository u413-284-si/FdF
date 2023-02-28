/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:11 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/28 16:39:24 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/utils.h"

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

/* This function rounds the floating point number n to its correct
integer value. */

int	roundme(float_t n)
{
	int	rounded;

	rounded = (int) n;
	if (n - rounded >= 0.5)
		rounded++;
	return (rounded);
}


/* This function puts a string to the window. */

void	put_str(t_data *data, int x, int y, char *str)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, TEXT_COLOUR, str);
}

/* This function puts a number as a string to the window. */
void	put_nbr(t_data *data, int x, int y, int n)
{
	char	*str;

	str = ft_itoa(n);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, TEXT_COLOUR, str);
	free(str);
}

