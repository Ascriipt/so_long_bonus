/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:34:52 by maparigi          #+#    #+#             */
/*   Updated: 2022/07/13 14:39:13 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	event_manager(int keycode, t_gdata *sl)
{
	if (keycode == 119 || keycode == 115
		|| keycode == 100 || keycode == 97)
	{
		sl->mv++;
		ft_putstr_fd("Moves : ", STDERR_FILENO);
		ft_putnbr_fd(sl->mv, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	if (keycode == 65307)
		close_game(sl);
	if (keycode == 119)
		move_up(&(sl->map.px), &(sl->map.py),
			sl->map.map, sl);
	else if (keycode == 115)
		move_down(&(sl->map.px), &(sl->map.py),
			sl->map.map, sl);
	else if (keycode == 100)
		move_right(&(sl->map.px), &(sl->map.py),
			sl->map.map, sl);
	else if (keycode == 97)
		move_left(&(sl->map.px), &(sl->map.py),
			sl->map.map, sl);
	return (0);
}

int	red_cross(void *sl)
{
	close_game(sl);
	return (0);
}

void	my_init(t_gdata *sl)
{
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		pexit_failfree("mlx pointer init error\n", sl->map.map);
	sl->win.window = mlx_new_window(sl->win.mlx, ((sl->map.x) * 64),
			((sl->map.y) * 64), "so_long");
	init_texture(sl);
	gen_map(sl->map, &(sl->win), sl->game_t);
	find_player(&(sl->map.px), &(sl->map.py), sl->map.map);
	count_collectibles(&(sl->map.t_col), sl->map.map);
	mlx_hook(sl->win.window, 17, 0L << 2, red_cross, sl);
	mlx_key_hook(sl->win.window, event_manager, sl);
	mlx_loop(sl->win.mlx);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
}

int	main(int ac, char **av)
{
	t_gdata	so_long;

	if (ac != 2)
		return (1);
	so_long.mv = 0;
	so_long.map.c_col = 0;
	is_ber(av[1]);
	so_long.map.map = parse_map(av[1]);
	map_main(&(so_long.map));
	my_init(&so_long);
	return (0);
}
