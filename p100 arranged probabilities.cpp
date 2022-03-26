#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define int_64bit unsigned long long
is_half_chance(int_64bit blue,int_64bit total)
{
	if(total*total-total==2*(blue*blue-blue)) return 1;
	else return 0;
}
main()
{
	
	double start=0,end=1;
	int_64bit arr[20]={0},l=0; 
	int_64bit total,blue;
	int_64bit max=pow(10,12);
	
	for(total=21;;total++)
	{
		
		for(blue=total*start;blue<=total*end;blue++)
		{
			if(is_half_chance(blue,total))
			{
				arr[l]=total;
				start=(blue-1)/double(total);
				end=(blue+1)/double(total);
				
				if(total>max) 
				{
					printf("blue disc=%lld",blue);	
					exit(1);
				}
				if (l!=0)total*=arr[l]/(double)arr[l-1];
				l++;
				break;
			}
		}
	}
}
