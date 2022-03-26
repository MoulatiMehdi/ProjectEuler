#include<stdio.h>
#include<math.h>
is_prime(int a)
{
	int i,answer=1;
	if((a%2==0&&a!=2)||a<2) answer=0;
	for(i=3;i<=sqrt(a);i+=2)
	{
		if(a%i==0)
		{
			answer=0;
			break;
		}
	}
	return answer;
}
main()
{
	int max=100,i,j;
	int ways[max+1]={0};
	ways[0]=1;
	for (i=1;i<max;i++) 
	{
		if(!is_prime(i))continue;
    	for (j=i;j<=max;j++)
    		ways[j]+=ways[j-i];
    		if(ways[i]>5000) break;
	}
	printf("%d",i);
}
