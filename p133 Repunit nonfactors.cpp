#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
int A(int p)
{
	int rest=1;
	int k=1;
	while(rest!=0)
	{
		rest=(rest*10+1)%p;
		k++;
	}
	return k;
}
main()
{
	int limit=100000;
	int *is_p=(int*)calloc(limit+1,sizeof(int));
	int i,j;
	
	for(i=3;i<=sqrt(limit);i+=2)
	{
		if(!is_p[i])
		{
			j=i;
			while(i*j<=limit)
			{
				is_p[i*j]=1;
				j++;
			}
		}
	}
	is_p[2]=is_p[5]=1;
	long long  answer=2+5;
	
	for(i=3;i<=limit;i+=2)
	{
		if(!is_p[i])
		{
			int num=A(i);
			while(num%10==0)
			{
				num/=10;
			}
			while(num%2==0)
			{
				num/=2;
			}
			while(num%5==0)
			{
				num/=5;
			}
			if(num!=1) answer+=i;
		}
	}
	
	printf("%lld",answer);
}
