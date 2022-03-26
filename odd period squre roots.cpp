#include<stdio.h>
#include<math.h>
#include<conio.h>
#define int_64bit unsigned long long
main()
{
	
	int_64bit i,j,answer;
	int_64bit diophan;
	int_64bit n;
	int_64bit max=0;
	int test;
	
	for(i=2;i<=1000;i++)
	{
		
		n=sqrt(i);
		if(n*n==i)continue;
		test=0;
		for(j=1;j<sqrt(2*pow(2,63)/i);j++)
		{
			
			n=sqrt(i*pow(j,2)+1);
			if(n*n==i*pow(j,2)+1)
			{
				printf("%d:%llu^2-%d*%llu^2=1\n",i,n,i,j);
				getch();
				if(max<n)
				{
					max=n;
					answer=i;
				}
				break;
			}
		}		
	}
	printf("%d",answer);
}
