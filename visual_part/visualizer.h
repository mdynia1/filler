/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:17:58 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/28 21:18:01 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# include <mlx.h>
# include "../libft/libft.h"
# include "../filler.h"

typedef struct	s_visual
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			map_y;
	int			map_x;
	int			to_pause;
	int			pix;
	int			to_type;
	int			p1_color;
	int			p2_color;
	int			p1_color_add;
	int			p2_color_add;
	int			score1;
	int			score2;
	char		*sign_1;
	char		*sign_2;
}				t_visual;

void			print_pixels(t_visual *v, size_t y, size_t x);
void			player_map_determine(t_visual *v, char *line);
char			*player_nick(char *line, char *str);
int				keys(int keycode, t_visual *v, char *line);
void			ft_flag_check(int argc, char **argv, t_visual *v);
void			if_to_pause(t_visual *v);
void			if_to_type(t_visual *v, char *line);
void			map_reader(t_visual *a, char *line);
void			map_visualizer(t_visual *v);
void			ft_flag_check(int argc, char **argv, t_visual *v);
void			ft_initialize(t_visual *v);
void			game_over_func(t_visual *a);
int				ft_add_color_set(int c);
int				ft_color_set(char *str);
int				color(t_visual *v, size_t y, size_t x);
void			color_main(char **argv, t_visual *v, int argc);
void			score_put(t_visual *a);
void			plateau_read(t_visual *a, char *line);

#endif
