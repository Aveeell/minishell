#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	
	execve("/bin/ls", argv, envp);
}