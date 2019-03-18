/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_for_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:05:45 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/28 21:05:52 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	ft_initialize(t_visual *v)
{
	v->score1 = 0;
	v->score2 = 0;
	v->sign_1 = NULL;
	v->sign_2 = NULL;
	v->map_y = 100;
	v->map_x = 100;
	v->to_pause = 0;
	v->to_type = 0;
	v->pix = 10;
	v->p2_color = 0x800080;
	v->p2_color_add = 0x590059;
	v->p1_color_add = 0x99cc99;
	v->p1_color = 0x008000;
}

void	player_map_determine(t_visual *v, char *line)
{
	while ((!v->sign_1 || !v->sign_2) && get_next_line(0, &line) > 0)
	{
		if_to_type(v, line);
		if (ft_strstr(line, "p1"))
			v->sign_1 = player_nick(line, v->sign_1);
		if (ft_strstr(line, "p2"))
			v->sign_2 = player_nick(line, v->sign_2);
	}
	while (get_next_line(0, &line))
	{
		if_to_type(v, line);
		if (ft_strcmp(ft_strsub(line, 0, 7), "Plateau") == 0)
		{
			v->map_y = (ft_atoi((line) + 8));
			v->map_x = (ft_atoi((line) + 8 + (ft_part_itoa(v->map_y))));
			break ;
		}
	}
}

char	*player_nick(char *line, char *str)
{
	str = ft_strdup(ft_strchr(line, '['));
	if (ft_strchr(str, '/'))
		str = ft_strchr(str, '/') + 1;
	if (ft_strchr(str, '.'))
		*ft_strchr(str, '.') = '\0';
	return (str);
}
