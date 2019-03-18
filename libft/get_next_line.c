/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:20:13 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/13 15:20:31 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl_struct			*create_struct(t_gnl_struct **a_structs, int fd)
{
	t_gnl_struct		*new;
	t_gnl_struct		*tmp;

	new = *a_structs;
	while (new)
	{
		if (new->fd == fd)
			return (new);
		new = new->next;
	}
	if (!(tmp = (t_gnl_struct*)malloc(sizeof(t_gnl_struct))))
		return (NULL);
	tmp->str = ft_strnew(0);
	tmp->fd = fd;
	tmp->next = *a_structs;
	*a_structs = tmp;
	return (*a_structs);
}

void					to_terminate(t_gnl_struct *st, char **line)
{
	char				*to_free;
	char				*m;

	to_free = st->str;
	if ((m = ft_strchr(st->str, '\n')))
	{
		*m = '\0';
		*line = ft_strdup(st->str);
		st->str = ft_strdup(++m);
	}
	else
	{
		*line = ft_strdup(st->str);
		ft_strclr(st->str);
	}
	ft_memdel((void*)&to_free);
}

int						get_next_line(const int fd, char **line)
{
	static t_gnl_struct	*gnl_all;
	t_gnl_struct		*current;
	char				*buffer;
	int					len;
	char				*to_free;

	if (fd < 0 || read(fd, NULL, 0) < 0 || !line)
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	current = create_struct(&gnl_all, fd);
	while (!ft_strchr(current->str, '\n') && (len = read(fd, buffer,
		BUFF_SIZE)))
	{
		buffer[len] = '\0';
		to_free = current->str;
		current->str = ft_strjoin(current->str, buffer);
		ft_memdel((void*)&to_free);
	}
	ft_memdel((void*)&buffer);
	if (ft_strlen(current->str) == 0 && len == 0)
		return (0);
	to_terminate(current, line);
	return (1);
}
