#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define limit 1000000
main()
{
	bool*is_square=(bool*)calloc(limit,sizeof(bool));
	
	for(int i=1;i*i<limit;i++)
	{
		is_square[i*i]=true;
	}
	int x,y,z,k;
	int a,b,c;
	
	for( a=3;;a++)
	{
		k=(a%2==0)?2:1;
		for(b=k;b<a;b+=2)
		{
			 x=(a*a+b*b)/2;
			y=(a*a-b*b)/2;
			
			if(x<=y)break;
			for(c=sqrt(x)+1;c;c++)
			{
				z=c*c-x;
				if(y<=z)break;
				
				if(is_square[x-z])
				if(is_square[y-z])
				if(is_square[y+z])
				{
					printf("%d+%d+%d=%d",x,y,z,x+y+z);
					exit(1);
				}
			}
		}
	}

}
