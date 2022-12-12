#include "../incl/lem_in.h"
#include <stdlib.h>
#include <unistd.h>
t_ant *ants;

int main()
{
	int n;
	char c;
	ants = calloc(sizeof(t_ant),n);
	int whateverman = 1;
	while (whateverman)
	{
		whateverman = read(0, &c, 1);
		if (whateverman)
			write(1, &c, 1);
	}
	// lol
	return (0);
}