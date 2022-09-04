/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:32:58 by maparigi          #+#    #+#             */
/*   Updated: 2022/09/04 18:39:08 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	print_moves(t_gdata *sl)
{
	char	*nbm;
	gen_map(sl->map, &(sl->win), sl->game_t);
	sl->mv++;
	nbm = ft_itoa(sl->mv);
	mlx_string_put(sl->win.mlx, sl->win.window,
		(sl->map.x * 64) / sl->map.x,
		(sl->map.y * 64) / sl->map.y, 0x000000FF, nbm);
	free(nbm);
}
