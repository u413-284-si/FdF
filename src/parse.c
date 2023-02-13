/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:50:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/02/13 15:55:27 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/parse.h"
#include "../inc/error.h"
#include "../inc/utils.h"

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
	int			colour;

	arr = ft_split(line, ' ');
	i = -1;
	while (arr[++i] && arr[i][0] != '\n')
	{
		if (!point_check(arr[i]))
			terminate(ERR_DATA_FORMAT);
		map->point[++point_index].coord[X] = (i - \
			(map->limits.coord[X] / 2)) * map->space;
		map->point[point_index].coord[Y] = (line_pos - \
			(map->limits.coord[Y] / 2)) * map->space;
		map->point[point_index].coord[Z] = ft_atoi(arr[i]);
		colour = colour_given(arr[i]);
		if (colour)
			map->point[point_index].colour = colour;
		else
			map->point[point_index].colour = DEFAULT_COLOUR;
		set_z_minmax(map, point_index);
	}
	free_arr(arr);
}

/* This function verifies whether information on the colour is given in
the string. In this instance it follows a specific format
of colour data being separated by the z-value by a ',' with a
leading 0x and representation in hexadecimal form. If given, the
colour is returned as an int, else 0 is returned. */

int	colour_given(char *s)
{
	int	colour;

	if (ft_strchr(s, ','))
	{
		while (*s != ',')
			s++;
		s += 3;
		if (upper_case(s))
			colour = ft_atoi_base(s, "0123456789ABCDEF");
		else
			colour = ft_atoi_base(s, "0123456789abcdef");
		return (colour);
	}
	else
		return (0);
}

/* This function identifies the maximum and minimum z-value of the 
map.*/

void	set_z_minmax(t_map *map, int point_index)
{
	if (map->limits.coord[Z] < map->point[point_index].coord[Z])
		map->limits.coord[Z] = map->point[point_index].coord[Z];
	if (map->z_min > map->point[point_index].coord[Z])
		map->z_min = map->point[point_index].coord[Z];
}
