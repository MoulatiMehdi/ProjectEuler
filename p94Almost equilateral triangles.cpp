#include<stdio.h>
#include<math.h>
#define int_64bit unsigned long long

int_64bit pgcd(int_64bit a, int_64bit b){

	while(a != 0 && b != 0)
	{
	
		if(a > b) a = a%b;
		else b = b%a;
	}
	return a+b;
}

main()
{
	
	int_64bit max=1000000000;
	int_64bit result=0;
	
	for(int_64bit m=2;m<=sqrt((max-2)/2)/2;m++)
	//max=c*2+c*2-2=8*m�-2
	//so m=sqrt((max-2)/8) (if n==m )
	{
	
		for(int_64bit n=1;n<m;n++)
		{
			if(pgcd(n,m)==1&&(m+n)%2==1)
			{
				int_64bit a=m*m-n*n;
				int_64bit b=2*m*n;
				int_64bit c=m*m+n*n;
				if(c*2+(c-1)*2>=max) break;
				
				if(b*2==c-1)
				{
					if(c*2+b*2<max)result+=c*2+b*2;
			    }
					
				else if(a*2==c+1)
				{
					if(c*2+a*2<max)result+=c*2+a*2;
			    }
				
			}
		}
	}
	printf("%lld",result);	
}
