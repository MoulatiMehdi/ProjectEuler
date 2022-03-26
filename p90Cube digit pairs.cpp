#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
check_tab(int *tab,int *tab1)
{
	int i,j;
	int answer=1;
	int test[10]={0};
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			int num=tab[i]*10+tab1[j];
			int s_num=sqrt(num);
			if(num==s_num*s_num)
			{
				test[s_num]=1;
			 } 
			
			num=tab[i]+tab1[j]*10;
			s_num=sqrt(num);
			if(num==s_num*s_num) 
			{
				test[s_num]=1;
			}
		}
	}
	
	for(i=1;i<10;i++)
	{
		if(test[i]!=1)
		{
			answer=0;
			break;
		}
	}
	return answer;
}
test(int *tab1,int*tab)
{
	int answer=0;
	for(int i=0;i<12;i++)
	{
		for(int j=i;j<12;j++)
		{
			if(tab[i]==tab[j])
			{
				answer++;
				break;
			}
		}
	}
	if(answer==12) return 1;
	else return 0;
}
main()
{
	int i,j,k,l,n,m;
	int o=0;
	
	int **tab=(int**)calloc(pow(10,6),sizeof(int*));
	int **tab1=(int**)calloc(pow(10,6),sizeof(int*));
	int **answer=(int**)calloc(pow(10,6),sizeof(int*));
	
		
	
		for(l=0;l<10;l++)
		{
			if(l==0||l==8||l==2)continue;
			for(m=0;m<10;m++)
			{
				if(m==0||m==8||m==2)continue;
				for(n=0;n<10;n++)
				{
					if(n==0||n==8||n==2)continue;
					tab[o]=(int*)calloc(6,sizeof(int));
					tab[o][0]=0;
					tab[o][1]=8;
					tab[o][2]=2;
					tab[o][3]=l;
					tab[o][4]=m;
					tab[o][5]=n;
					o++;	
				}
			}
		}
	
	int max=o;
	o=0;

		for(l=0;l<10;l++)
		{
			if(l==1||l==4||l==5)continue;
			for(m=0;m<10;m++)
			{
				if(m==1||m==4||m==5||l==m)continue;
				for(n=0;n<10;n++)
				{
					if(n==1||n==4||n==5||n==m||n==l)continue;
					tab1[o]=(int*)calloc(6,sizeof(int));
					tab1[o][0]=1;
					tab1[o][1]=4;
					tab1[o][2]=5;
					tab1[o][3]=l;
					tab1[o][4]=m;
					tab1[o][5]=n;
					o++;	
				}
			}
		}
	

	int max1=o;
	o=0;
	for(i=0;i<max;i++)
	{
		for(j=0;j<max1;j++)
		{
			if(check_tab(tab[i],tab1[j]))
			{
				answer[o]=(int*)calloc(12,sizeof(int));
				for(k=0;k<6;k++)
				{
					
					answer[o][k]=tab[i][k];
					answer[o][k+6]=tab1[j][k];
				}
				o++;
			}
		}
	}
	printf("%d\n",o);
	max=o;
	o=0;
	for(i=0;i<max;i++)
	{
		if(answer[i][0]==answer[i][1]&&answer[i][0]==0) continue;
		for(j=i+1;j<max;j++)
		{
			if(answer[j][0]==answer[j][1]&&answer[j][0]==0) continue;
			if(test(answer[i],answer[j]))
			{
				for(k=0;k<12;k++)
				{
					answer[j][k]=0;
				}
				
			}
		}
		o++;
	}
	printf("%d",o);
}
