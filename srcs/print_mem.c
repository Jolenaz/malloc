/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:33:15 by jbelless          #+#    #+#             */
/*   Updated: 2018/01/22 15:33:17 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			ft_putnbr_hex_heigth(unsigned long long nbr, char flag)
{
	static char	phrase[16] = "0123456789ABCDEF";
	char		str[11];
	int			i;

	i = 0;
	ft_memcpy(str, "00000000  \0", 11);
	while ((nbr / 16) != 0)
	{
		i++;
		str[8 - i] = phrase[nbr % 16];
		nbr /= 16;
	}
	i++;
	str[8 - i] = phrase[nbr % 16];
	ft_putstr(str, flag);
}

void			ft_print_line(char *data, int nb)
{
	char		str[52];
	static char	phrase[16] = "0123456789ABCDEF";
	int			i;
	int			j;

	j = 0;
	i = 0;
	str[51] = 0;
	while (i < 51)
	{
		str[i] = ' ';
		i++;
	}
	i = 0;
	while (j < nb)
	{
		str[i] = phrase[(data[j] / 16) % 16];
		str[i + 1] = phrase[data[j] % 16];
		i += 3;
		j++;
		if (j == 7)
			i++;
	}
	ft_putstr(str, 1);
}

void			ft_printable(char *data, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (data[i] > 31 && data[i] != 127)
			ft_putchar(data[i], 1);
		else
			ft_putchar('.', 1);
		i++;
	}
	ft_putchar('\n', 1);
}

void			print_mem_hex(void *data, size_t size)
{
	size_t i;

	ft_putstr("Addr print : ", 1);
	ft_putnbr_hex_endl((unsigned long long)data, 1);
	i = 0;
	while ((int)size > 0)
	{
		ft_putnbr_hex_heigth((unsigned long long)i, 1);
		ft_print_line((char*)data + i, (int)(size >= 16 ? 16 : size));
		ft_printable((char*)data + i, (int)(size >= 16 ? 16 : size));
		size -= 16;
		i += 16;
	}
	data = NULL;
	size = 0;
}
