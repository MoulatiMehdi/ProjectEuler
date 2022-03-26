#include<stdio.h>
#include<math.h> 
main()
{
	int i,j,k;
	int n_num=0;
	for(i=1;i<=100;i++)
	{
		for(j=1;;j++)
		{
			for(k=1;pow(10,k)<=pow(j,i);k++)continue;
			
			if(i==k)
			{
				n_num++;
			}
			else if(k>i)break; 
		}
	}
	printf("%d",n_num);
	
}
