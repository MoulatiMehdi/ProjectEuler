#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
	int max_p=pow(10,7);
	int i,j=1,k=0;
	
	int *answer=(int*)calloc(max_p,sizeof(int));
	for(i=1;i<max_p;i++)
	{
		for(j=i;j<max_p;j+=i)
		{
			answer[j]++;
		}
		if(answer[i]==answer[i-1])
		{
			k++;
		}
	}
	printf("the answer is : %d",k);
}
