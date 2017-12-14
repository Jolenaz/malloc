#include <sys/mman.h>

void* mallocL(unsigned long int i)
{
    return (mmap(0, i, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
}