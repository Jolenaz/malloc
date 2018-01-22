#include <stdlib.h>
#include "malloc.h"


int			main(void)
{
	char	*addr;
	char	*test;

	addr = malloc(16);
	free(NULL);
	free((void *)addr + 5);
	test = realloc((void *)addr + 5, 10);
	if (test == NULL)
		ft_putstr("Bonjours\n", 1);
	return (0);
}
