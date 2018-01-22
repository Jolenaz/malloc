#include "malloc.h"
#include <stdlib.h>


int		main(void)
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	ft_putstr("\n---------show_alloc_mem()------------\n", 1);
	show_alloc_mem();
	return (0);
}
