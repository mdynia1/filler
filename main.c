/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:10:38 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/17 15:38:37 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_initializer(t_filler *data)
{
	data->map_size_x = 0;
	data->map_size_y = 0;
	data->piece_size_x = 0;
	data->piece_size_y = 0;
	data->distance = 0;
	data->result = -1;
	data->fit_y = 0;
	data->fit_x = 0;
	data->game_over = 1;
	data->map = NULL;
	data->piece = NULL;
}

void			ft_memdel_ar(char **array)
{
	int			x;

	x = 0;
	while (array[x])
		ft_memdel((void*)&array[x++]);
}

void			clean_memory(t_filler *data)
{
	ft_memdel_ar(data->piece);
	ft_memdel_ar(data->map);
}

int				main(void)
{
	int			fd;
	char		*line;
	t_filler	*a;

	fd = 0;
	a = (t_filler *)ft_memalloc(sizeof(t_filler));
	ft_initializer(a);
	ft_player(a, &line, fd);
	while (a->game_over)
	{
		ft_plateau_read(a, &line, fd);
		ft_piece_read(a, &line, fd);
		first_sorter(a);
		ft_putnbr(a->fit_y);
		ft_putchar(' ');
		ft_putnbr(a->fit_x);
		ft_putchar('\n');
		clean_memory(a);
		ft_initializer(a);
	}
	free(a);
	return (0);
}
