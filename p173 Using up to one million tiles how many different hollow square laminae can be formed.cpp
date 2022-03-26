#include<stdio.h>
#include<stdlib.h>
#define limit 1000000
main()
{

	int ring,n_tiles,n_ring=0;
	int i,j;
	for(i=3;;i++)
	{
		n_tiles=0;
		for(j=i;j>=3;j-=2)
		{
			ring=4*(j-1);
			if(n_tiles+ring>limit)break;
			
			n_tiles+=ring;
			n_ring++;
		}
		if(n_tiles==0)break;
	}
	printf("%d",n_ring);
	
}
