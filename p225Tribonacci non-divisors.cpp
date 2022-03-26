#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long *tribo=(long long*)calloc(100,sizeof(long long));
main()
{
	int i,j;
	tribo[0]=1;
	tribo[1]=1;
	tribo[2]=1;
	for(i=3;i<100;i++)
	{
		tribo[i]=tribo[i-1]+tribo[i-2]+tribo[i-3];
		if(floor(log10(tribo[i])+1)==19)break;
	}
	int max=i+1;
	int k=0;
	for(i=3;k<124;i+=2)
	{
		int test=1;
		for(j=0;j<max;j++)
		{
			if(tribo[j]%i==0)
			{
				test=0;
				break;
			}
		}
		if(test==1) printf("%d-->%d\n",k+1,i),k++;
	}
}
