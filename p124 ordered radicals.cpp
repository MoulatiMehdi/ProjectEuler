#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
int *prime=(int*)calloc(10000,sizeof(int));//(prime)^n
is_prime(int num)
{
	int answer=1;
	if(num<=1)answer=0;
	else if(num<4)answer=1;
	else if(num%2==0)answer=0;
	else if(num%3==0)answer=0;
	else
	{
		for(int i=5;i<=sqrt(num);i++)
		{
			if(num%i==0||num%(i+2)==0)
			{
				answer=0;
				break;
			}
		}
	}
	return answer;
}

main()
{
	int max=100000,find=10000;
	
	
	int*E=(int*)calloc(max+1,sizeof(int));
	int *rad_num=(int*)calloc(max+1,sizeof(int));
	int i,j=0;
	
	E[1]=1;
	rad_num[1]=1;
	for(i=2;i<=max;i++)
	{
		E[i]=i;
		if(is_prime(i))
		{
			for(j=i;j<=max;j+=i)
			{
				if(rad_num[j]==0)rad_num[j]=1;
				rad_num[j]*=i;
			}
		 }  
	}
	int answer=1;
	for(int i=2;;i++)
	{
		for( j=2;j<=max;j++)
		{
		 	if(rad_num[j]==i) answer++;
		 	if(answer==find)break;
		}
		if(answer==find)break;
	}
	printf("k=%d---> E(k)=%d rad(n)=%d\n",find,E[j],rad_num[j]);
}
