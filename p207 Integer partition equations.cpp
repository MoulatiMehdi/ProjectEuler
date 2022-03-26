#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long  solve(int num,int denum)
{
	long long  perfect=0,total=0;
	long long  P=1;
	for(long long i=2;;i++)
	{
		double  t=log2(i);
		long long   K=pow(2,t)*(pow(2,t)-1);
		if(t==(long long )t) perfect++;//if t is a perfect 
		total++;
		P=perfect*denum;

		if(P<total*num)
		{
			printf("-->%d/%d",perfect,total);
			return (long long)K;
		}
	}
	
	
}
main()
{
	printf("-->%lld",solve(1,12345));
}//other method :
/*
#include<stdio.h>
#include<math.h>
is_pow_2(int num)
{
	return (num&(num-1))==0;
}
long long  solve(int num,int denum)
{
	long long j=1,total=1;
	long long  P=1;
	for(long long i=3;;i++)
	{
		P=i*i-i;
		if(is_pow_2(i))j++;
		total++;
		
		if(j*denum<total*num)
		{
			printf("%d/%d=",j,total);
			return P;
			}	
			
	}
	
	
}
main()
{
	printf("%lld",solve(1,12345));
}
*/
