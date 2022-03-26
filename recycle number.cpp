
#include <stdio.h>
#include<conio.h>

int main()
{
	int n;
	int count;
	int d;
	int d0;
	
	for(n=999;n>0;n-=2)
	{
		if(n%5==0) continue;
		
		d = 1;
		d0 = d%n;
		
		d = (d%n)*10;
		
		
		for(count=0;count<=n;++count)
		{
			if(d>=n) d %= n;
			if(d==d0) break;
			d *= 10;
			printf("%d:%d--->%d\n",n,d,d0);
			getch();
		}
		
		if(count+2==n)
		{
			printf("%i\n", n);
			break;
		}
	}
	
	return 0;
}
