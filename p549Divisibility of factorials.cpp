#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int limit=pow(10,8);
int *cache=(int*)calloc(limit+1,sizeof(int));
long long s(int n)
{
	long long rest=1,i=0;
	while(rest!=0)
	{
		i++;
		rest*=i%n;
		rest%=n;
		
	}
	return i;
}
long long S(int n)
{
	long long result=0;
	for(int i=2;i<=n;i++)
	{
		if(cache[i]==0)cache[i]=s(i);
		printf("%d-->%d\n",i,cache[i]);
		result+=cache[i];
	}
	return result;
	
}
main()
{
	int *is_prime=(int*)calloc(limit+1,sizeof(int));
	int i,j;
	int target=100;
	int sq_t=sqrt(target);
	for( i=3;i<=sq_t;i+=2)
	{
		if(!is_prime[i])
		{
			j=i;
			cache[i*i]=i*2;	
			while(j*i<=target)
			{
				is_prime[j*i]=1;
				j+=2;
			}
		}
	}
	cache[2]=2;
	cache[4]=4;
	for(i=3;i<=target;i+=2)
	{
		if(!is_prime[i]) 
		{
			cache[i]=i;
		}
	}
	printf("%lld",S(target));
}
