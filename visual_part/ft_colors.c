/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:09:01 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/28 21:09:32 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		ft_add_color_set(int c)
{
	int c2;

	c2 = 0;
	if (c == 0xff3232)
		c2 = 0xff6666;
	if (c == 0x324f9f)
		c2 = 0x7f7fff;
	if (c == 0xFFA500)
		c2 = 0xffc966;
	if (c == 0xffff00)
		c2 = 0xffff99;
	if (c == 0xFFC0CB)
		c2 = 0xffe5ea;
	if (c == 0x585757)
		c2 = 0xbfbfbf;
	if (c == 0x008000)
		c2 = 0x99cc99;
	if (c == 0x800080)
		c2 = 0x590059;
	return (c2);
}

int		ft_color_set(char *str)
{
	int c;

	c = 0;
	if (ft_strstr(str, "red"))
		c = 0xff3232;
	if (ft_strstr(str, "blue"))
		c = 0x324f9f;
	if (ft_strstr(str, "orange"))
		c = 0xFFA500;
	if (ft_strstr(str, "yellow"))
		c = 0xffff00;
	if (ft_strstr(str, "pink"))
		c = 0xFFC0CB;
	if (ft_strstr(str, "grey"))
		c = 0x585757;
	if (ft_strstr(str, "green"))
		c = 0x008000;
	if (ft_strstr(str, "purple"))
		c = 0x800080;
	return (c);
}

int		color(t_visual *v, size_t y, size_t x)
{
	if (v->map[y][x] == 'O')
		return (v->p1_color);
	else if (v->map[y][x] == 'o')
		return (v->p1_color_add);
	else if (v->map[y][x] == 'X')
		return (v->p2_color);
	else if (v->map[y][x] == 'x')
		return (v->p2_color_add);
	else
		return (0xE8E8E8);
}

void	color_main(char **argv, t_visual *v, int argc)
{
	if (argv[argc + 1] && argv[argc + 2])
	{
		v->p1_color = ft_color_set(argv[argc + 1]);
		v->p2_color = ft_color_set(argv[argc + 2]);
		v->p1_color_add = ft_add_color_set(v->p1_color);
		v->p2_color_add = ft_add_color_set(v->p2_color);
	}
	if (!argv[argc + 1] || !argv[argc + 2] || v->p1_color == 0
		|| v->p2_color == 0)
	{
		ft_printf("%s\n", "Available colors:\n *red;\n *blue;\n *orange;");
		ft_printf("%s\n", " *yellow;\n *pink;\n *grey; \n *green;\n *purple;");
		ft_initialize(v);
	}
}
