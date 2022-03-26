#include<stdio.h>
#include<conio.h>
int P(int line,int colon)
{
	int answer=0;
	for(int i=1;i<=line;i++)
	{
		for(int j=1;j<=colon;j++)
		{
			answer+=i*j;
		}
	}
	return answer;
}
main()
{
	int max,num,answer;
	for(int i=100;i>=1;i--)
	{
		for(int j=100;j>=1;j--)
		{
			num=P(i,j);
			if(num<2000000)
			{
				if(num>max)
				{
					max=num;
					answer=i*j;
				}
			}
		}
	}
	printf("%d",answer);
}
