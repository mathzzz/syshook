// #define _GNU_SOURCE #define RTLD_NEXT ((void *)(-1l))
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static inline int 
sncat(char *buf, size_t bufsize, char *chip)
{
	int len = 0;
	int chip_size = strlen(chip);
	if(chip_size+1 < bufsize && bufsize > 0) {
        strncpy(buf, chip, chip_size+1);
		len = chip_size;
	}
	return len;
}

#ifdef  myexecve
int execve(const char *filename, char *const argv[], char *const envp[])
{
    char buf[1024];
    char args[8192];
    int i, len;


	__typeof__(execve) *func = dlsym((void *)(-1UL), __func__);
	
    for(len=0, i=0; argv[i]; i++) {
        len += sncat(args+len, sizeof(args)-len, " ");
        len += sncat(args+len, sizeof(args)-len, argv[i]);
    }

	fprintf(stderr, ":; PID=%d;PPID=%d;cd %s; %s %s\n", getpid(), getppid(), getcwd(buf, sizeof(buf)), filename, args);
	return func(filename, argv, envp);
}
#endif



#ifdef mymain
int main(int argc,  char **argv)
{
	__typeof__(execve) *func = dlsym(RTLD_NEXT, __func__);

	
	fprintf(stderr, "PID=%d;PPID=%d;%s\n", getpid(), getppid(), __func__);
	return func(argc, argv);
}

#endif

