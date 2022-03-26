#include<stdio.h>
#define int64_bit unsigned long long
int64_bit is_triangle(int64_bit a)
{
	int64_bit i,num=0,answer=0;
	
	for(i=0;num<a;i++)
	{
		num=i*(i+1)/2;
		if(num==a) 
		{
			answer=1;
			break;
		}
	}
	return answer;
}
int64_bit is_penta(int64_bit a)
{
	int64_bit i,num=0,answer=0;
	
	for(i=0;num<a;i++)
	{
		num=i*(3*i-1)/2;
		if(num==a) 
		{
			answer=1;
			break;
		}
	}
	return answer;
}
int64_bit is_hexa(int64_bit a)
{
	int64_bit i,num=0,answer=0;
	for(i=0;num<a;i++)
	{
		num=i*(2*i-1);
		if(num==a) 
		{
			answer=1;
			break;
		}
	}
	return answer;
}
main()
{
	int64_bit i,k=0;
	for(i=0,k=1;;i=k*(k*2-1),k++)
	{
		if(is_triangle(i)&&is_penta(i)&&is_hexa(i)&&i>40755)
		{	
			printf("--->%ld\n",i);
			break;
		}			
	}	
}
