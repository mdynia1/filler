/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:14:44 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/28 21:14:46 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	score_put(t_visual *a)
{
	char *score;
	char *tmp;

	score = ft_strjoin(": ", ft_itoa(a->score1));
	tmp = score;
	score = ft_strjoin(a->sign_1, score);
	mlx_string_put(a->mlx_ptr, a->win_ptr, a->map_x * a->pix + 60,
		a->map_y * a->pix + 100, a->p1_color, score);
	free(score);
	free(tmp);
	score = ft_strjoin(": ", ft_itoa(a->score2));
	tmp = score;
	score = ft_strjoin(a->sign_2, score);
	mlx_string_put(a->mlx_ptr, a->win_ptr, a->map_x * a->pix + 60,
		a->map_y * a->pix + 130, a->p2_color, score);
	free(score);
	free(tmp);
}

void	print_pixels(t_visual *v, size_t y, size_t x)
{
	int tmp_x;
	int tmp_y;

	tmp_y = 0;
	while (tmp_y < v->pix)
	{
		tmp_x = 0;
		while (tmp_x < v->pix)
		{
			if (tmp_y == v->pix - 1 || tmp_x == v->pix - 1)
				mlx_pixel_put(v->mlx_ptr, v->win_ptr, tmp_x + (x * v->pix) + 50,
					tmp_y + (y * v->pix) + 50, 0x000000);
			else
				mlx_pixel_put(v->mlx_ptr, v->win_ptr, tmp_x + (x * v->pix) + 50,
					tmp_y + (y * v->pix) + 50, color(v, y, x));
			tmp_x++;
		}
		tmp_y++;
	}
}

void	map_visualizer(t_visual *v)
{
	int	y;
	int	x;

	y = 0;
	while (y < v->map_y)
	{
		x = 0;
		while (x < v->map_x)
		{
			print_pixels(v, y, x);
			x++;
		}
		y++;
	}
}

void	map_reader(t_visual *a, char *line)
{
	int	i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if_to_type(a, line);
		if (ft_strstr(line, "<got (O):"))
			a->score1++;
		if (ft_strstr(line, "<got (X):"))
			a->score2++;
		if (ft_strstr(line, "   0"))
		{
			plateau_read(a, line);
			score_put(a);
			map_visualizer(a);
			if_to_pause(a);
			mlx_do_sync(a->mlx_ptr);
		}
		if (ft_strstr(line, "== X"))
			game_over_func(a);
	}
}

void	plateau_read(t_visual *a, char *line)
{
	int	i;

	i = 0;
	mlx_clear_window(a->mlx_ptr, a->win_ptr);
	a->map = (char **)ft_memalloc(sizeof(char *) * a->map_y + 1);
	while (i < a->map_y && (get_next_line(0, &line) > 0))
	{
		a->map[i++] = ft_strdup(line + 4);
		if_to_type(a, line);
	}
	a->map[i] = NULL;
}
