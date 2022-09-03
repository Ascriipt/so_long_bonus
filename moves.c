/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:30:14 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 13:28:43 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	find_player(int *px, int *py, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				*px = j;
				*py = i;
			}
		}
	}
}

void	move_up(int *px, int *py, char **map, t_gdata *sl)
{
	if (map[*py - 1][*px] == '1'
		|| map[*py - 1][*px] == 'E')
	{
		if (map[*py - 1][*px] == 'E' && sl->map.t_col
			== sl->map.c_col)
			close_game(sl);
		return ;
	}
	if (map[*py - 1][*px] == 'C')
	{
		map[*py - 1][*px] = '0';
		sl->map.c_col++;
	}
	mp_swop(&(map[*py - 1][*px]), &(map[*py][*px]));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.floor, (*px * 64), (*py * 64));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.player_r, (*px * 64), ((*py - 1) * 64));
	*py -= 1;
}

void	move_down(int *px, int *py, char **map, t_gdata *sl)
{
	if (map[*py + 1][*px] == '1'
		|| map[*py + 1][*px] == 'E')
	{
		if (map[*py + 1][*px] == 'E' && sl->map.t_col
			== sl->map.c_col)
			close_game(sl);
		return ;
	}
	if (map[*py + 1][*px] == 'C')
	{
		map[*py + 1][*px] = '0';
		sl->map.c_col++;
	}
	mp_swop(&(map[*py + 1][*px]), &(map[*py][*px]));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.floor, (*px * 64), (*py * 64));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.player_r, (*px * 64), ((*py + 1) * 64));
	*py += 1;
}

void	move_left(int *px, int *py, char **map, t_gdata *sl)
{
	if (map[*py][*px - 1] == '1'
		|| map[*py][*px - 1] == 'E')
	{
		if (map[*py][*px - 1] == 'E' && sl->map.t_col
			== sl->map.c_col)
			close_game(sl);
		return ;
	}
	if (map[*py][*px - 1] == 'C')
	{
		map[*py][*px - 1] = '0';
		sl->map.c_col++;
	}
	mp_swop(&(map[*py][*px - 1]), &(map[*py][*px]));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.floor, (*px * 64), (*py * 64));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.player_l, ((*px - 1) * 64), (*py * 64));
	*px -= 1;
}

void	move_right(int *px, int *py, char **map, t_gdata *sl)
{
	if (map[*py][*px + 1] == '1'
		|| map[*py][*px + 1] == 'E')
	{
		if (map[*py][*px + 1] == 'E' && sl->map.t_col
			== sl->map.c_col)
			close_game(sl);
		return ;
	}
	if (map[*py][*px + 1] == 'C')
	{
		map[*py][*px + 1] = '0';
		sl->map.c_col++;
	}
	mp_swop(&(map[*py][*px + 1]), &(map[*py][*px]));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.floor, (*px * 64), (*py * 64));
	mlx_put_image_to_window(sl->win.mlx, sl->win.window,
		sl->game_t.player_r, ((*px + 1) * 64), (*py * 64));
	*px += 1;
}
