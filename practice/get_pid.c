#include <unistd.h>
#include <stdio.h>


int main()
{
	pid_t my_pid, parent_pid;

	my_pid = getpid();
	parent_pid = getppid();
	printf("parent pid is: %u\n Child Id is %u\n : ",parent_pid, my_pid);
	return (0);
}
