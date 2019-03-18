/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_gather.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:30:09 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/17 16:03:19 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_player(t_filler *data, char **line, int fd)
{
	while (!data->my_sign && get_next_line(fd, line))
	{
		if (ft_strstr(*line, "p1"))
			data->my_sign = 'O';
		if (ft_strstr(*line, "p2"))
			data->my_sign = 'X';
	}
	data->enemy_sign = (data->my_sign == 'O') ? 'X' : 'O';
}

void	ft_plateau_read(t_filler *a, char **line, int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd, line) > 0)
	{
		if (ft_strstr(*line, "Plateau"))
		{
			a->map_size_y = ft_atoi((*line) + 8);
			a->map_size_x = ft_atoi((*line) + 8 + ft_part_itoa(a->map_size_y));
			a->map = (char **)ft_memalloc(sizeof(char *) * (a->map_size_y) + 1);
			get_next_line(fd, line);
			while (i < a->map_size_y && (get_next_line(fd, line) > 0))
				a->map[i++] = ft_strdup(*line + 4);
			a->map[i] = NULL;
			break ;
		}
	}
}

void	ft_piece_read(t_filler *a, char **line, int fd)
{
	int	k;

	k = 0;
	while (get_next_line(fd, line) > 0)
	{
		if (ft_strstr(*line, "Piece"))
		{
			a->piece_size_y = ft_atoi((*line) + 6);
			a->piece_size_x = ft_atoi((*line) + 6
									+ ft_part_itoa(a->piece_size_y));
			a->piece = (char **)ft_memalloc(sizeof(char *) *
										a->piece_size_y + 1);
			while (k < a->piece_size_y && get_next_line(fd, line) > 0)
				a->piece[k++] = ft_strdup(*line);
			a->piece[k] = NULL;
			break ;
		}
	}
}
