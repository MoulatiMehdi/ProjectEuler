
#include<stdio.h>
int C(int F)
{
	int resultat=5*(F-32)/9;
	return resultat ;

}
 main(){
	
		int F ;
		while(F<=300)
		{
			printf("%d  %d\n",F,C(F));
			F+=20;
		}
	
}
