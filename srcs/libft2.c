#include "malloc.h"

void			ft_putnbr_hex_endl(unsigned long long nbr, char flag)
{
	ft_putnbr_hex(nbr, flag);
	ft_putchar('\n', flag);
}

void			ft_putnbr_endl(unsigned long long nbr, char flag)
{
	ft_putnbr(nbr, flag);
	ft_putchar('\n', flag);
}

void			ft_memcpy(void *new_v, void *old_v, size_t size)
{
	char *new;
	char *old;

	if (new_v == NULL || old_v == NULL || size == 0)
		return ;
	new = (char*)new_v;
	old = (char*)old_v;
	while (size)
	{
		*new = *old;
		new++;
		old++;
		size--;
	}
}