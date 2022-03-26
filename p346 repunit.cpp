#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define int_64bit unsigned long long

int_64bit base(int_64bit base,int_64bit digit)
{
	int_64bit answer;
	answer=(pow(base,digit+1)-1)/(base-1);
	return answer;
}

main()
{
	int_64bit i,j;
	int_64bit sum=0,num;
	int_64bit max=pow(10,12);
	int_64bit limit=sqrt(max);
	
	int_64bit*answer=(int_64bit*)calloc(limit,sizeof(int_64bit));
	for(i=0;i<limit;i++)answer[i]=0;
	for(i=0;i<41;i++)
	{
		for(j=2;j<=limit;j++)
		{
			num=base(j,i);
			if(num>max)break;			
			if(num<limit)answer[num]++;
			else 
			{
				sum+=num;
			}
			
		}
	}
	for(i=1;i<limit;i++)
	{
		if(answer[i]>1)
		{
			sum+=i;
		 } 
	}
	printf("---->%llu\n",sum);
	
}
