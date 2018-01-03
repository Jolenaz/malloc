/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:44:33 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/26 11:44:36 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_book	g_book = (t_book){NULL, NULL, NULL};

void	*malloc(size_t size)
{
	g_min_size = getpagesize();
	if (size == 0)
		return (NULL);
	if (size <= TINY * g_min_size)
		return (use_g_tiny(size, &g_book));
	else if (size <= SMALL * g_min_size)
		return (use_g_small(size, &g_book));
	else
		return (use_g_large(size, &g_book));
}

void free(void *data){
	ft_putstr("addr donne in free : ");
	ft_putnbr((unsigned long long )data);
	ft_putstr("\n");
	if (data == NULL || !is_in_book(data, &g_book))
		ft_putstr("not in my book\n");
	else
		ft_putstr("in my book\n");
	
}

void	*realloc(void * ptr, unsigned long int i)
{
	ptr = NULL;
    return (malloc(i));
}
