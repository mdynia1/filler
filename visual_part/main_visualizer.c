/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visualizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:58:42 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/17 19:59:32 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		keys(int keycode, t_visual *v, char *line)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
		exit(1);
	}
	if (keycode == 49)
	{
		v->to_pause = 0;
		map_reader(v, line);
	}
	if (keycode == 36)
		map_reader(v, line);
	return (0);
}

int		main(int argc, char **argv)
{
	t_visual	v;
	char		*line;

	line = NULL;
	ft_initialize(&v);
	if (argc > 1)
		ft_flag_check(argc, argv, &v);
	player_map_determine(&v, line);
	v.pix = v.map_x > 50 || v.map_y > 50 ? 5 : v.pix;
	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, v.map_x * v.pix + 220,
		v.map_y * v.pix + 220, "FILLER by MDYNIA");
	mlx_string_put(v.mlx_ptr, v.win_ptr, 10, 10, v.p1_color,
		"Press Enter to start");
	mlx_key_hook(v.win_ptr, keys, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
