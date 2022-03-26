#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define int_64bit unsigned long long 
int_64bit *prime=(int_64bit*)calloc(100,sizeof(int_64bit));

int_64bit divisor_num(int_64bit num,int n)
// number of divisor for a given number^n without repetition
{
	int answer=1,i=0;
	while(num!=1&&prime[i]!=0)
	{
		int_64bit mul=1;
		while(num%prime[i]==0)
		{
			num/=prime[i];
			mul+=n;
		}
		answer*=mul;
		i++;
	}
	return ceil(answer/2);
}

is_prime(int_64bit num)
{
	int_64bit answer=1;
	if(num<=1)answer=0;
	else if(num<4)answer=1;
	else if(num%2==0)answer=0;
	else if(num%3==0)answer=0;
	else
	{
		for(int_64bit i=5;i<=sqrt(num);i+=6)
		{
			if(num%i==0||num%(i+2)==0)
			{
				answer=0;
				break;
			}
		}
	}
	return answer;
}
main()
{
	int_64bit target=4000000-1;
	int_64bit min;
	int_64bit max=1;
	
	int l=0;
	int max_pow=0;
	int max_prime;
	int i,j,k;
	for( i=2;;i++)
	{
		if(is_prime(i))
		{
			prime[l]=i;
			l++;
			max*=i;
			if(divisor_num(max,2)>target)break;
		}
		
	}
	min=max;
	max_prime=l;
	// l is number of factorizing discunt prime numbers  that num_solution>4_000_000-1
	//max is the result of factorizing  discunt prime numbers (from 2 to prime[l-1])
	//pow_prime[i] is the power of each prime number (from prime[0] to prime[l-1])
	
	int pow_prime[max_prime];
	
	while(pow(max_pow,max_prime)<=target) max_pow++;
	
	//max_pow is maximum power number needed to be
	// in all prime numbers( l prime numbers) to exceding num_solution>4_000_000-1 
	// i already know that max_pow ==3
	
	//i,jand k are number of primes  
	 
	for(i=0;i<max_prime;i++)// if pow=3 
	{
		for(j=0;j<max_prime-i;j++)//if pow=2
		{
			for(k=0;k<max_prime-i-j;k++)//if pow=1
			{
				max=pow((3*2+1),i)*pow((2*2+1),j)*pow((1*2+1),k);//(num*2+1)
				max/=2;
				if(max>target)
				{
					
					if(min>max)
					{
						min=max;
						printf("%lld : ",max);
						l=0;
						while(l<i)
						{
							pow_prime[l]=3;
							l++;
						}
						while(l<i+j)
						{
							pow_prime[l]=2;
							l++;
						}
						while(l<i+j+k)
						{
							pow_prime[l]=1;
							l++;
						}
						
						while(l<max_prime)
						{
							pow_prime[l]=0;
							l++;
						}
						printf(" 3:%d 2:%d 1:%d 0:%d\n",i,j,k,max_prime-i-j-k-1);
					}
				}
			}
		}
	}
	max=1;
	for(i=0;i<max_prime;i++)
	//the higher power to the lowest prime to find the least value of n 
	{
		for(int j=i+1;j<max_prime;j++)
		{
			if(pow_prime[j]>pow_prime[i])
			{
				int n=pow_prime[i];
				pow_prime[i]=pow_prime[j];
				pow_prime[j]=n;			
			}
		}
		max*=pow(prime[i],pow_prime[i]);
	}
	printf("\n%lld",max);
}
