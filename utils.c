/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:50:38 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 14:43:20 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	is_ber(char *filename)
{
	int	i;
	int	ln;

	i = 0;
	ln = ft_strlen(filename);
	if (ln < 4)
		pexit_failure("file is not a .ber");
	while (filename[i] && i < ln - 4)
		i++;
	if (strncmp(filename + i, ".ber", 4))
		pexit_failure("file is not a .ber");
}

int	ft_sizeof(int n, int ln)
{
	if (n == -2147483648)
		n = -2147483647;
	if (n < 0)
	{
		n = -n;
		return (1 + ft_sizeof(n, ln));
	}
	if (n < ln)
		return (1);
	return (1 + ft_sizeof(n / ln, ln));
}

void	mp_swop(char *x, char *y)
{
	char	swop;

	swop = *x;
	*x = *y;
	*y = swop; 
}

void	count_collectibles(int *t_col, char **map)
{
	int	i;
	int	j;

	i = -1;
	*t_col = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				*t_col += 1;
		}
	}
}