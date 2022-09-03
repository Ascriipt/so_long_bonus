/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:17:03 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 14:16:40 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	my_open(char *filename)
{
	int	fd;

	errno = 0;
	fd = open(filename, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		pexit_failure("map is a directory.");
	}
	errno = 0;
	fd = open(filename, O_RDONLY | __O_NOFOLLOW);
	if (fd < 0 || errno != 0)
	{
		if (errno == 40)
			pexit_failure("map is a symlink");
		pexit_failure("failed to open file.");
	}
	return (fd);
}

static int	count_backlines(char *str)
{
	int	x;
	int	i;

	x = -1;
	i = 0;
	while (str[++x])
		if (str[x] == '\n')
			i++;
	return (i);
}

static int	map_lines(char *filename)
{
	int		i;
	int		fd;
	int		res;
	char	*buffer;

	i = 0;
	fd = my_open(filename);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 2);
	if (!buffer)
		return (0);
	res = 1;
	while (res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res < 0)
			pexit_failure("read encountered a problem.");
		buffer[BUFFER_SIZE + 1] = '\0';
		i += count_backlines(buffer);
	}
	free(buffer);
	close(fd);
	return (i);
}

char	**parse_map(char *av)
{
	int		i;
	int		ml;
	int		fd;
	char	**map;

	i = 0;
	fd = 0;
	ml = map_lines(av);
	fd = my_open(av);
	map = ft_calloc(sizeof(char **), ml + 1);
	if (!map)
		return (NULL);
	if (ml > 0)
	{
		map[i] = get_next_line(fd);
		while (map[i] && i < ml)
			map[++i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}
