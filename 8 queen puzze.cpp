#include<stdio.h>
#include<stdlib.h>
void queen_move(char **tab,int line,int colon)
{
	int s_i=line,s_j=colon;//diagonale start
	int a=line,b=colon;//anti_diagonal start
	if(s_i>s_j)
	{
		s_i-=s_j;
		s_j=0;
	}
	else
	{
		s_j-=s_i;
		s_i=0;
	} 
	
	if(tab[line][colon]=='0')
	{
		for(int i=0;i<8;i++)
		{
			if(a>0&&b<8)b++,a--;
    		if(tab[i][colon]=='0')tab[i][colon]='1';
			if(tab[line][i]=='0')tab[line][i]='1';
		}
		while(s_i<8&&s_j<8)
		{
			tab[s_i][s_j]='1';
			s_i++;
			s_j++;
		}
		while(a<8&&b>=0)
		{
			tab[a][b]='1';
			a++;
			b--;
		}
		tab[line][colon]='2';//queen location
	}
}
char** clear_board()
{
	char **tab;
	
	tab=(char**)calloc(8,sizeof(char*));
	for(int i=0;i<8;i++)
	{
		tab[i]=(char*)calloc(8,sizeof(char));
		for(int j=0;j<8;j++)
		{
			tab[i][j]='0';
		}
	}
	return tab;
}
void cpy_board(char** to,char** from)
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			to[i][j]=from[i][j];
		}
	}
}

is_8_queen(char**tab)
{
	int answer=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(tab[i][j]=='2') answer++;	
		}
	}
	 return answer;
}
main()
{
	int i,j,k,l,m,n,o,p;
	char ***test;
	int answer=0;
	
	test=(char***)calloc(8,sizeof(char**));
	for(i=0;i<8;i++)
	{
		test[i]=clear_board();
	}
	
	for(i=0;i<8;i++)//row 1 colon i
	{
		test[0]=clear_board();
		queen_move(test[0],0,i);
		for(j=0;j<8;j++)//row 2 colon j
		{
			if(test[0][1][j]!='0')continue;
			cpy_board(test[1],test[0]);
			queen_move(test[1],1,j);
			for(k=0;k<8;k++)//row 3 colon k
			{
				if(test[1][2][k]!='0')continue;
				cpy_board(test[2],test[1]);
				queen_move(test[2],2,k);
				for(l=0;l<8;l++)//row4 colon l
				{
					if(test[2][3][l]!='0')continue;
					cpy_board(test[3],test[2]);
					queen_move(test[3],3,l);
					for(m=0;m<8;m++)//row 5 colon m
					{
						if(test[3][4][m]!='0')continue;
						
						cpy_board(test[4],test[3]);
						queen_move(test[4],4,m);
						for(n=0;n<8;n++)//row 6 colon n
						{
							if(test[4][5][n]!='0')continue;
							
							cpy_board(test[5],test[4]);
							queen_move(test[5],5,n);
							for(o=0;o<8;o++)//row 7 colon o
							{
								if(test[5][6][o]!='0')continue;
								cpy_board(test[6],test[5]);
								queen_move(test[6],6,o);
								for(p=0;p<8;p++)//row 8 colon p
								{
									if(test[6][7][p]!='0')continue;
									cpy_board(test[7],test[6]);
									queen_move(test[7],7,p);
									if(is_8_queen(test[7])==8)answer++;
								}
								
							}
						}
					}
				}
			}
		}
	}
	
	printf("there is : %d",answer);
	printf(" probabilities to have eight queen in the board");
	printf("\n\t   without eating each other\n");
}
