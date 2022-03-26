#include<stdio.h>
typedef struct
{
	int x;
	int y;
}two_D;
int det(two_D p1,two_D p2)
{
	int answer=0;
	answer=p1.x*p2.y-p1.y*p2.x;
	return answer;
}
is_in_triangle(two_D p,two_D p0,two_D p1,two_D p2)
{
	float a,b;
	int test;
	two_D v1,v2;
	
	v1.x=p1.x-p0.x;
	v2.x=p2.x-p0.x;
	
	v1.y=p1.y-p0.y;
	v2.y=p2.y-p0.y;
	
	a=(det(p,v2)-det(p0,v2))/(float)det(v1,v2);
	b=-(det(p,v1)-det(p0,v1))/(float)det(v1,v2);
	if(a>0&&b>0&&a+b<1) test=1;
	else test=0;
	return test;
}
main()
{
	FILE* file;
	file=fopen("p102_triangles.txt","r");
	
	
	two_D origin,p[3];
	origin.x=origin.y=0;
	
	int tab[1000][6]={0};
	int i=0,j=0,k=1,answer=0;
	char c;
	while((c=fgetc(file))!=EOF)
	{
		if(c==',')
		{
			tab[i][j]*=k;
			j++;
			k=1;
		}
		else if(c=='\n')
		{
			
			tab[i][j]*=k;
			k=1;
			i++;
			j=0;
		}
		else if(c=='-')k=-1;
		else
		{
			tab[i][j]*=10;
			tab[i][j]+=c-'0';	
		}
	}
	tab[i][j]*=k;
	for(i=0;i<1000;i++)
	{
		p[0].x=tab[i][0];
		p[0].y=tab[i][1];
		p[1].x=tab[i][2];
		p[1].y=tab[i][3];
		p[2].x=tab[i][4];
		p[2].y=tab[i][5];
		if(is_in_triangle(origin,p[0],p[1],p[2])) answer++;
	}
	printf("the answer is :%d",answer);
}
