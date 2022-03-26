#include<stdio.h>
#include<math.h>
#include<conio.h>
#define big_num 10203040506070809
#define int_64bit unsigned long long

int_64bit generate_num(int a)
{
	int i,num;
	int_64bit answer=0;
	for(i=1;i<=15;i+=2)
	{
		num=a%10;
		answer+=num*pow(10,i);
		a/=10;
	}
	answer+=big_num;
	return answer;
	
}
main()
{
	int i;
	int_64bit square_root,num;
	for(i=99999999;;i--)
	{
		num=generate_num(i);
		square_root=sqrt(num);
		if(square_root*square_root==num)
		{
			printf("%lld",square_root*10);
			break;
		}
	}
}
