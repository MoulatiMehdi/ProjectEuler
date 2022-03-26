#include<stdio.h>
#include<math.h>
main()
{
	int i,j,k=0,n,num,test,p;
	int max=0,m=0;
	int tab[10];
	for(m=2;m<=1000;m++)
	{
		k=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
				{
					num=i*i+j*j;
					test=0;
					if(sqrt(num)+i+j==m)
					{
						for(n=0;n<=k;n++) if(sqrt(num)==tab[n]) test++;
						if(test!=0) continue;
						else
						{
							tab[k]=sqrt(num);
							k++;
						}
					}
					else continue;	
				}
			}
		if(max<k)
		{
			max=k;
			p=m;
		}	
	}
printf("p=%d----> max=%d\n",p,max);
}
