/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:53:21 by sqiu              #+#    #+#             */
/*   Updated: 2023/01/20 13:57:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "fdf.h"

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	point_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isalnum(s[i]) || s[i] == ',')
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}
