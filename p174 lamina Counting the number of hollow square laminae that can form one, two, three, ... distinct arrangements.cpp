#include<stdio.h>
#include<stdlib.h>
#define limit 832
main()
{
	int l,t,tile,ring,sum=0,answer=0;
	int *N=(int*)calloc(limit+1,sizeof(int));
	for(l=3;;l++)
	{
		sum=0;
		tile=4*(l-1);
		for(t=l;t>=3;t-=2)
		{
			ring=4*(t-1);
			
			if(ring+sum>limit) break;
			N[tile-ring]++;	
			sum+=ring;
			answer++;	
		}

		if(sum==0)break;
	}
	printf("%d",N[32]);
}
