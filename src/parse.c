/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:50:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/03 09:55:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/parse.h"
#include "../inc/error.h"
#include "../inc/utils.h"
#include "../inc/colour.h"

/* This functions retrieves the data in the given file descriptor and saves
it in a map->buf. */

void	read_file(t_map *map, int fd)
{
	char	*buffer;
	char	*tmp;

	tmp = ft_strdup("");
	buffer = ft_strdup("");
	while (buffer != NULL)
	{
		free(buffer);
		buffer = get_next_line(fd);
		if (buffer)
		{
			map->buf = ft_strjoin(tmp, buffer);
			free(tmp);
			tmp = map->buf;
		}
	}
}

/* This function mallocs enough space in memory to save all point
specified in the data, extracts the individual lines read from the 
file and forwards them to the function 'extract_points'. */

void	extract_lines(t_map *map)
{
	static int	i = -1;
	static int	line_count = -1;
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
			line_count++;
			extract_points(map, line, line_count);
		}
	}
	free(line);
}

/* This function extracts the data given in 'line' into an array of strings - 
every string representing one point - and extrapulates the respective
coordinates and height value (z-value). Coordinates are distributed around
the origin (0,0) of the window (upper left corner) with a space of 10 pixels
between them horizontally as well as vertically.
If colour info is given in the string, this value is assigned for the point,
else it is assigned the default value. */

void	extract_points(t_map *map, char *line, int line_pos)
{
	char		**arr;
	int			i;
	static int	point_index = -1;

	arr = ft_split(line, ' ');
	i = -1;
	while (arr[++i] && arr[i][0] != '\n')
	{
		if (!point_check(arr[i]))
			terminate(ERR_DATA_FORMAT);
		map->point[++point_index].x = (i - \
			(int)(map->limits.x / 2)) * map->space;
		map->point[point_index].y = (line_pos - \
			(int)(map->limits.y / 2)) * map->space;
		map->point[point_index].z = ft_atoi(arr[i]);
		check_hex(&map->point[point_index], arr[i]);
		set_z_minmax(map, point_index);
	}
	free_arr(arr);
}

/* This function checks whether hexadecimal colours are given in the
input data and assigns them to the respective points if given.
Otherwise a default value is assigned. */

void	check_hex(t_point *point, char *str)
{
	int	colour;

	colour = 0;
	colour = colour_given(str);
	if (colour != 0)
	{
		point->colour = colour;
		point->hex_given = 1;
	}
	else
		point->colour = DEFAULT_COLOUR;
}

/* This function identifies the maximum and minimum z-value of the 
map.*/

void	set_z_minmax(t_map *map, int point_index)
{
	if (map->limits.z < map->point[point_index].z)
		map->limits.z = map->point[point_index].z;
	if (map->z_min > map->point[point_index].z)
		map->z_min = map->point[point_index].z;
}
