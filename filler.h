/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:22:55 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/17 16:10:24 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_filler
{
	char		my_sign;
	char		enemy_sign;
	char		**map;
	int			map_size_x;
	int			map_size_y;
	char		**piece;
	int			piece_size_x;
	int			piece_size_y;
	int			distance;
	int			result;
	int			fit_x;
	int			fit_y;
	int			game_over;
}				t_filler;

void			ft_initializer(t_filler *data);
void			ft_player(t_filler *data, char **line, int fd);
void			ft_plateau_read(t_filler *a, char **line, int fd);
void			ft_piece_read(t_filler *a, char **line, int fd);
void			ft_better(t_filler *data, int x, int y, int r);
void			best_option(t_filler *data, int x, int y);
int				second_sorter(t_filler *data, int x, int y, int *touch);
void			first_sorter(t_filler *data);

#endif
