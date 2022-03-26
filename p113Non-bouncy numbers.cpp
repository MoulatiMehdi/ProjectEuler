#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define int_big unsigned long long
int_big C(int n,int k)//n>=k
{
	double answer=1;
	while(k!=0)
	{
		answer*=n;
		answer/=k;
		n--;
		k--;
	}
	return (int_big)ceil(answer);
}
int_big no_bouncy(int n)//number of not_bouncy_number below 10^n
{
	int_big answer=1;
	
	answer=C(n+9,9)-1;//number of incresing digit
	answer+=C(n+10,10)-1-n;//number of decresing
	answer-=9*n;//delete the repetition
	
	return answer;//final answer
}
main()
{
	
	printf("%lld",no_bouncy(100));
}
