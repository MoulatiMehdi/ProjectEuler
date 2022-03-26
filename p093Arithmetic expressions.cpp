#include<stdio.h>
#include<stdlib.h>
double replace(char c,double a,double b)
{
	double answer=0;
	switch(c)
	{
		
		case '+':answer=a+b;break;
		case '-':answer=a-b;break;
		case '*':answer=a*b;break;
		case '/':answer=a/(double)b;break;		
	}
	return answer;
}
int **generate(int i,int j,int k,int l)
{
	int **tab=(int**)calloc(24,sizeof(int*));
	int n=0;
	for(n=0;n<24;n++)	tab[n]=(int*)calloc(4,sizeof(int));
		
	tab[0][0]=i;
	tab[0][1]=j;
	tab[0][2]=k;
	tab[0][3]=l;
	n=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i==j)continue;
			for(k=0;k<4;k++)
			{
				if(k==j||k==i)continue;
				for(l=0;l<4;l++)
				{
					if(l==j||l==i||l==k) continue;
					tab[n][0]=tab[0][i];
					tab[n][1]=tab[0][j];
					tab[n][2]=tab[0][k];
					tab[n][3]=tab[0][l];
					n++;
		
				}
			}
		}
	}
	return tab;
}
void three_breacket(int*answer,char*string,int i,int j,int k,int l)
{
	double num;
	num=replace(string[0],i,j);
	num=replace(string[1],num,k);
	num=replace(string[2],num,l);
	int a=num;
	if(a>0&&num==a) answer[a]++;
					
	num=0;
	num=replace(string[2],k,l);
	num=replace(string[1],j,num);
	num=replace(string[0],i,num);
	a=num;
	if(a>0&&num==a) answer[a]++;
	

	num=0;
	num=replace(string[1],j,k);
	num=replace(string[0],i,num);
	num=replace(string[2],num,l);
		
	a=num;	
	if(a>0&&num==a) answer[a]++;
	
	num=0;
	num=replace(string[1],j,k);
	num=replace(string[2],num,l);
	num=replace(string[0],i,num);		
	a=num;
	if(a>0&&num==a) answer[a]++;					
}
main()
{
	char A[]="+-*/";
	char string[64][3];
	int i,j,k,l=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				string[l][0]=A[i];
				string[l][1]=A[j];
				string[l][2]=A[k];
				l++;
			}	
		}
	}
	int** num;
	int n,m;
	int* answer;
	int i_max=0;
	for(i=1;i<=6;i++)
	{

		for(j=i+1;j<=7;j++)
		{
			for(k=j+1;k<=8;k++)
			{
				for(l=k+1;l<=9;l++)
				{
					num=generate(i,j,k,l);
					answer=(int*)calloc(64*64*9*9,sizeof(int));
					
					 for(n=0;n<24;n++)
					{
						for(m=0;m<64;m++)
						{
							three_breacket(answer,string[m],num[n][0],num[n][1],num[n][2],num[n][3]);
						}		
					}
					for(n=1;answer[n]!=0;n++);
					
					if(n>i_max)
						{
							i_max=n-1;
							printf("%d%d%d%d(%d)\n",i,j,k,l,i_max);
							
						}
				}
			}
		}
	}
}
