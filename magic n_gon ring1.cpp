#include<stdio.h>
#include<conio.h>
int fact(int a)
{
	int i;
	if(a==0)a=1;
	for(i=a-1;i>=1;i--)
	{
		a*=i;
	}
	
	return a;
}

main()
{
	int i,j,l;
	int classe,max=13,test;
	int string[]={1,2,3,4,5,6,7,8,9,10};
	int num[10];
	
	int answer[15]={0};
			
	printf(" total  께\t  solution set\n");
	printf("께께께께께께께께께께께께께께께께께께께께께�\n");	
	for(max=13;max<=20;max++)			
	for(l=1;l<=fact(10);l++)
	{
		classe=l;
		for(i=0;i<10;i++) string[i]=i+1;
		
		for(i=9;i>=0;i--)
		{
			for(j=0;j<10;j++)
			{
				
				if(classe<=fact(i)*(j+1))
				{
					classe-=fact(i)*j;
					num[i]=string[j];
					while(j!=10)
					{
						string[j]=string[j+1];
						j++;
					}
					break;
				}	
			}	
		}
		if(num[0]<num[1]&&num[0]<num[2]&&num[0]<num[3]&&num[0]<num[4])
		{
			if(num[0]==10||num[1]==10||num[2]==10||num[3]==10||num[4]==10)
			{
				if(num[0]+num[5]+num[6]==max)
				if(num[1]+num[6]+num[7]==max)
				if(num[2]+num[7]+num[8]==max)
				if(num[3]+num[8]+num[9]==max)
				if(num[4]+num[9]+num[5]==max)
				{
					test=0;
					printf("    %d  께  ",max);
					for(i=0;i<10;i++)
					{
						if(answer[i]<num[i])
						{
							test=1;
							break;
						}
						else if(answer[i]>num[i])
						{
							test=0;
							break;
						} 
					}
					for(i=0;i<5;i++)
					{
					
					if(i<4)
						{
							printf("%d %d %d,",num[i],num[i+5],num[i+6]);
							if(test!=0)
							{
								answer[i*3]=num[i];	
								answer[i*3+1]=num[i+5];
								answer[i*3+2]=num[i+6];
							}
							
						}
					else
						{
							printf("%d %d %d\n",num[i],num[i+5],num[5]);
							if(test!=0)
							{
								answer[i*3]=num[i];	
								answer[i*3+1]=num[i+5];
								answer[i*3+2]=num[5];
							}			
						} 
					}
				}
			}
		}	
	}
	printf("께께께께께께께께께께께께께께께께께께께께께�\n");
	printf("\nanswer is : ");
	for(i=0;i<15;i++) printf("%d",answer[i]);
	
}
