#include<stdio.h>
int gcd(int a,int b)
{
	while(a!=0&&b!=0)
	{
		if(a>b)a%=b;
		else b%=a;
	}
	return a+b;
}
A(int n)
{
	if(gcd(10,n)!=1) return 0;
	int rest=1;
	int p=1;
	while(rest!=0)
	{
		rest=(rest*10+1)%n;
		p++;
	}
	return p;
}
main()
{
	int target=1000000;
	int answer=target+1;
	while(A(answer)<=target)
	{
		answer+=2;
	}
	
	printf("%d",answer);
}
