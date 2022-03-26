#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
long long reverse(long long num)
{
	long long answer=0;
	while(num!=0)
	{
		answer*=10;
		answer+=num%10;
		num/=10;
	}
	return answer;
}
int root_3(long long num)
{
	double n=log10(num)/(double)3;
	
	return pow(10,n);
}

main()
{

	int j,i;
	int target=0,times=0;
	long long p1,answer=0,p2;
	double root_2;
	for(i=3;target<5;i++)
	{
		
		int n=floor(log10(i)+1);
		p1=i*pow(10,n-1)+reverse(i)%(long long)pow(10,n-1);
		p2=i*pow(10,n)+reverse(i);
		times=0;
		
		long long max=root_3(p1);
		for(j=2;j<max&&times<5;j++)
		{
			 root_2=sqrt(p1-pow(j,3));
			if(root_2==(int)root_2)
			{
				times++;
			}
			
		}
		if(times==4)
		{
			answer+=p1; 
			target++;
		}
		
		times=0;
		max=root_3(p2);
		for(j=2;j<max&&times<5;j++)
		{
			 root_2=sqrt(p2-pow(j,3));
			if(root_2==(int)root_2)times++;
		}
		if(times==4)
		{
			answer+=p2;
			target++;
		}
			
	}
	
	printf("-->%d",answer);
}
