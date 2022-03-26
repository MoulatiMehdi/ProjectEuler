#include<stdio.h>
#include<stdlib.h>
int prime[]={2,3,5,7,11,13,17};
int d_nxn(int num)
{
	int answer=1,i=0;
	while(num!=1&&i<7)
	{
		int mul=1;
		while(num%prime[i]==0)
		{
			num/=prime[i];
			mul+=2;
		}
		answer*=mul;
		i++;
	}
	return answer/2;
}
main()
{
	int target=100;
	int *tab=(int*)calloc(510511,sizeof(int));
	for(int i=2;i<=510510;i++)
	{
		if(d_nxn(i)>target)
		{
			printf("%d",i);
			break;
		 } 
	}
	
}
