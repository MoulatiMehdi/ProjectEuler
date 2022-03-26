#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n =20000000;
int k =15000000;
main()
{

	int min=(k>n-k)? n-k:k;
	int *T=(int*)calloc(n+1,sizeof(int));
	int *sum=(int*)calloc(n+1,sizeof(int));
	int j,i;
	
	
	sum[2]=2;
	for(i=2;i<=sqrt(n);i++)
	{
	
		if(!T[i])
		{
			
			j=i;
			while(j*i<=n)
			{
				T[i*j]=1;
				j++;
			}
		}
	}
	for(i=3;i<=n;i+=2)
	{
		if(!T[i])
		{
			sum[i]=i;
		}
	}
	for(i=2;i<=sqrt(n);i++)
	{
		
		if(!T[i])
		{
			j=i;
			while(i*j<=n)
			{
				sum[i*j]=sum[j]+i;
				j++;
			}
		}	
	}
	long long answer=0;
	while(min!=0)
	{
		answer+=sum[n];
		answer-=sum[min];
		n--;
		min--;
	}
	printf(" -->sum=%lld",answer);
}
