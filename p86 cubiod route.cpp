#include<stdio.h>
#include<math.h>
int solve(int a,int b)
{
	int d;	
	d=sqrt(a*a+b*b);
	if(d*d==a*a+b*b) return 1;
	else return 0;
}

main()
{	
	int limit=pow(10,6);
	
	int sum_solution=0;
	int M,j;
	for(M=0;;M++)
	{
		for(j=1;j<=M*2;j++)
		{
			if(solve(M,j))
			{
				if(M>=j)sum_solution+= j/2;
				else    sum_solution+=(M-(j+1)/2)+1;
	
			}
			if(sum_solution>limit) break;
		}
		if(sum_solution>limit) break;
	}
	printf("-->%d(sum=%d)",M,sum_solution);
}
