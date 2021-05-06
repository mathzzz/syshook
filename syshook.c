#include <dlfcn.h>
#include <stdio.h>


int execve(const char *filename, char *const argv[], char *const envp[])
{
	__typeof__(execve) *func = dlsym((void *)(-1UL), __func__);

	
	fprintf(stderr, "PID=%d;PPID=%d;%s\n", getpid(), getppid(), filename);
	return func(filename, argv, envp);
}

