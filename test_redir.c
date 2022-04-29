#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buf = malloc(10000);
	read(0, buf, 10000);
	buf[9999] = '\0';
	printf("%s\n", buf);
	free(buf);
}