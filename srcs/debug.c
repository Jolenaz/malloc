#include "malloc.h"

int debug_flag = 0;

void use_malloc_debug(int flag)
{
	debug_flag = flag;
}