#include<stdio.h>
#include<math.h>
int is_prime(int a)
{
	int i,answer=1;
	if(a==0||a==1) answer=0;
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)answer=0;
	}
	return answer;
}
main()
{
	int i,answer=1;
	for(i=2;;i++)
	{
		if(is_prime(i))
		{
			answer*=i;
			if(answer*(i+1)>1000000)break;
		}
	}
	printf("the answer is %d ",answer);
}
