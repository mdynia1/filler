/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:31:48 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/17 15:47:34 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_better(t_filler *data, int x, int y, int r)
{
	int		touch;
	int		tmp_x;
	int		tmp_y;

	touch = 0;
	tmp_y = y - r < 0 ? 0 : y - r;
	while (data->map[tmp_y] != NULL && tmp_y <= y + r)
	{
		tmp_x = x - r < 0 ? 0 : x - r;
		while (data->map[tmp_y][tmp_x] != '\0' && tmp_x <= x + r)
		{
			if (data->map[tmp_y][tmp_x] == data->enemy_sign)
				touch += 1;
			tmp_x++;
		}
		tmp_y++;
	}
	if (!touch)
		ft_better(data, x, y, r + 1);
	else
		data->distance += r;
}

void		best_option(t_filler *data, int x, int y)
{
	int		piece_y;
	int		piece_x;

	piece_y = 0;
	while (piece_y < data->piece_size_y)
	{
		piece_x = 0;
		while (piece_x < data->piece_size_x)
		{
			if (data->piece[piece_y][piece_x] == '*')
				ft_better(data, x + piece_x, y + piece_y, 1);
			piece_x++;
		}
		piece_y++;
	}
	data->result = data->result == -1 ? data->distance + 1 : data->result;
	if (data->distance < data->result)
	{
		data->result = data->distance;
		data->fit_x = x;
		data->fit_y = y;
	}
}

int			second_sorter(t_filler *data, int x, int y, int *touch)
{
	int		piece_x;
	int		piece_y;
	int		zero;

	zero = 0;
	piece_y = 0;
	while (piece_y < data->piece_size_y)
	{
		piece_x = 0;
		while (piece_x < data->piece_size_x)
		{
			if (data->map[y + piece_y][x + piece_x] == data->my_sign)
			{
				if (data->piece[piece_y][piece_x] == '*')
					*touch = *touch == 0 ? 1 : 2;
			}
			else if (data->map[y + piece_y][x + piece_x] == data->enemy_sign)
				if (data->piece[piece_y][piece_x] == '*')
					zero = 1;
			piece_x++;
		}
		piece_y++;
	}
	return (zero);
}

void		first_sorter(t_filler *data)
{
	int		x;
	int		y;
	int		touch;
	int		zero;

	y = 0;
	while (y <= data->map_size_y - data->piece_size_y)
	{
		x = 0;
		while (x <= data->map_size_x - data->piece_size_x)
		{
			touch = 0;
			zero = second_sorter(data, x, y, &touch);
			if (zero == 0 && touch == 1)
			{
				data->distance = 0;
				best_option(data, x, y);
			}
			x++;
		}
		y++;
	}
	if (data->distance == 0)
		data->game_over = 0;
}
