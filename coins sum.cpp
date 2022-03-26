#include<stdio.h>
#include<conio.h>
main()
{
	int i,j,k,l,m,n,o;
	int num=0,test=0;
	for(i=0;i<=2;i++)// 100 p
	{
		for(j=0;j<=4;j++)//50p
		{
			for(k=0;k<=10;k++)//20p
			{
				for(l=0;l<=20;l++)//10p
				{
					for(m=0;m<=40;m++)//5p
					{
						for(n=0;n<=100;n++)//2p
						{
							for(o=0;o<=200;o++)// 1p
							{
								num=1*o+2*n+5*m+10*l+20*k+50*j+100*i;	
								if(num!=200) continue;
								else if(num==200) test++;	
							}
						}
					}
				}
			}
		}		
	}
	test++;//this is for the number 200
				printf("number of probabilities is %d",test);
	
}
