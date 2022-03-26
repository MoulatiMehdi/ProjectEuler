#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define limit 10000
#define int_big unsigned long long 
is_prime(int num)
{
	int answer=1;
	if(num<=1)answer=0;
	else if(num%2==0)answer=0;
	else if(num%3==0)answer=0;
	else
	{

		for(int i=5;i<=sqrt(num);i+=6)
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
	int target=1000000;
	int num_p=0,num;
	for(int a=0;num<=target;a++)
	{
		num=3*a*(1+a)+1;
		if(is_prime(num))
		{
			num_p++;
		}
	}
	printf("%d",num_p);

	
	
}
