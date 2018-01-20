
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

	while(j < 100000)
	{
		if (j>=621)
		{
			use_malloc_debug(1);
			ft_putnbr_endl(j,1);
	show_all_mem();

		}
		int r = rand() % 100;

		int l =  rand() % 1024;
		if (c[r] == NULL)
			c[r] = malloc(l);
		else if (l % 2)
		{
			free(c[r]);
			c[r] = NULL;
		}
		else
			c[r]=realloc(c[r],l);
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
	// char *c = malloc(100);
	// char *p = malloc(10);
	// show_all_mem();
	// c = realloc(c, 20);
	test1();
	return (0);
}
