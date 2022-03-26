#include<stdio.h>
#include<math.h>
#include<stdlib.h>
is_prime(int num)
{
	int  i,test=1;
	if(num<=1)test=0;
	else if(num<=3) test=1;
	else if(num%2==0) test=0;
	else if(num%3==0) test=0;
	else
	for(i=5;i<=sqrt(num);i+=6)
	{
		if(num%i==0||num%(i+2)==0)
		{
			test=0;
			break;
		}
	}
	return test;
}
int M(int p,int q,int N)
{
	int answer,max=0;
	int i,j;
	if(p*q<=N)
	{
		for(i=1;pow(p,i)<=N/q;i++)
		{
			
			for(j=1;pow(q,j)*pow(p,i)<=N;j++)
			{
				answer=pow(q,j);
				while(answer<=N/pow(p,i))	answer*=pow(p,i);
				if(answer>max) max=answer;
			
				answer=pow(p,i);
		
				while(answer<=N/pow(q,j)) answer*=pow(q,j);
				if(answer>max) max=answer;
			}
		}
 	}
	return max;
}


main()
{
	
	int limit=10000000,j=1,i;
	
	int * prime=(int*)calloc(1000000,sizeof(int));
	
	prime[0]=2;
	for(i=3;i<=limit;i+=2)
	{
		if(is_prime(i))
		{
			prime[j]=i;
			j++;
		}
	}
	int max=j;
	long long sum=0,num;
	
	for(i=0;i<max;i++)
	{
		for(j=i+1;j<max;j++)
		{
			if(prime[i]*prime[j]>limit) break;
			num=M(prime[i],prime[j],limit);
			sum+=num;
		}
	}
	printf("%lld",sum);
}
