#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define int_big unsigned long long
int fact_mod_p(int num,int p)
{
	int answer=1;
	while(num>=1)
	{
		answer*=num;
		answer%=p;	
		num--;
	}
	answer%=p;
	return answer;
}
S(int p)
{
	int answer=0;
	answer=ceil(9*(p-1)/(24%p));
	answer%=p;
	
	return answer;
}
main()
{
	int limit=100;
	int *T=(int*)calloc(limit,sizeof(int));
	int i,j,k=0;
	int_big sum=0;
	for(i=3;i<limit;i+=2)
	{
		T[i]=1;
	}
	for(i=2;i<=sqrt(limit);i++)
	{
		if(T[i])
		{

			j=i;
			while(j*i<limit)
			{
				T[i*j]=0;
				j+=2;
			}
		}
	}
	for(i=5;i<=limit;i+=2)
	{
		if(T[i])
		{
			sum+=S(i);
		}
	}
	printf("%lld",sum);

}
