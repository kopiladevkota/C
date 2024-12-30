#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x0,x,a,c,M=101;
	x0 = 29,a=34,c=11;
	double r;
	printf("15 pseudo-random numbers normalized in the range [0, 1) are :\n");
	for(int i=1;i<=10;i++)
	{
		x = (a*x0+c)%M;
		r = (double)x/M;
		printf(" %f\n",r);
		x0 = x;
	}
}
