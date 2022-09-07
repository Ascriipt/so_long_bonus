/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:59:54 by maparigi          #+#    #+#             */
/*   Updated: 2022/09/07 22:11:42 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	rev_dfs(char **map, int i, int j)
{
	if (map[i][j] != 'v' && map[i][j] != 'C')
		return ;
	else
	{
		if (map[i][j] == 'v')
			map[i][j] = '0';
		rev_dfs(map, i + 1, j);
		rev_dfs(map, i - 1, j);
		rev_dfs(map, i, j + 1);
		rev_dfs(map, i, j - 1);
	}
	return ;
}

void	dfs(char **map, int i, int j)
{
	if (map[i][j] != '0' && map[i][j] != 'C')
		return ;
	else
	{
		if (map[i][j] == '0')
			map[i][j] = 'v';
		dfs(map, i + 1, j);
		dfs(map, i - 1, j);
		dfs(map, i, j + 1);
		dfs(map, i, j - 1);
	}
	return ;
}

int	check_collectibles(char	**map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			{
				if ((map[i + 1][j] == '0' || map[i + 1][j] == '1')
					&& (map[i - 1][j] == '0' || map[i - 1][j] == '1')
					&& (map[i][j + 1] == '0' || map[i][j + 1] == '1')
					&& (map[i][j - 1] == '0' || map[i][j - 1] == '1'))
					return (-1);
			}
		}
	}
	return (0);
}

int	is_path(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i + 1][j] == 'v' || map[i - 1][j] == 'v'
					|| map[i][j + 1] == 'v' || map[i][j - 1] == 'v')
					return (0);
				if (map[i + 1][j] == 'C' || map[i - 1][j] == 'C'
					|| map[i][j + 1] == 'C' || map[i][j - 1] == 'C')
					return (0);
			}
		}
	}
	return (-1);
}

void	flood_fill(char **map)
{	
	int	i;
	int	j;

	find_player(&j, &i, map, 'P');
	map[i][j] = '0';
	dfs(map, i, j);
	if (is_path(map) == -1 || check_collectibles(map) == -1)
		pexit_failfree("no valid path", map);
	rev_dfs(map, i, j);
	map[i][j] = 'P';
}
