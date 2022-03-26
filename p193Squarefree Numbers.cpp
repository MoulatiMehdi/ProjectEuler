#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define limit pow(2,50)
main()
{
	int i,j;
	long long  sq_limit=sqrt(limit);
	printf("%d",sq_limit);
	int *is_prime=(int*)calloc(sq_limit,sizeof(int));
	for(i=2;i<=sqrt(sq_limit);i++)
	{
		if(!is_prime[i])
		{
			j=1;
			while(j*i<=sq_limit)
			{
				is_prime[i*j]=1;
				j++;
			}
		}
	}

}
