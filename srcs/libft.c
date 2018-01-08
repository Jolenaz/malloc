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
	if (debug_flag)
		write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	if (debug_flag)
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

void			ft_putnbrendl(unsigned long long  nbr)
{
	ft_putnbr(nbr);
	ft_putchar('\n');
}

void			ft_memcpy(void *new_v, void *old_v, size_t size)
{
	char *new;
	char *old;

	if (new_v == NULL || old_v == NULL || size == 0)
		return;
	new = (char*)new_v;
	old = (char*)old_v;
	while(size)
	{
		*new = *old;
		new++;
		old++;
		size--;
	}
}
