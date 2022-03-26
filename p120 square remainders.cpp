#include<stdio.h>
#include<math.h>
int Rmax(int a)
{
	int n=(a-1)/2;
	return (2*n*a);
}

main()
{
	int answer=0;
	for(int i=3;i<=1000;i++)
	{
		answer+=Rmax(i);
	}
	printf("%d",answer);
}
