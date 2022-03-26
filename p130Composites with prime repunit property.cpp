#include<stdio.h>
#include<stdlib.h>
#include<math.h>

A(int n)
{
	int rest=1;
	int p=1;
	while(rest!=0)
	{
		rest=(rest*10+1)%n;
		p++;
	}
	return p;
}

main()
{
	int limit=100000;
	int *T=(int*)calloc(limit,sizeof(int));
	int i,j=0;
	int answer=0,l=0;
	for(i=2;i<=sqrt(limit);i++)
	{
		if(!T[i])
		{
			j=i;
			while(i*j<limit)
			{
				T[i*j]=1;
				j++;		
			}
		}
	}
	
	
	
	for(i=7;i<limit;i+=2)
	{
		if(i%5==0)continue;
		if(T[i])
		{
			int n=A(i);
			if((i-1)%n==0)
			{
				answer+=i;
				l++;
				printf("%d-->A(%d)=%d\n",l,i,n);
				if(l>=25)break;
			}
		}
	}

	printf("%d",answer);
}
