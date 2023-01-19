/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:50:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/01/19 17:54:00 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse.h"
#include "error.h"

/* This functions retrieves the data in the given file descriptor and saves
it in a map->buf. */

void	read_file(t_map *map, int fd)
{
	char	*buffer;

	map->buf = ft_strdup("");
	buffer = ft_strdup("");
	while (buffer != NULL)
	{
		free(buffer);
		buffer = get_next_line(fd);
		if (buffer)
			map->buf = ft_strjoin(map->buf, buffer);
	}
}

/* This function mallocs enough space in memory to save all points
specified in the data, extracts the individual lines read from the 
file and forwards them to the function 'extract_points'. */

void	extract_lines(t_map *map)
{
	static int	i = -1;
	char		*line;
	char		*start;

	line = NULL;
	start = map->buf;
	map->point = ft_calloc (map->point_count, sizeof(t_point));
	while (map->buf[++i])
	{
		if (map->buf[i] == '\n')
		{
			free(line);
			line = ft_substr(start, 0, &map->buf[i] - start);
			start = &map->buf[i + 1];
			extract_points(map, line);
		}
	}
	free(line);
	line = ft_substr(start, 0, &map->buf[i] - start);
	extract_points(map, line);
	free(line);
}

void	extract_points(t_map *map, char *line)
{
	char		**arr;
	static int	i = -1;
	static int	point_index;

	arr = ft_split(line, ' ');
	while (arr[++i] && arr[i][0] != '\n')
	{
		if (point_check(arr[i]))
			terminate(ERR_DATA_FORMAT);
	}
}

int	point_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	
}
