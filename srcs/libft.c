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

unsigned long	strlen(const char *str)
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

void			putstr(char *str)
{
	write(1, str, strlen(str));
}
