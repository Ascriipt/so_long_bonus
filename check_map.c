/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:38:45 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 02:34:59 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_lib.h>

static void	is_rectangle(t_coord *map)
{
	int	i;
	int	j;

	map->x = ft_strlen(map->map[0]);
	map->y = 0;
	i = -1;
	while (map->map[++i])
	{
		map->y++;
		j = ft_strlen(map->map[i]);
		if (!map->map[i + 1])
			map->x -= 1;
		if (j != map->x)
			pexit_failfree("not a rectangle\n", map->map);
	}
	if (map->y == map->x)
		pexit_failfree("not a rectangle\n", map->map);
}

static void	pec(char **map)
{
	int	pec[3];
	int	i;
	int	j;

	i = -1;
	pec[0] = 0;
	pec[1] = 0;
	pec[2] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				pec[0]++;
			if (map[i][j] == 'E')
				pec[1]++;
			if (map[i][j] == 'C')
				pec[2]++;
		}
	}
	if (pec[0] != 1 || pec[1] < 1 || pec[2] < 1)
		pexit_failfree("Too few/many Player(s), Exit(s), or Collectible(s)\n",
			map);
}

static void	pec_digit(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\n')
				break ;
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
				pexit_failfree("the map should only contain 1, 0, P, E, C.\n",
					map);
		}
	}
	pec(map);
}

static void	walls(t_coord *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!map->map)
		return ;
	while (map->map[++i])
		if (map->map[i][0] != '1' || map->map[i][map->x - 1] != '1')
			pexit_failfree("walls not properly mapped.\n", map->map);
	while (map->map[0][++j] && j < map->x)
		if (map->map[0][j] != '1')
			pexit_failfree("walls not properly mapped.\n", map->map);
	j = -1;
	while (map->map[map->y - 1][++j] && j < map->x)
		if (map->map[map->y - 1][j] != '1')
			pexit_failfree("walls not properly mapped.\n", map->map);
}

void	map_main(t_coord *map)
{
	pec_digit(map->map);
	is_rectangle(map);
	walls(map);
}
