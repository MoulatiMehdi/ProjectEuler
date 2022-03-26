#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
int limit=1500000;
int pgcd(int a, int b){

	while(a != 0 && b != 0)
	{
	
		if(a > b) a = a%b;
		else b = b%a;
	}
	return a+b;
}

main()
{
	int max=(int)sqrt(limit/2);
	int result=0;
	int *triangle=(int*)realloc(0,sizeof(int)*(limit+1));
	
	for(long m=2;m<=max;m++)
	{
	
		for(long n=1;n<m;n++)
		{
			if(pgcd(n,m)==1&&(m+n)%2==1)
			{
				long a=m*m-n*n;
				long b=2*m*n;
				long c=m*m+n*n;
				long p=a+b+c;
				while(p<=limit)
				{
					triangle[p]++;
					if(triangle[p]==1)result++;
					if(triangle[p]==2)result--;
					p+=a+b+c;
				}
	
			}
		}
		
	}
	printf("%d",result);	
}
