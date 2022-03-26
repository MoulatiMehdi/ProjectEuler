#include<stdio.h>
#include<math.h>
int is_prime(int num)
{
	int i,answer=1;
	if(num%2==0) answer=0;
	else 
	for(i=3;i<=sqrt(num),i+=2)
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
	
	
}
