#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int num_digit(int a)
{
	int i=1;
	for(i=1;pow(10,i)<=a;i++) continue;
	return i;
}

int is_prime(int a)
{
	int i,answer=0;
	
	if(a==0||a==1) answer=1;
	else
    for(i=2;i<=sqrt(a);i++) 
	{
		if(a%i==0) 
		{
			answer++;
			break;
		}
	}
	if(answer!=0) answer=0;
	else answer=1;
	
	return answer;
}
int*split_number(int *tab,int a)
{
	
	int i,num=a,max=num_digit(a);
	
	tab=(int*)malloc(sizeof(int)*max);
		for(i=0;i<max;i++)
	{
		tab[i]=num/pow(10,max-i-1);
		num-=tab[i]*pow(10,max-i-1);
	}
	return tab;
}

main()
{
	int *tab,i,j,k,l,n,m,max,chaine=0;
	int num,max_prime=0,max_num,smallest_prime;
	
	
	for(i=100000;i<1000000;i++)
	{
		max=num_digit(i);
		for(j=0;j<max-2;j++)
		{
			for(k=j+1;k<max-1;k++)
			{
				for(m=k+1;m<max;m++)
				{
				
				chaine=0;
				for(l=0;l<10;l++)
				{
					tab=split_number(tab,i);
					num=0;
					tab[m]=l;
					tab[k]=l;
					tab[j]=l;
					
					for(n=0;n<max;n++) num+=tab[n]*pow(10,max-n-1);	
					if(chaine==0) smallest_prime=num;
					if(is_prime(num)&&tab[0]!=0)
						{
							chaine++;
					 	} 	
				}
				if(chaine>max_prime)
					{
					max_prime=chaine;
					max_num=smallest_prime;
					}
					if(max_prime>=8)break;
				}
				if(max_prime>=8)break;
			}
			if(max_prime>=8)break;		
		}
		if(max_prime>=8)break;
	}
	printf("number of chaine is %d the smallest prime :%d",max_prime,max_num);
	printf("\n_____________________________________________________\n");

}
