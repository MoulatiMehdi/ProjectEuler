#include<stdio.h>
#include<math.h>
#include<conio.h>
int pnt_num(int num)
{
	int i;
	i=num*(3*num-1)/2;
	return i;
}
int is_pnt_num(int num)
{
	num=fabs(num);
	
	int i,answer=0;
	if(num==0) answer=0;
	else
	for(i=0;pnt_num(i)<=num;i++)
	{
		if(pnt_num(i)==num) 
		{
			answer=1;
			break;
		}	  
	}
	
	return answer;
}

main()
{
	int i,j,test=0;
	int sum,dif,max=2200;
	for(i=1;i<=max;i++)
	{	
		for(j=1;j<=max;j++)
		{	
			sum=pnt_num(i)+pnt_num(j);
			dif=pnt_num(i)-pnt_num(j);
			if(dif<0)dif*=-1;
			if(is_pnt_num(sum)==1&&is_pnt_num(dif)==1)
			{
				printf("\n----->P%d P%d --->D=%d\n",i,j,dif);
				test++;
				break;
			}
		 			
		}
		if(test!=0) break;
	}
}
