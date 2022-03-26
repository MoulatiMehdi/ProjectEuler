#include<stdio.h>
#include<math.h>
#include<conio.h>

main()
{
	long long i,j,a;
	long test,answer=0;
	long sum=0;
	int max=7;
	
	for(i=2;i<400000;i++)
	{
		test=i;
		sum=0;
		for(j=0;j<max;j++)
		{
			a=test/pow(10,max-1-j);
			test-=a*pow(10,max-1-j);
			sum+=pow(a,5);	
		}
		if(sum==i)
		{
			printf("--->%d\n",i);
			answer+=i;
		 } 	
	}
	printf("the sum is %d",answer);	
}
