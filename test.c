
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

void test1(){
	void *c[100];
	
	for (int i =0; i < 100; i++){
		c[i] = NULL;
	}

	int j = 0;
	int bo = 0;

	while(j < 408000)
	{
		int r = rand() % 100;

		if (j > 8)
		{
			bo = 0; 
			// write(1, "death\n",6);
		}
		if (c[r] == NULL)
		{
			int l =  rand();

			if (bo)
				write(1,"toto0\n",6);
			c[r] = malloc(l);
			if (bo)
				write(1,"totO1\n",6);
		}
		else
		{
			free(c[r]);
			c[r] = NULL;
		}
		j++;
	}
}

void test2()
{
	char *c;

	int i =1;
	while(i < 10)
	{
		c = (char*)malloc(i);
		if (c == NULL)
			write(1, "probleme \n", 10);
		free(c);
		c = NULL;
		i++;
	}


}

void test3()
{
}

int main()
{
	use_malloc_debug(DEBUG_ENABLE);
	char *c = NULL;
	c = malloc(1);
	use_malloc_debug(DEBUG_DISABLE);
	ft_putstr("here2\n");
	return (0);
}
