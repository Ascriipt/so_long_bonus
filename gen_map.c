/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:45:48 by maparigi          #+#    #+#             */
/*   Updated: 2022/09/04 18:25:56 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	free_texturexmap(t_texture *game_t, t_window *win, t_coord *map)
{
	if (map->map)
		free_tab(map->map);
	if (game_t->collectibles)
		mlx_destroy_image(win->mlx, game_t->collectibles);
	if (game_t->player_ml)
		mlx_destroy_image(win->mlx, game_t->player_ml);
	if (game_t->player_mr)
		mlx_destroy_image(win->mlx, game_t->player_mr);
	if (game_t->player_l)
		mlx_destroy_image(win->mlx, game_t->player_l);
	if (game_t->player_r)
		mlx_destroy_image(win->mlx, game_t->player_r);
	if (game_t->walls)
		mlx_destroy_image(win->mlx, game_t->walls);
	if (game_t->floor)
		mlx_destroy_image(win->mlx, game_t->floor);
	if (game_t->exit)
		mlx_destroy_image(win->mlx, game_t->exit);
}

void	init_texture(t_gdata *sl)
{
	int		hw[2];

	sl->game_t.collectibles = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/dolla.xpm", &hw[0], &hw[1]);
	sl->game_t.player_r = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/Sprite_1.1.xpm", &hw[0], &hw[1]);
	sl->game_t.player_l = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/Sprite_1.xpm", &hw[0], &hw[1]);
	sl->game_t.walls = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/Wall.xpm", &hw[0], &hw[1]);
	sl->game_t.floor = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/floor.xpm", &hw[0], &hw[1]);
	sl->game_t.exit = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/exit.xpm", &hw[0], &hw[1]);
	sl->game_t.player_mr = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/MR.xpm", &hw[0], &hw[1]);
	sl->game_t.player_ml = mlx_xpm_file_to_image(sl->win.mlx,
			"so_long_sprites/ML.xpm", &hw[0], &hw[1]);
	if (!sl->game_t.collectibles || !sl->game_t.floor || !sl->game_t.walls
		|| !sl->game_t.player_l || !sl->game_t.player_r || !sl->game_t.exit
		|| !sl->game_t.player_mr || !sl->game_t.player_ml)
		close_game(sl);
}

void	close_game(t_gdata *sl)
{
	free_texturexmap(&(sl->game_t), &(sl->win), &(sl->map));
	mlx_destroy_window(sl->win.mlx, sl->win.window);
	mlx_destroy_display(sl->win.mlx);
	mlx_loop_end(sl->win.mlx);
	free(sl->win.mlx);
	exit(EXIT_SUCCESS);
}

static void	match_to_map(char c, int xy[2], t_window *win, t_texture game_t)
{
	if (c == '1')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.walls, xy[0], xy[1]);
	else if (c == '0')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.floor, xy[0], xy[1]);
	else if (c == 'P')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.player_r, xy[0], xy[1]);
	else if (c == 'E')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.exit, xy[0], xy[1]);
	else if (c == 'C')
		mlx_put_image_to_window(win->mlx, win->window,
			game_t.collectibles, xy[0], xy[1]);
}

void	gen_map(t_coord map, t_window *win, t_texture game_t)
{
	int		i;
	int		j;
	int		xy[2];

	i = -1;
	xy[0] = 0;
	xy[1] = 0;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j] && j < map.x)
		{
			match_to_map(map.map[i][j], xy, win, game_t);
			xy[0] += 64;
		}
		xy[0] = 0;
		xy[1] += 64;
	}
}
