#include<stdio.h>
#include<math.h>
int num_digit(int a)
//number of digits
{
	int i=1;
	for(i=1;pow(10,i)<=a;i++) continue;
	return i;
}
main()
{
	int i,j,k=0,l=0,divide,num;
	int i_digit;
	int tab[9];
	int answer[9];
	int test1;
	for(i=1;i<10000;i++)
	{
		i_digit=0;
		k=0;
		for(j=1;i_digit<9;j++)
		{
			num=i*j;
			i_digit+=num_digit(num);
			divide=num;
			for(l=0;l<num_digit(num);l++)
			{
				tab[l+k]=divide/pow(10,num_digit(num)-1-l);
				divide-=tab[l+k]*pow(10,num_digit(num)-1-l);
			}
				k+=num_digit(num);
		}
		test1=0;
		for(k=0;k<9;k++)
		{	
			for(l=0;l<9;l++)
			{
				if(l==k)continue;
				if(tab[k]==tab[l]||tab[k]==0) test1++;
			}
		}
		if(i_digit==9&&j>1&&test1==0)
		{
			for(l=0;l<9;l++)
			{
				answer[l]=tab[l];
			}
		}	
	}
		for(i=0;i<9;i++) printf("%d",answer[i]);
		
}
