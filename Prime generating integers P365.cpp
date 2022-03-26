#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define max 100000000
int is_prime(int num)
{
	int i,answer=1;
	if((num%2==0&&num!=2)||num<=1) answer=0;
	else 
	for(i=3;i<=sqrt(num);i+=2)
	{
		if(num%i==0)
		{
			answer=0;
			break;
		}
	}
	return answer;
}
main()
{
	int i,n,j,test;
	unsigned long long answer=0;
	for(n=1;n<=max;n++)
	{
		test=1;
		for(i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				j=i+n/(i);	
				if(!is_prime(j))
				{
					test=0;
					break;
				}
			}
		}
		if(test==1) answer+=n;	
	}
	printf("the aswer is  :%lld",answer);
}
