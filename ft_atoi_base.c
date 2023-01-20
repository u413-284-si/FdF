/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 23:03:48 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/14 21:01:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	input_check(char *base, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (length < 2)
		return (1);
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (base[i] == base[j])
				return (1);
			else if (base[i] == '+' || base[i] == '-')
				return (1);
			else if (base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
/* 
String starts with whitespace, then signs come, afterwards the number in
a specific base.
*/

static int	skip(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

static int	convert(char *str, int *factor, char *base)
{
	int	j;

	j = 0;
	while (base[j])
	{
		if (base[j] == *str)
		{
			*factor = j;
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	length;
	int	result;
	int	sign;
	int	i;
	int	factor;

	result = 0;
	length = str_len(base);
	if (input_check(base, length))
		return (0);
	i = skip(str, &sign);
	while (str[i] && convert(&str[i], &factor, base))
	{
		result = result * str_len(base) + factor * sign;
		i++;
	}
	return (result);
}

//int	main(void)
//{
//	char	str[] = "    +++-----2b6%147483648t889+0";
// 	printf("%d\n", ft_atoi_base(str, "0123456789abcdef"));
//	return (0);
//}
