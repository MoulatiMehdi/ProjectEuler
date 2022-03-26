#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
A(int num)
{
	int rest=1;
	int k=1;
	while(rest!=0)
	{
		rest=(rest*10+1)%num;
		k++;
	}
	return k;
}
main()
{
	int limit=1000000;
	long long target=pow(10,9);
	int *T=(int*)calloc(limit,sizeof(int));
	int i,j;
	for(i=3;i<=sqrt(limit);i+=2)
	{
		if(!T[i])
		{
			 j=i;
			while(j*i<limit)
			{
				T[i*j]=1;
				j++;
			}
		}
	}
	T[5]=1;
	j=0;
	long long num=1;
	for(int i=3;j<40;i+=2)
	{
		if(T[i])continue;
		int n=A(i);
		if(target%n==0&&n<=target)
		{
				
				num+=i;
				printf("%d :%d-->%d(%lld)\n",j+1,i,n,num);
				j++;
		}
		
	}
	printf("%lld",num);
	
}
