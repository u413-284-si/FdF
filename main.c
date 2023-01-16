/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:26:52 by sqiu              #+#    #+#             */
/*   Updated: 2023/01/11 15:38:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"

#define READ_SIZE 10

int	main(int argc, char **argv)
{
	char	*buf;
	int		fd;
	int		sz;
	int		len;

	if (argc != 2)
		terminate(ERR_ARGC);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		terminate(ERR_OPEN);
	len = 0;
	while (sz > 0)
	{
		sz = read(fd, 0, READ_SIZE);
		if (sz < 0)
			exit(0);
		len += sz;
	}
	buf = malloc (sizeof(char) * len + 1);
	if (!buf)
		terminate(ERR_MEM);
	while 
	return (0);
}
