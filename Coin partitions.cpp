#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define int_64bit unsigned long long
main()
{
	int i,j,k,num;
	int max=56000;
	int max_digit=6;
	int**ways=NULL;
	ways=(int**)malloc(sizeof(int*)*(max+1));
	
	for(i=0;i<max+1;i++)
	{
		ways[i]=(int*)malloc(sizeof(int)*max_digit);
		for(j=0;j<max_digit;j++)
		ways[i][j]=0;
	}
	ways[0][0]=1;
	
	
	for(i=1;i<max;i++)
	{
		for(j=i;j<=max;j++)
		{
			for(k=0;k<max_digit;k++)
			{
				ways[j][k]+=ways[j-i][k];
				if(ways[j][k]>=10)
				{
					num=ways[j][k]/10;
					ways[j][k+1]+=num;
					ways[j][k]-=num*10;
				}
			}
			
		}
		num=0;
		for(j=0;j<max_digit;j++)
		{
			if(ways[i][j]==0) num++;
			else break;
			if(num>=6)
			{
				printf("-->%d",i);
				exit(1);
			 } 
		}
	}
		
	
}
