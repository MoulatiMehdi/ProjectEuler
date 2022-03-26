#include<stdio.h>
#include<math.h>
typedef struct
{
	int x;
	int y;
}point;
int is_right_Triangle(point B,point C)
{
	//A is the point (0,0)
	int AB,AC,BC;//length between  two point 
	AB=pow(B.x,2)+pow(B.y,2);//we don't need to mins the coordinates of  A from B our C
	AC=pow(C.x,2)+pow(C.y,2);
	BC=(B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y);
	if(AB+AC==BC||BC+AC==AB||AB+BC==AC) return 1;
	else return 0;
	
}
main()
{
	point B,C;
	int max=50,answer=0;
	for(B.x=0;B.x<=max;B.x++)
	{
		for(B.y=0;B.y<=max;B.y++)
		{
			if(B.x==0&&B.y==0)continue;
			for(C.x=0;C.x<=max;C.x++)
			{
				for(C.y=0;C.y<=max;C.y++)
				{
					if(C.x==0&&C.y==0)continue;
					if(C.x==B.x&&C.y==B.y)continue;
					if(is_right_Triangle(B,C))
					{
						answer++;
					}
				}
			}
		}
	}
	answer/=2;//delete the repetation
	printf("%d",answer);
}
