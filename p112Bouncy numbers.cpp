#include<stdio.h>
#include<stdlib.h>
int is_incresing(int num)
{
	int i,k,test=1;
	i=num%10;
	num/=10;
	while(num!=0)
	{
		k=num%10;
		if(k>i)  
		{
			test=0;
			break;
		}
		num/=10;
		i=k;	
	}
	return test;
}
int is_decresing(int num)
{
	int i,k,test=1;
	i=num%10;
	num/=10;
	while(num!=0)
	{	
		k=num%10;
		if(k<i)  
		{
			test=0;
			break;
		}
		num/=10;
		i=k;
	}
	return test;
}

main()
{
	int i,bonucy=0,a,b;
	for(i=0;;i++)
	{
		a=is_decresing(i);
		b=is_incresing(i);
		if(!a&&!b)
		{
			bonucy++;
			if(bonucy/(double) i==99/double(100))
			{
				printf("the least number:%d--->%d",i,bonucy*100/i);
				puts("%");
				exit(1);
			}	
		}
	}
}
