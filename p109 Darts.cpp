#include<stdio.h>
#include<stdlib.h>
#define limit 21
int S[22];
int D[22];
int T[21];
typedef struct
{
	char name;
	int num;
}Darts;
int score(int max)
{
	Darts **tab=(Darts**)calloc(max*max,sizeof(Darts*));
	int l=0,i,j,k;
	for(i=1;i<=limit&&i<=max/2;i++)
	{
		if(D[i]==max)
		{
			tab[l]=(Darts*)calloc(3,sizeof(Darts));
			tab[l][0].name='D';
			tab[l][0].num=i;
			l++;
		}
		for(j=1;j<=limit&&j<=max;j++)
		{
			if(D[i]+S[j]==max)
			{
				tab[l]=(Darts*)calloc(3,sizeof(Darts));
				tab[l][0].name='D';
				tab[l][0].num=i;
				tab[l][1].name='S';
				tab[l][1].num=j;
				l++;
			}
			if(D[i]+D[j]==max)
			{
				tab[l]=(Darts*)calloc(3,sizeof(Darts));
				tab[l][0].name='D';
				tab[l][0].num=i;
				tab[l][1].name='D';
				tab[l][1].num=j;
				l++;
			}
			if(j!=limit&&D[i]+T[j]==max)
			{
				tab[l]=(Darts*)calloc(3,sizeof(Darts));
				tab[l][0].name='D';
				tab[l][0].num=i;
				tab[l][1].name='T';
				tab[l][1].num=j;
				
				l++;
			}
			
			for(k=1;k<=limit&&k<=max;k++)
			{
				
				if(D[i]+S[j]+S[k]==max)
				{
					tab[l]=(Darts*)calloc(3,sizeof(Darts));
					tab[l][0].name='D';
					tab[l][0].num=i;
					tab[l][1].name='S';
					tab[l][1].num=j;
					tab[l][2].name='S';
					tab[l][2].num=k;
					l++;
				}
			
				if(k!=limit&&D[i]+S[j]+T[k]==max)
				{
					tab[l]=(Darts*)calloc(3,sizeof(Darts));
					tab[l][0].name='D';
					tab[l][0].num=i;
					tab[l][1].name='S';
					tab[l][1].num=j;
					tab[l][2].name='T';
					tab[l][2].num=k;
					l++;
				}
				if(D[i]+D[j]+S[k]==max)
				{
					tab[l]=(Darts*)calloc(3,sizeof(Darts));
					tab[l][0].name='D';
					tab[l][0].num=i;
					tab[l][1].name='D';
					tab[l][1].num=j;
					tab[l][2].name='S';
					tab[l][2].num=k;
					l++;
				}
				if(D[i]+D[j]+D[k]==max)
				{
					tab[l]=(Darts*)calloc(3,sizeof(Darts));
					tab[l][0].name='D';
					tab[l][0].num=i;
					tab[l][1].name='D';
					tab[l][1].num=j;
					tab[l][2].name='D';
					tab[l][2].num=k;
					l++;
				}
				if(k!=limit&&D[i]+D[j]+T[k]==max)
				{
					tab[l]=(Darts*)calloc(3,sizeof(Darts));
					tab[l][0].name='D';
					tab[l][0].num=i;
					tab[l][1].name='D';
					tab[l][1].num=j;
					tab[l][2].name='T';
					tab[l][2].num=k;
					l++;
				}
				
				
				if(k!=limit&&j!=limit&&D[i]+T[j]+T[k]==max)
				{
					
					tab[l]=(Darts*)calloc(3,sizeof(Darts));
					tab[l][0].name='D';
					tab[l][0].num=i;
					tab[l][1].name='T';
					tab[l][1].num=j;
					tab[l][2].name='T';
					tab[l][2].num=k;
					l++;
				}
			
			}
		}
	}
	int score=0;
	for(i=0;i<l;i++)
	{
		if(tab[i][0].num==0)continue;
		for(j=i+1;j<l;j++)
		{
			if(tab[i][0].num!=tab[j][0].num||tab[i][2].num==0)continue;
			
			if(tab[i][1].num==tab[j][2].num)
			if(tab[i][1].name==tab[j][2].name)
			if(tab[j][1].num==tab[i][2].num)
			if(tab[j][1].name==tab[i][2].name)
			{
				tab[j][0].num=0;
				tab[j][1].num=0;
				tab[j][2].num=0;
			}		
		}
		score++;
	}
	return score;
}
main()
{
	int i;
	int target=100;
	for(i=0;i<21;i++)
	{
		S[i]=i;
		D[i]=i*2;
		T[i]=i*3;
	}
	S[21]=25;
	D[21]=50;
	int sum=0;
	
	for(i=0;i<target;i++)
	{
		sum+=score(i);
	}	
	
	printf("%d",sum);
}
