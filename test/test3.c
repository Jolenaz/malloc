#include <string.h>
#include <stdlib.h>
#include "malloc.h"


#define M1 (1024 * 1024)

int			main(void)
{
	char	*addr1;
	char	*addr3;

	addr1 = (char *)malloc(16 * M1);
	strcpy(addr1, "Bonjours\n");
	ft_putstr(addr1, 1);
	addr3 = (char *)realloc(addr1, 128 * M1);
	addr3[127 * M1] = 42;
	ft_putstr(addr3, 1);
	return (0);
}
