
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

	int i =0;
	while(i < 1000)
	{
		c = (char*)malloc(100000000 * i);
		if (c == NULL)
			write(1, "probleme \n", 10);
		free(c);
		c = NULL;
		i++;
	}


}

int main()
{
	test1();
	return (0);
}
