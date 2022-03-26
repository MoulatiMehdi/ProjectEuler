#include<stdio.h>
#include<conio.h>
void null_array(int *tab,int max_j)
{
	int j;
	for(j=0;j<max_j;j++)
	tab[j]=0;	
}
main()
{
    int max_j=1000;
	int i=0,j,tab[3][max_j];
	int index=2;
	int test;
	null_array(tab[0],max_j);
	null_array(tab[1],max_j);
	null_array(tab[2],max_j);
	tab[0][0]=1;
	tab[1][0]=1;
	int digit;
	printf("1----->%d\n",tab[0][0]);
	printf("2----->%d\n",tab[1][0]);
	while(digit!=1000)
	{	
		for(j=0;j<max_j;j++)
		{
			tab[2][j]+=tab[1][j]+tab[0][j];	
		for(i=0;i<3;i++)	
			if(tab[i][j]>=10)
			{	
				test=tab[i][j];	
				test/=10;
				tab[i][j+1]+=test;
				tab[i][j]-=10*test;		
			}		
		}
		test=0;
		digit=0;
		for(j=max_j-1;j>=0;j--)
		{
			tab[1][j]=tab[0][j];
			tab[0][j]=tab[2][j];
			tab[2][j]=0;
			
			if(tab[0][j]!=0)test++;
			if(test!=0)
			{
			digit++; 
			}		
		}
		printf("\tthe index %d has %d digits\n",index+1,digit);
		index++;	
	}
}

