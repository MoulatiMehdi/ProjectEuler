#include<stdio.h>
#include<math.h>
int num_digit(int a)
//calculate number of digits
{
	int i=1;
	for(i=1;pow(10,i)<=a;i++) continue;
	return i;
}
main()
{
	int i,j,k=0,test,max,num,num1,sum;
	int prime[100000];
	
	prime[0]=2;
	for(i=3;i<800000;i++)
	//find the prime numbers
	{
		test=0;
		for(j=0;j<=k;j++) if(i%prime[j]==0) test++;
		if(test==0)
		{
			k++;
			prime[k]=i;
		}	
	}
	int max_prime=k;
	for(i=0;i<=max_prime;i++)
	//find truncatable numbers
	{
		max=num_digit(prime[i]);
		if(num_digit(prime[i])<2) continue;
		test=0;
		for(j=1;j<max;j++)
		//truncatable prime from right to left
		{
			num=prime[i]/pow(10,max-j);
			for(k=0;prime[k]<=num;k++) if(num==prime[k]) test++;  			
		}
		for(j=1;j<max;j++)
		//truncatable prime from left to right
		{
			num=prime[i]/pow(10,max-j);
			num1=prime[i]-num*pow(10,max-j);
			for(k=0;prime[k]<=num1;k++)if(num1==prime[k]) test++;	
		}
		if(test==(max-1)*2) 
		{
			printf("%d\n",prime[i]);
			sum+=prime[i];	
		}
	}
	printf("\nsum=%d",sum);	
}
