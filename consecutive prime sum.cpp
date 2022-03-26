#include<stdio.h>
#include<conio.h>
#include<math.h>
int is_prime(unsigned long long a)
{
	unsigned long long i;
	int answer=0;
	
	
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			answer++;
			break;
		 } 
	}
	
	if(answer!=0) answer=0;
	else answer=1;
	return answer;
}
main()
{
	long long sum=0,max=0,answer;
	int max_num=1000000;
	int lg=0,i,j,k=0,test,l;
	int prime[78666];
		
	for(i=2;i<max_num;i++)
	{
		test=0;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0) 
			{
				test++;
				break;
			}
		}
		if(test==0)
		{
			prime[k]=i;
			k++;
		}
	}
	
	for(i=0;i<8;i++)
	{
		for(l=0;l<k;l++)
		{
			sum=0;
			lg=0;
			for(j=i;j<k-l;j++)
			{
				if(sum+prime[j]>max_num)break;
				sum+=prime[j];
				lg++;	
			}
			if(is_prime(sum)&&sum<max_num&&max<lg) 
			{
				max=lg;
				answer=sum;
				printf("sum :%d ,consecutive primes:%d\n",answer,max);
			
			}		
		}
	}	
}
