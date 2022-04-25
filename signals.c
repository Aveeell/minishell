#include "minishell.h"

int signals(int signal)
{
	printf("\n%d\n", signal);
}
int main(void)
{
	char c;
	read(0, &c, 1);
	printf("\n%c\n", c);
		signal(9, signals);
	usleep(1000000000);
	return 0;
}