#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define limit 64000000
main()
{
	long long *sigma=(long long*)calloc(limit+1,sizeof(long long));
	long long answer=1;
	long  long i,j;
	
	for(i=2;i<=sqrt(limit);i++)
	{
			
			j=i;
			while(j*i<=limit)
			{
				
				sigma[j*i]+=j*j;
				if(i!=j)sigma[j*i]+=i*i;
				j++;
			}

	}
	
	for(i=2;i<=limit;i++)
	{
		sigma[i]+=i*i;
		sigma[i]+=1;
		double long s_root=sqrt(sigma[i]);
		if(s_root==(long long)s_root)answer+=i;
	}
	printf("-->%llu",answer);
}
