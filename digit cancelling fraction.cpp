#include<stdio.h>
#include<conio.h>
main()
{
	int i,j;
	float num=0,test=0;
	
	int nom=1,denom=1;
	
	float mul_fraction;
	int a=0,b=0,c=0,d=0;
	
	
	
	for(i=10;i<100;i++)
	{	
		a=i/10; //digit number 2
		b=i-a*10; //digit number 1
		for(j=10;j<i;j++)
		{
			num=j/float(i);
			c=j/10;
			d=j-c*10;
			
		
			if(a==c&&(a!=0||c!=0))
			{
				test=d/float(b);
				if(test<1&&test==num) 
				{
					printf("%d/%d=%d/%d=%f\n",b,d,j,i,num);
					mul_fraction*=test;
					nom*=d;
					denom*=b;
				}
			}
			
			 if(a==d&&(a!=0||d!=0))
			{
				test=c/float(b);
				if(test<1&&test==num)
				{
					printf("%d/%d=%d/%d=%f\n",b,c,j,i,num);
					mul_fraction*=test;
					nom*=c;
					denom*=b;
				 } 
				 
			}
			
			 if(b==c&&(b!=0||c!=0))
			{
				test=d/float(a);
				if(test<1&&test==num)
				{
					printf("%d/%d=%d/%d=%f\n",a,d,j,i,num);
					mul_fraction*=test;
					nom*=d;
					denom*=a;
				 } 
			}
			
			if(b==d&&(b!=0||d!=0))
			{
				test=c/float(a);
				if(test<1&&test==num) 
				{
					mul_fraction*=test;
					printf("%d/%d=%d/%d=%f\n",a,c,j,i,num);
					nom*=c;
					denom*=a;
				}
			}
					
		}	
	}
	for(i=2;i<100;i++)
	{
		if(nom%i==0&&denom%i==0)
		{
			nom/=i;
			denom/=i;
			i--;
		}
		
	}
	printf(" the answer is ----> %d",denom);	
}
	
