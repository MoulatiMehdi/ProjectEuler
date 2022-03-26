#include<stdio.h>
main()
{
	int  max1=4*4*4*4*4*4*4*4*4,max2=6*6*6*6*6*6;
	int  i,j,k,l,m,n,o,p,q;
	int  r=0;
	
	int peter_dice[max1]={0};
	int colin_dice[max2]={0};
	for(i=1;i<=4;i++)//dice 1
	for(j=1;j<=4;j++)//dice 2
	for(k=1;k<=4;k++)//dice 3		
	for(l=1;l<=4;l++)//dice 4
	for(m=1;m<=4;m++)//dice 5
	for(n=1;n<=4;n++)//dice 6
	for(o=1;o<=4;o++)//dice 7
	for(p=1;p<=4;p++)//dice 8
	for(q=1;q<=4;q++)//dice 9
	{
		peter_dice[r]=i+j+k+l+m+n+o+p+q;
		r++;
	}
	
	max1=r;
	r=0;

	for(i=1;i<=6;i++)//dice 1
	for(j=1;j<=6;j++)//dice 2
	for(k=1;k<=6;k++)//dice 3		
	for(l=1;l<=6;l++)//dice 4
	for(m=1;m<=6;m++)//dice 5
	for(n=1;n<=6;n++)//dice 6
	{
		colin_dice[r]=i+j+k+l+m+n;
		r++;
	}
	max2=r;
	long long  peter_wins=0;
	for(i=0;i<max1;i++)
	{
		for(j=0;j<max2;j++)
		{
			if(colin_dice[j]<peter_dice[i]) peter_wins++;
		}
	}
	printf("number of wins for peter:%lld\n",peter_wins);
	printf("number of rolls :%lld\n",max1*max2);
	printf("the answer is  ---->%0.7f",peter_wins/((float) max1*(float)max2));
}
