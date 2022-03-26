#include<stdio.h>
#include<stdlib.h>
#define limit 4000000 
#define row_size 2000


main()
{
	
	long long i=0,j=0;
	long long *S=(long long*)calloc(limit,sizeof(long long));
	
	long long **tab=(long long**)calloc(row_size,sizeof(long long*));

	for(i=1;i<=55;i++)
	{
		S[i-1]=(100003+(300007*i*i-200003)*i)%1000000-500000;
	}

	for(i=56;i<=limit;i++)
	{
		S[i-1]=(S[i-25]+S[i-56]+1000000)%1000000-500000;	
	}
	long long sum=0,max=0;
	
	for(i=0;i<row_size;i++)
	{
		for(j=0;j<row_size;j++)
		{
			
		}
	}
	
	printf("%lld ",max);
	
	
		
	
	
	
}
