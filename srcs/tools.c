/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:53:42 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/27 14:53:45 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char	is_free(char state)
{
	return ((state & IS_FREE) == IS_FREE);
}

char	is_last(char state)
{
	return ((state & IS_LAST) == IS_LAST);
}	
