/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_dealer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:11:48 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/28 21:11:52 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	game_over_func(t_visual *a)
{
	char	*winner;

	mlx_clear_window(a->mlx_ptr, a->win_ptr);
	if (a->score1 > a->score2)
		winner = ft_strjoin(a->sign_1, " wins!");
	else
	{
		winner = ft_strjoin(a->sign_2, " wins!");
		a->p1_color = a->p2_color;
	}
	mlx_string_put(a->mlx_ptr, a->win_ptr, a->map_x * a->pix + 60,
		a->map_y * a->pix + 100, a->p1_color, "Game Over!");
	mlx_string_put(a->mlx_ptr, a->win_ptr, a->map_x * a->pix + 60,
		a->map_y * a->pix + 130, a->p1_color, winner);
	ft_strdel(&winner);
	mlx_key_hook(a->win_ptr, keys, a);
	mlx_loop(a->mlx_ptr);
}

void	if_to_type(t_visual *v, char *line)
{
	if (v->to_type == 1)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
}

void	if_to_pause(t_visual *v)
{
	if (v->to_pause == 1)
	{
		mlx_key_hook(v->win_ptr, keys, v);
		mlx_loop(v->mlx_ptr);
	}
}

void	ft_flag_check(int argc, char **argv, t_visual *v)
{
	while (argc-- > 1)
	{
		if (ft_strstr(argv[argc], "-t"))
			v->to_type = 1;
		else if (ft_strstr(argv[argc], "-p"))
			v->to_pause = 1;
		else if (ft_strstr(argv[argc], "-c"))
			color_main(argv, v, argc);
		else if (ft_strstr(argv[argc], "-s"))
		{
			if (argv[argc + 1])
				v->pix = ft_atoi(argv[argc + 1]);
			v->pix = (v->pix > 35) || (v->pix < 3) ? 10 : v->pix;
		}
	}
}
