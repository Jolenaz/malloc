
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

	while(j < 1000000)
	{
		int r = rand() % 100;

		int l =  rand() % (1024 * 16 * 16);
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

	int i = 1;
	while(i < 10000)
	{
		c = (char*)malloc(i);
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
	// c = realloc(c, 20);
	int line = 2;
	char *c = malloc(16 * line);
	int i = 0;
	while(i < (line * 16))
	{
		c[i] = i + 'A';
		i++;
	}
	print_mem(c);
	return (0);
}
