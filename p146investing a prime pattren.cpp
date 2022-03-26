#include<stdio.h>
#include<math.h>
#include<stdlib.h>
is_prime(long long num)
{
	if(num%2==0) return 0;
	else if(num%3==0) return 0;
	else
	{
		for(int i=5;i<=sqrt(num);i+=6)
		{
			if(num%i==0||num%(i+2)==0)
			{
				return 0;
			}
		}
		return 1;
	}
}
i
main()
{
	int i,j;
	long long limit=15000000;
	long long n,m;
	long long sum=0;
	int p[]={2,3,5,7,11,13,17,19,23,29};
	int res[10];
	
	
	/*for(long long n=10;n<limit;n+=10)
	{
		
		long long square=n*n;
		if(square%3!=1)continue;
		if(square%7!=2&&square%7!=3)continue;
		if(square%9==0||square%13==0||square%27==0)continue;
		
		if(is_prime(square+1))
		if(is_prime(square+3))
		if(is_prime(square+7))
		if(is_prime(square+9))
		if(is_prime(square+13))
		if(is_prime(square+27))
		 sum+=n,printf("%lld(%lld)\n",n,sum);
		
		
	}*/
	
	printf("%lld",sum);
	
	
}
