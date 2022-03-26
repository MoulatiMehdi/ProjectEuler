#include<stdio.h>
#include<stdlib.h>
is_connect(int **tab)
{
	int test=0;
	for(int j=0;j<40;j++)
	{
		test=0;
		for(int i=0;i<40;i++)
		{
			if(tab[j][i]!=0)test++;
		}
		if(test<=2) 
		{
			test=0;
			
			break; 
		}
	}
	return test;
	
}
main()
{
	int** network=(int**)calloc(40,sizeof(int*));
	FILE* file=fopen("p107_network.txt","r");
	char c;
	int i=0,j=0;
	network[0]=(int*)calloc(40,sizeof(int));
	int all;
	while((c=fgetc(file))!=EOF)
	{
		if(c=='-')
		{

		}
		else if(c==',')
		{
			all+=network[i][j];
			j++;	
		}
		else if(c=='\n')
		{
			all+=network[i][j];
			j=0;
			i++;
			network[i]=(int*)calloc(40,sizeof(int));
		}
		else
		{
			network[i][j]*=10;
			network[i][j]+=c-'0';
		}
	 } 
	 int max,a,b;
	 
	 
	while(is_connect(network)!=0) 
	{
		
		max=0;
		
		for(i=0;i<40;i++)
		{
	 		for(j=0;j<40;j++)
	 		{
			 	if(network[i][j]>max)
				 {
				 	max=network[i][j];
				 	a=i;
				 	b=j;
				 }	
			}
		}
		network[a][b]=0;
		network[b][a]=0;
	}
	
	max=0;
	int sum=0;
	for(i=0;i<40;i++)
	{
		for(j=0;j<40;j++)
		{
			if(network[i][j]!=0) max++,sum+=network[i][j],printf("%d %d\n",i,j);
		}
	}
	
	 printf("\n-->%d(%d ->%d)",max,all,sum);
}
