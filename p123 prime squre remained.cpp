#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define int_64bit unsigned long long
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
int_64bit R(int_64bit p,int_64bit n)
{
	if(n%2==0)return 2;
	else return 2*n*p;	
}
main()
{
	int p,j=3;
	int_64bit max_R=pow(10,10);
	int_64bit max;
	
	for(p=5;;p+=2)
	{
		
		if(is_prime(p))
		{
			if(j%2==0)
			{
				j++;
				continue;
			}
			else
			{
				max=R(p,j);
				if(max>max_R)
				{
					printf("n=%d ,p=%d-->%lld\n",j,p,max);
					break;
				}
				j++;
			}
		}
		
	}
	
	
}
