#include<stdio.h>
#include<math.h>
int reverse(int num)
{
	int answer=0;
	if(num%10==0) num=0;
	while(num!=0)
	{
		answer*=10;
		answer+=num%10;
		num/=10;
	}
	return answer;
}
is_digits_odd(int num)
{
	int answer=1;
	if(num<10)
	{
		if(num%2==0) answer=0;
		else answer=1;
	}
	else 
	while(num!=0)
	{
		
		if(num%2==0)
		{
			answer=0;
			break;
		}
		num/=10;	
	}
	return answer;
}
main()
{
	int i,answer=0;
	int max=pow(10,9);
	int num,reverse_i;
	for(i=11;i<=max;i+=2)
	{
		reverse_i=reverse(i);
		num=i+reverse_i;
		if(is_digits_odd(num)) 
		{
			answer+=2;
			printf("%d+%d=%d\n",i,reverse_i,num);
		}
		
		
	}
	printf("\n---->%d",answer);
}
