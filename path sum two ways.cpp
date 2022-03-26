#include<stdio.h>
#include<stdlib.h>
int min_sum_path(int **tab, int max)
{
	int i, j;

	/* Replace each tabatrix eletabent with tabinitabutab sutab to get there */
	for (i=1;i<max;i++) 
	{
		tab[i][0]+=tab[i-1][0];
		tab[0][i]+=tab[0][i-1];
	}
	for (i=1;i<max;i++)
	 {
		for(j=1;j<max;j++)
		 {
			int num1=tab[i-1][j];
			int num2=tab[i][j-1];
			tab[i][j]+=((num1<num2)?num1:num2);
		}
	}
	return tab[max-1][max-1];
}
main()
{
	int i=0,j=0;
	int **M=(int**)calloc(80,sizeof(int*));
	char c;
	
	FILE* file=NULL;
	file=fopen("p081_matrix.txt","r");
	M[0]=(int*)calloc(80,sizeof(int));
	while((c=fgetc(file))!=EOF)
	{
		if(c=='\n')
		{
			
			i++;
			M[i]=(int*)calloc(80,sizeof(int));
			j=0;		
		}
		else if(c==',') j++;
		else
		{
			M[i][j]*=10;
			M[i][j]+=c-'0';
		}	
	}
	printf("the answer is :%d",min_sum_path(M,80));
}
