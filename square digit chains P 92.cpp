#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int digit_square(int i)
{
	int answer=0,last_digit;
	for(;i>0;)
	{
		last_digit=i%10;
		answer+=last_digit*last_digit;
		i/=10;	
	}
	return answer;
}
main()
{
	int max=0,num;
	int i;
	int *tab=(int*)calloc(10000000,sizeof(int));
	for( i=2;i<10000000;i++)
	{
		num=digit_square(i);
		tab[num]++;
	}
	for(i=1;i<=digit_square(9999999);i++)
	{
		if(tab[i]==0)continue;
		num=i;
		while(num!=89&&num!=1)
		{
			num=digit_square(num);
		}
		if(num==89)max+=tab[i];
	}
	printf("%d",max);
}
