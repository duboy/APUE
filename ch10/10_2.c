#include "apue.h"

static void sig_usr (int);

int
main (void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGUSR2");
		
	while (1)
	{
		pause ();
	}
}

static void
sig_usr (int signo)
{
	if (signo == SIGUSR1)
		printf ("recived SIGUSR2\n");
	else if (signo == SIGUSR2)
		printf ("recived SIGUSR2\n");
	else
		err_dump("recived signal %d\n", signo);
}
