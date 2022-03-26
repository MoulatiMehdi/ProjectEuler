#include<stdio.h>
main()
{
	long long max=1000,test;
	long long i,j,k=1,tab[max]={0};
	tab[0]=2;
	printf("%lld\t",tab[0]);
	for(i=3;i<max;i++)
	{
		test=0;
		for(j=0;j<k;j++) if(i%tab[j]==0) test++;	
			 
		
		if(test!=0)  continue;
		tab[k]=i;
		printf("%lld\t",tab[k]);
		k++;	
	}		
}

