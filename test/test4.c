#include <stdlib.h>
#include "malloc.h"


int			main(void)
{
  char *addr; 

  addr = malloc(16); 
  free(NULL); 
  free((void *)addr + 5); 
  if (realloc((void *)addr + 5, 10) == NULL) 
  	ft_putstr("Bonjours\n", 1); 
}
