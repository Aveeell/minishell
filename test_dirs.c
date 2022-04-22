#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(void)
{
	DIR * dir = opendir(".");
	if (dir == NULL)
		return (1);

	struct dirent *entity;
	entity = readdir(dir);
	while (entity != NULL)
	{
		printf("%hhd %s\n", entity->d_type, entity->d_name);
		entity = readdir(dir);
	}

	closedir(dir);
	return(0);
}