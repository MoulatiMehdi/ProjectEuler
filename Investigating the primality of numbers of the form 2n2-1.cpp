#include<stdio.h>
#include<stdlib.h>
#include<math.h>
is_prime(long long num)
{
	if(num<4)return 1;
	else if(num%2==0)return 0;
	else if(num%3==0)return 0;
	else 
	{
		for(long long i=5;i<=sqrt(num);i+=6)
		{
			if(num%i==0||num%(i+2)==0) return 0;
		}
		return 1;
	}
}
main()
{
	long long max=50000000,k=0;
	for(long long i=2;i<=max;i++)
	{
		if(is_prime(2*i*i-1))k++;
	}
	printf("-->%lld",k);
}
