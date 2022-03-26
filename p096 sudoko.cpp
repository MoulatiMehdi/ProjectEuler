#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void eliminite(int*tab,int num)
{
	int i,max=0;
	while(tab[max]!=0&&max<10)max++;
	for(i=0;tab[i]!=0;i++)
	{
		if(tab[i]==num)
		{
			tab[i]=tab[max-1];
			tab[max-1]=0;
			max--;
		}
	}
}
is_true(int **tab)
{
	int i,j,answer=1;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(tab[i][j]==0)
			{
				answer=0;
				break;
			}
			
		}
		if(answer==0)break;
	}
	return answer;
}

	void print_grid(int**tab)
{
	int i;
	for(i=0;i<9;i++)
	{
		if(i==0)
		{
			printf("%c",218);
			for(int j=1;j<=9;j++)
			{
			printf("%c",196);
			if(j<9)
			{	
				if((j)%3==0)printf("%c",194);
				else printf("%c",196);
			}
			else printf("%c",191);
			}
			printf("\n");
		}
			for(int j=0;j<9;j++)
		{
			if(j==0) printf("%c",179);
			printf("%d",tab[i][j]);
			if((j+1)%3==0&&j!=0)printf("%c",179);
			else printf(" ");
		}
		printf(" \n");
		if((i+1)%3==0&&i!=8)
		{
			printf("%c",195);
			for(int j=1;j<=9;j++)
			{
				printf("%c",196);
				if(j<9)
				{	
					if((j)%3==0)printf("%c",197);
					else printf("%c",196);
				}
				else printf("%c",180);
			}
			printf("\n");
		}	
	}
	printf("%c",192);
	for(int j=1;j<=9;j++)
	{
		
		printf("%c",196);
		if(j<9)
		{	
			if((j)%3==0)printf("%c",193);
			else printf("%c",196);
		}
		else printf("%c",217);
	}
	printf("\n");
	
}
num_grid(int i,int j)
{
	if(i<3)
	{
		if(j<3) return 0;
		else if(j<6)return 1;
		else return 2;
	}
	else if(i<6)
	{
		if(j<3) return 3;
		else if(j<6)return 4;
		else return 5;
	}
	else 
	{
		if(j<3) return 6;
		else if(j<6)return 7;
		else return 8;
	}
}
is_num_in_row(int**tab,int j,int num)
{
	
	int i,answer=0;
	for(i=0;i<9;i++)
	{
	  if(tab[j][i]==num) 
	  {
	  	answer=1;
		break;
	  }
	}
	return answer;
}
is_num_in_colon(int**tab,int j,int num)
{
	int i,answer=0;
	for(i=0;i<9;i++)
	{
	  if(tab[i][j]==num) 
	  {
	  	answer=1;
		break;
	  }
	}
	return answer;
}
int** cpy_soduko(int **from)
{
	int i,j;
	int**to=(int**)calloc(9,sizeof(int*));
	for(i=0;i<9;i++)
	{
		to[i]=(int*)calloc(9,sizeof(int));
		for(j=0;j<9;j++)
		{
			to[i][j]=from[i][j];
		}
	}
	return to;
}
int***solve(int**grid)
{
	int ***tab;
	int i,j,k,l=0;
	int test,test1;
	int box[9][9];
	int n,m;
	tab=(int***)calloc(9,sizeof(int**));
	for(i=0;i<9;i++)
	{
		tab[i]=(int**)calloc(9,sizeof(int*));
		for(j=0;j<9;j++)
		{
			tab[i][j]=(int*)calloc(9,sizeof(int));
		}
	}
	start:
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			box[i][j]=0;
			for(k=0;k<9;k++)
			{
				tab[i][j][k]=0;
			}
		}
	}
	for(k=0;k<3;k++)
	{
		for(n=0;n<3;n++)
		{
			int o=0;
			for(m=1;m<=9;m++)
			{
				test=0;
				
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(grid[i+3*k][j+3*n]==m) 
						{
							test++;
							break;
						}
					}
					if(test!=0) break;
				}
				if(test!=0) box[k*3+n][o]=m,o++;
			}
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{	
			if(grid[i][j]!=0)for(k=0;k<9;k++)tab[i][j][k]=0;
			else
			{
				l=0;
				for(k=1;k<=9;k++)
				{
					test=is_num_in_row(grid,i,k);
					test1=is_num_in_colon(grid,j,k);
					if(test==test1&&test==0) 
					{
						for(n=0;n<9&&box[num_grid(i,j)][n]!=0;n++)
						{
							if(box[num_grid(i,j)][n]==k)
							{
								test=1;
								break;
							}
						}
						if(test==0)
						{
							tab[i][j][l]=k;
							l++;
						}
					}
				}
				if(l==1)
				{
					grid[i][j]=tab[i][j][0];	
					goto start;
				}
			}
		}
	}
	
	int a=0,b=0,change=0;
	if(!is_true(grid)) 
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=1;k<=9;k++)
				{
					test1=0;
					test=0;
					for(l=0;l<9&&box[num_grid(i*3,j*3)][l]!=0;l++)
					{
						if(box[num_grid(i*3,j*3)][l]==k)
						{
							test1++;
							break;
						} 
					}
					if(test1!=0) continue;
					for(l=0;l<3;l++)
					{
						for(n=0;n<3;n++)
						{
						
							for(m=0;tab[i*3+n][j*3+l][m]!=0&&m<9;m++)
							{
								if(tab[i*3+n][j*3+l][m]==k&&grid[i*3+n][j*3+l]==0)
								{
									a=i*3+n;
									b=j*3+l;
									test++;
								 } 
							}		
						}
					}
					if(test==1) 
					{
						grid[a][b]=k;
						change++;	
					}
				}
			}
		}	
	 	if(!is_true(grid)&&change!=0) goto start;
	 	else
	 	{
	 		for(i=0;i<9;i++)
	 		{
	 			test1=0;
	 			for(j=0;j<9;j++)
	 			{
	 				for(n=j+1;n<9;n++)
	 				{
	 					test1=0;
	 					for(k=0;k<9;k++) if(grid[i][j]==0) test1++;
	 					if(test1>=3)	
	 					if(tab[i][j][0]==tab[i][n][0]&&tab[i][j][0]!=0)
						if(tab[i][j][1]==tab[i][n][1]&&tab[i][j][1]!=0)
						if(tab[i][j][2]==tab[i][n][2]&&tab[i][j][2]==0)
						{
							test=0;
							for(k=0;k<9;k++)
							{
									
								if(k==n||k==j||tab[i][j][1]==0)continue;
								eliminite(tab[i][k],tab[i][j][0]);
								eliminite(tab[i][k],tab[i][j][1]);		
							}
							l=0;
							while(l<9)
							{
								if(l!=j&&l!=n&&grid[i][l]==0)
								{	
									k=0;
									while(tab[i][l][k]!=0) k++;
									if(k==1) 
									{
										grid[i][l]=tab[i][l][0];
										change++;
									}
								}
								
								l++;
							}
						}
						test1=0;		
						for(k=0;k<9;k++) if(grid[j][i]==0) test1++;	
					 	if(test1>=3)	
					 	if(tab[j][i][0]==tab[n][i][0]&&tab[j][i][0]!=0)
					 	if(tab[j][i][1]==tab[n][i][1]&&tab[j][i][1]!=0)
						if(tab[j][i][2]==tab[n][i][2]&&tab[j][i][2]==0)
						{
							test=0;
							for(k=0;k<9;k++)
							{
								if(k==n||k==j||tab[k][i][0]==0)continue;
								eliminite(tab[k][i],tab[j][i][0]);
								eliminite(tab[k][i],tab[j][i][1]);
							}
							l=0;
							while(l<9)
							{
								if(l!=j&&l!=n&&grid[l][i]==0)
								{
										
									k=0;
									while(tab[l][i][k]!=0)k++;
										
									if(k==1) 
									{
										grid[l][i]=tab[l][i][0];
										change++;
									}
								}	
								l++;
							}		
						}
					}
				}	 
			}
		}
	}
	if(change!=0) goto start;
	return tab;
}
main()
{

	int i=0,j=0;
	FILE*file=fopen("p096_sudoku.txt","r");
	char c;
	
	int** tab=(int**)calloc(9,sizeof(int*));
	tab[0]=(int*)calloc(9,sizeof(int));
	while((c=fgetc(file))!=EOF)
	{
		if(c=='\n')
		{
			j=0;
			i++;
			if(i<9)tab[i]=(int*)calloc(9,sizeof(int));
		}
		else
		{
			tab[i][j]=c-'0';
			j++;
		}	
	}
	printf("before solving the puzzle:\n");
	print_grid(tab);
	getch();

	int ***p=NULL;
	int **testing;
	p=solve(tab);
	if(!is_true(tab))
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(p[i][j][0]!=0&&p[i][j][1]!=0)
				{
					testing=cpy_soduko(tab);
					for(int n=0;n<9&&p[i][j][n]!=0;n++)
					{
					
						testing[i][j]=p[i][j][n];
							solve(testing);
						if(is_true(testing))
						{
							tab=cpy_soduko(testing);
							break;	
						} 						
					}
					if(is_true(testing))	break;	
				}
			}
			if(is_true(testing)) break;			
		}
	}
	if(!is_true(tab))
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(p[i][j][0]!=0&&p[i][j][3]==0)
				{
					for(int n=0;n<9&&p[i][j][n]!=0;n++)
					{
						testing=cpy_soduko(tab);
						testing[i][j]=p[i][j][n];
						int***p1=solve(testing);
						for(int m=0;m<9;m++)
						{
							for(int p=0;p<9;p++)
							{
								for(int l=0;l<9&&p1[m][p][l]!=0;l++)
								{
									int**testing1;
									testing1=cpy_soduko(testing);
									testing1[m][p]=p1[m][p][l];
									solve(testing1);
							
								
									if(is_true(testing1))
									{
										tab=cpy_soduko(testing1);
										break;
									}	
								}
								if(is_true(tab)) break;
							}
							if(is_true(tab)) break;
						}
						if(is_true(tab)) break;
					}
					if(is_true(tab)) break;
				}
			}
			if(is_true(tab)) break;
		}
	} 
	printf("the solution : \n");
	print_grid(tab);

}
