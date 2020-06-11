#include "miniRT.h"

int     error(int n)
{
	if (n == -1)
		write(1, "Error -1: Can't find scene file\n", 32);
        if (n == -2)
                write(1, "Error -2: Invalid scene data\n", 29);
	if (n == -3)
		write(1, "Error -3: Memory allocation issue\n",35);
	exit(n);
}
