/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:53:49 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/27 14:53:53 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

unsigned long	ft_strlen(const char *str)
{
	size_t	i;
	char 	*ptr;

	if (str == NULL)
		return (0);
	i = 0;
	ptr = (char*)str;
	while (*ptr)
	{
		i++;
		ptr++;
	}
	return (i);
}

void			ft_putchar(char c)
{
	if (DEBUG)
		write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	if (DEBUG)
		write(1, str, ft_strlen(str));
}

void			ft_putnbr(unsigned long long  nbr)
{
	static char phrase[10] = "0123456789";

	if ((nbr / 10) != 0)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar(phrase[nbr % 10]);
}
