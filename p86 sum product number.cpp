#include<stdio.h>
#include<stdlib.h>
#define LIMIT 12000


main()
{
	int i,j,k,l,m,n,a,b,c,d,e,f,g;
	int num_1;
	long long classe;
	int *sum_p=(int*)calloc(LIMIT+1,sizeof(int));
	int *answer=(int*)calloc(LIMIT*2,sizeof(int));
	
	for(i=2;i<=LIMIT;i++){	
	
		for(j=i;j<=LIMIT;j++){
		num_1=i*j-i-j;
		classe=num_1+2;
		if(classe>LIMIT)break;
		if(sum_p[classe]==0||sum_p[classe]>i*j)
		 sum_p[classe]=i*j;
		for(k=j;k<=LIMIT;k++){
			
			num_1=i*j*k-i-j-k;
			classe=num_1+3;
			if(classe>LIMIT)break;
			if(sum_p[classe]==0||sum_p[classe]>i*j*k) 
			sum_p[classe]=i*j*k;
			for(l=k;l<=LIMIT;l++)	{
				
				num_1=i*j*l*k-i-j-k-l;
				classe=num_1+4;
				if(classe>LIMIT)break;
				if(sum_p[classe]==0||sum_p[classe]>i*j*k*l) 
				sum_p[classe]=i*j*k*l;
				for(m=l;m<=LIMIT;m++)
				{
						
					num_1=i*j*l*k*m-i-j-k-l-m;
					classe=num_1+5;
					if(classe>LIMIT)break;
					if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m)
					 sum_p[classe]=i*j*k*l*m;
					for(n=m;n<=LIMIT;n++)
					{
							
						num_1=i*j*l*k*m*n-i-j-k-l-m-n;
						classe=num_1+6;
						if(classe>LIMIT)break;
						if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n) 
						sum_p[classe]=i*j*k*l*m*n;
						for(a=n;a<=LIMIT;a++)
						{
								
							num_1=i*j*l*k*m*n*a-i-j-k-l-m-n-a;
							classe=num_1+7;
							if(classe>LIMIT)break;
							if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n*a) 
							sum_p[classe]=i*j*k*l*m*n*a;
							for(b=a;b<=LIMIT;b++)
							{
									
								num_1=i*j*l*k*m*n*a*b-i-j-k-l-m-n-a-b;
								classe=num_1+8;
								if(classe>LIMIT)break;
								if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n*a*b) sum_p[classe]=i*j*b*k*l*m*n*a;
						
								for(c=b;c<=LIMIT;c++){
									num_1=i*j*l*k*m*n*a*b*c-i-j-k-l-m-n-a-b-c;
									classe=num_1+9;
									if(classe>LIMIT)break;
									if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n*a*b*c)
									 sum_p[classe]=i*j*b*k*l*m*n*a*c;
						
									for(d=c;d<=LIMIT;d++){
											
							num_1=i*j*l*k*m*n*a*b*c*d-i-j-k-l-m-n-a-b-c-d;
							classe=num_1+10;
							if(classe>LIMIT)break;
							if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n*a*b*c*d) 
							sum_p[classe]=i*j*b*k*l*d*m*n*a*c;
						
									for(e=d;e<=LIMIT;e++){
												
							num_1=i*j*l*k*m*n*a*b*c*d*e-i-j-k-l-m-n-a-b-c-d-e;
							classe=num_1+11;
							if(classe>LIMIT)break;
							if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n*a*b*c*d*e) 
							sum_p[classe]=i*j*b*k*l*d*m*n*e*a*c;
						
										for(f=e;f<=LIMIT;f++){
													
							num_1=i*j*l*k*m*n*a*b*c*d*e*f-i-j-k-l-m-n-a-b-c-d-e-f;
							classe=num_1+12;
							if(classe>LIMIT)break;
							if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n*a*b*c*d*e*f) 
							sum_p[classe]=i*j*b*k*l*d*m*n*e*a*c*f;
							
						
											for(g=f;g<=LIMIT;g++){
														
							num_1=i*j*l*k*m*n*a*b*c*d*e*f*g-i-j-k-l-m-n-a-b-c-d-e-f-g;
							classe=num_1+13;
							if(classe>LIMIT)break;
							if(sum_p[classe]==0||sum_p[classe]>i*j*k*l*m*n*a*b*c*d*e*f*g) 
							sum_p[classe]=i*j*b*k*l*d*m*n*e*a*c*f*g;
													}
												}							
											}
										}
									}
								}
							}
						}
					}
				}						
			}
		}
	}
	int sum=0;
	for(i=2;i<=LIMIT;i++)
	{
		answer[sum_p[i]]++;
		if(answer[sum_p[i]]==1)sum+=sum_p[i];
		
	}
	printf("--->%d",sum);
		
	
}

