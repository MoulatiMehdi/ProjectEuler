#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int num_digit(int a)
{
	int i=1;
	for(i=1;pow(10,i)<=a;i++)continue;
	return i;
}
int type_gonal(int type,int n)
{
	int num;
	switch(type)
	{
		case 3 : num=(n*(n+1))/2;    break;
		case 4 : num=n*n; 		     break;
		case 5 : num=(n*(3*n-1))/2;  break;
		case 6 : num=n*(2*n-1);      break;
		case 7 : num=(n*(5*n-3))/2;  break;
		case 8 : num=n*(3*n-2);      break;	
	}
	return num;
}
int cycle_nums(int a,int b,int c,int d,int e,int f)
{
	int i,j,max=6;
	int front[max],back[max];
	int tab[max];
	tab[0]=a;
	tab[1]=b;
	tab[2]=c;
	tab[3]=d;
	tab[4]=e;
	tab[5]=f;
	for(i=0;i<max;i++)
	{
		front[i]=tab[i]/100;
		back[i]=tab[i]-front[i]*100;
	}
	int aide,answer=1;
	
	for(i=0;i<max;i++)
	{
		for(j=i+1;j<max;j++)
		{
			if(front[i]>front[j]) 
			{
				aide=front[i];
				front[i]=front[j];
				front[j]=aide;			
			}
			if(back[i]>back[j]) 
			{
				aide=back[i];
				back[i]=back[j];
				back[j]=aide;			
			}
		}
	}
	for(i=0;i<max;i++)
	{
		if(front[i]!=back[i])
		{
			answer=0;
			break;
		}
	}
	return answer;
}
int last_two_digit(int a)
{
	int last;
	last=a/100;
	last=a-last*100;
	return last*100;
}
first_two_digit(int a)
{
	int first;
	first=a/100;
	return first*100;
}
main()
{
	
	int Pk_n[6][100];

	
	int i,j,num,k,l,m,n=0;
	int max[6];
	
	for(j=3;j<=8;j++)
	{
		k=0;
		for(i=1;;i++)
		{
			num=type_gonal(j,i);
			if(num_digit(num)==4)
			{
				Pk_n[j-3][k]=type_gonal(j,i);
				k++;
			}
			else if(num_digit(type_gonal(j,i))>4) break;
		}
		max[j-3]=k;
	}
	
	char tab[]="12345";
	int classe[120][5];
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==j) continue;
			for(k=0;k<5;k++)
			{
				if(i==k||j==k) continue;
				for(l=0;l<5;l++)
				{
					if(i==l||j==l||k==l) continue;
					for(m=0;m<5;m++)
					{
						if(i==m||j==m||k==m||l==m) continue;
						classe[n][0]=tab[i]-'0';
						classe[n][1]=tab[j]-'0';
						classe[n][2]=tab[k]-'0';
						classe[n][3]=tab[l]-'0';
						classe[n][4]=tab[m]-'0';
						n++;
					}
					
				}
			}
		}
	}
	int o,sum;
	for(i=0;i<max[0];i++)
	{
		for(o=0;o<120;o++)
		{

		for(j=0;Pk_n[classe[o][0]][j]<last_two_digit(Pk_n[0][i])+100;j++)
		{
			if(Pk_n[classe[o][0]][j]<last_two_digit(Pk_n[0][i])) continue;
			for(k=0;Pk_n[classe[o][1]][k]<=last_two_digit(Pk_n[classe[o][0]][j])+100;k++)
			{
				if(Pk_n[classe[o][1]][k]<last_two_digit(Pk_n[classe[o][0]][j])) continue;
				
				for(l=0;Pk_n[classe[o][2]][l]<last_two_digit(Pk_n[classe[o][1]][k])+100;l++)
				{
					if(Pk_n[classe[o][2]][l]<last_two_digit(Pk_n[classe[o][1]][k])) continue;
					
					for(m=0;Pk_n[classe[o][3]][m]<last_two_digit(Pk_n[classe[o][2]][l])+100;m++)
					{
						if(Pk_n[classe[o][3]][m]<last_two_digit(Pk_n[classe[o][2]][l])) continue;
						
						for(n=0;Pk_n[classe[o][4]][n]<last_two_digit(Pk_n[classe[o][3]][m])+100;n++)
						{
							if(Pk_n[classe[o][4]][n]<last_two_digit(Pk_n[classe[o][3]][m])) continue;
							
							if(last_two_digit(Pk_n[classe[o][4]][n])==first_two_digit(Pk_n[0][i]))	
							{
								printf("%d,%d,%d,%d,%d,%d\n",Pk_n[0][i],Pk_n[classe[o][0]][j],Pk_n[classe[o][1]][k],Pk_n[classe[o][2]][l],Pk_n[classe[o][3]][m],Pk_n[classe[o][4]][n]);
								sum=Pk_n[0][i]+Pk_n[classe[o][0]][j]+Pk_n[classe[o][1]][k]+Pk_n[classe[o][2]][l]+Pk_n[classe[o][3]][m]+Pk_n[classe[o][4]][n];
								printf(" sum=%d",sum);
								exit(1);
								printf("\n");
							}
						}
						
					}
				}
			}
		}
		}	
	}
	
	
}
