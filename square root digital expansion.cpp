#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int* multiplay_tab(int*a,int num)
{
	int i,help=0;
	int* answer=(int*)calloc(102,sizeof(int));
	for(i=0;i<102;i++)
	{
		answer[i]=a[i]*num;
		if(answer[i-1]>=10&&i>0)
		{
			help=answer[i-1]/10;
			answer[i-1]-=help*10;
			answer[i]+=help;	
		}
	}
	return answer;
}
int is_greater(int*big,int*small)
{
	int answer=1;
	for(int i=101;i>=0;i--)
	{
		if(small[i]>big[i])
		{
			answer=0;
			 break;
		}
		else if(small[i]<big[i])
		{
			answer=1;
			break;
		}
		else continue;
	}
	return answer;
}
void sum(int*tab1,int num)
{
	tab1[0]+=num;
	int i=0;
	while(i<=101)
	{	
		if(tab1[i]>=10)
		{
			num=tab1[i]/10;
			tab1[i]-=num*10;
			tab1[i+1]+=num;
		}
		i++;
	}
	
}
int *diff(int*greater,int*lowest)
{
	int*answer=(int*)calloc(102,sizeof(int));
	for(int i=0;i<102;i++)
	{
		
		answer[i]+=greater[i]-lowest[i];
		if(answer[i]<0)
		{
			answer[i]+=10;
			answer[i+1]--;
		}
	}
	return answer;
}
void print_tab(int*tab)
{
	int test=0;
	for(int i=101;i>=0;i--)
	{
		if(tab[i]!=0||test!=0)test++;
		if(test!=0)printf("%d",tab[i]);
	}
	printf("-->%d digit",test);
}
int*squre_root(int num,int max)
{
	int*b=(int*)calloc(102,sizeof(int));
	int*a=(int*)calloc(102,sizeof(int));
	a[0]=num;
	a=multiplay_tab(a,5);
	b[0]=5;
	int j=0;
	while( j!=max)
	{	
		if(is_greater(a,b))
		{
			a=diff(a,b);
			sum(b,10);
		}
		else
		{
			a=multiplay_tab(a,100);
			b=multiplay_tab(b,10);
			b[1]=0;
			b[0]=5;
			j++;
		}	
	}
	return b;
}
main()
{
	int *answer;
	int sum=0;
	int i,j,k=0;
	for(i=2;i<=100;i++)
	{
		j=sqrt(i);
		if(i==j*j) continue;
		answer=squre_root(i,100);		
		for(j=101,k=0;k<100;j--,k++) sum+=answer[j];

	}
	printf("%lld",sum);
}
