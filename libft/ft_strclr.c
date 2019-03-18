/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:46:44 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 15:26:29 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char	*str;
	int		i;

	if (s)
	{
		str = s;
		i = 0;
		while (str[i] != '\0')
		{
			str[i] = '\0';
			i++;
		}
	}
}
