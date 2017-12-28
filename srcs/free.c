/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:44:40 by jbelless          #+#    #+#             */
/*   Updated: 2017/12/26 11:44:41 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void free(void *data){
	if (data == NULL)
		return;
		ft_putstr("addr donne in free : ");
		ft_putnbr((unsigned long long )data);
		ft_putstr("\n");
}
