#include "apue.h"
#include <setjmp>

static void f1 (int, int, int, int);
static void f2 (void);

static jmp_buf jmpbuffer;
static int gobval;

int 
main (void)
{
	int autoval;
	register int regival;
	volatile int volaval;
	static statval;
	
	globval = 1; autoval = 2; regival = 3; volaval =4; statval = 5;
	
	if (setjmp (jmpbuffer) != 0)
	{
		printf ("after longjmp: \n");
		printf ("gobval = %d, autoval = %d, regival = %d,"
			" volaval = %d, staval = %d\n",
			globval, autoval, regival, volaval, statval);
		exit (0);
	}
	
	f1 (autoval, regival, volaval, statval);
	ext (0);
}

static void
f1 (int i, int j, int k, int l)
{
	printf ("in f1():\n");
	printf ("gobval = %d, autoval = %d, regival = %d,"
		" volaval = %d, staval = %d\n",	globval, i, j, k, l);
		
	f2 ();
}

static void
f2 (void)
{
	longjmp (jmpbufer, 1);
}
