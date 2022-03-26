#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int is_prime(int num)
{
	int answer=1;
	if(num<=1) answer=0;
	else if(num<4) answer=1;
	else if(num%2==0)answer=0;
	else if( num%3==0) answer=0;
	else 
	{
		for(int i=5;i<=sqrt(num);i+=6)
		{
			if(num%i==0||num%(i+2)==0) answer=0;
		}
	}
	return answer;
}
main()
{
	int limit=50000000;
	int j=0,i,k,sum=0;
	
	int prime[1000];
	int*answer=(int*)calloc(limit+1,sizeof(int));
	long long num;
	
	
	
	for(i=2;i<=sqrt(limit);i++) if(is_prime(i)) prime[j]=i,j++;

	int max_prime=j;
	for(i=0;i<max_prime;i++)
	for(j=0;prime[j]<368;j++)
	for(k=0;prime[k]<84;k++)4 
	{
		num=pow(prime[i],2)+pow(prime[j],3)+pow(prime[k],4);
		if(num>=limit) break;
		
		answer[num]++;
		if(answer[num]==1)sum++;
	}
	printf("%d",sum);
	
}
