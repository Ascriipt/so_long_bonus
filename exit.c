/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:32:12 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/12 13:53:05 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_lib.h>

void	pexit_failfree(char *str, char **map)
{
	if (map)
		free_tab(map);
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	pexit_failure(str);
}

void	pexit_failure(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}
