#include<stdio.h>
#include<conio.h>
#include<math.h>
#define int_64bit unsigned long long

is_prime(int_64bit num)
{
	int_64bit  i;
	if(num<4)return 1;
	else if(num%2==0)return 0;
	else if(num%3==0)return 0;
	else
	for(i=5;i<=sqrt(num);i+=6)
	{
		if(num%i==0||num%(i+2)==0)
		{
			return 0;
		}
		return 1;
	}
}
is_harshad(int_64bit a)
{
	int_64bit num=a,digit_sum=0;
	while(num!=0)
	{
		digit_sum+=num%10;
		num/=10;
	}
	if(a%digit_sum==0)return 1;
	else return 0;
}
is_RTHN(int_64bit a)//right truncatable Harshad number.
{
	int_64bit num=a,test=1;
	while(num!=0)
	{
		if(!is_harshad(num)) 
		{
			test=0;
			break;
		}
		else num/=10;
	}
	return test;
}
is_strong(int_64bit a)
{
	int_64bit num=a/10,digit_sum=0;
	int test=0;
	
	if(is_RTHN(num)&&num>=10)
	{
		while(num!=0)
		{
			digit_sum+=num%10;
			num/=10;
		}
		num=a/10;
		num/=digit_sum;
		if(is_prime(num)) test=1;
		else test=0;
	}
	return test;
}

main()
{
	int_64bit i,sum=0;	
	for(i=3;i<pow(10,14);i+=2)
	{
		
		if(is_strong(i)&&is_prime(i))
		{	
			sum+=i;
			printf("%lld:---->(%lld)",i,sum);
			printf("\n");
		}
		
	}
	printf("\nthe sum is :%lld",sum);
}
