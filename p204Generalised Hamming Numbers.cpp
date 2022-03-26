#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define limit 1000000000
#define n 100
int*prime=(int*)calloc(n,sizeof(int));
int limit_p;
main()
{
	int *T=(int*)calloc(n,sizeof(int));
	int *result=(int*)calloc(3000000,sizeof(int));
	int i,j,k=0;
	for(i=2;i<=n;i++)
	{
		T[i]=1;
	}
	
	for(i=2;i<=n;i++)
	{
		if(T[i])
		{
			j=i;
			prime[k]=i;
			k++;
			while(j*i<=n)
			{
				T[j*i]=0;
				j++;
			}
		}
	}
	limit_p=k;
	int final_size=1,p,add_size,x,max;
	result[0]=1;
	final_size=1;
	for(i=0;i<limit_p;i++)
	{
		p=prime[i];
		add_size=final_size;
		max=limit/p;
		for(j=0;j<final_size;j++)
		{
			x=result[j];
			while(x<=max)
			{
				x*=p;
				result[add_size]=x;
				add_size++;	
				
			}
		}
		final_size=add_size;
		
	}
	printf("%d\n",final_size);
}
