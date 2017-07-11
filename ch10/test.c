#include "apue.h"

volatile sig_atomic_t quitflag;

main ()
{
	printf ("%d", quitflag);
}
