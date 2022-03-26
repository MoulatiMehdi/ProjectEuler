#include<stdio.h>
#include<math.h>
int is_prime(int a)
{
	int i,answer=1;
	if(a>1)
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			answer=0;
			break;
		}
	}
	else answer=0;
	return answer;
}
main()
{
	int i,j=2,k=3,diagonal=1,prime;
	float result=1;
	for(i=3;;i+=j)
	{
		diagonal++;
		if(is_prime(i)) prime++;
		if(k*k==i)
		{
			j+=2;
			result=prime/float(diagonal);
			if(result<0.1) break;
			k=k+2;
		}	
	}
	printf("\nsize =%d ",k);
}
