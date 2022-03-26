#include<stdio.h>
main()
{
	int i,j,k,num,sum=0,max=0;
	int tab[98][200]={0};
	for(i=0;i<98;i++)
	{
		num=i+2;
		tab[i][2]=num/100;
		tab[i][1]=(num-tab[i][2]*100)/10;
		tab[i][0]=num-tab[i][2]*100-tab[i][1]*10;	
	}
	for(i=0;i<98;i++)
	{
		for(k=2;k<100;k++)
		{
			sum=0;
			for(j=0;j<200;j++)
			{
				tab[i][j]*=i+2;
				if(tab[i][j-1]>=10&&j!=0)
				{
					num=tab[i][j-1]/10;
					tab[i][j]+=num;
					tab[i][j-1]-=num*10;	
				}
				if(j!=0)sum+=tab[i][j-1];
			}
			if(sum>max)max=sum;			
		}
	}	
	printf("max power digits sum is %d",max);	
}
