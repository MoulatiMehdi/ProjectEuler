#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define int_big unsigned long long
int_big find(int k)
{
	int_big num=0,num1=0;
	int j=k;
	while(k!=0)
	{
		num*=10;
		num+=1;
		num1*=pow(10,4);
		num1+=2222;
		k--;
	}
	num*=pow(10,j*4);
	return num+num1;
}
main()
{
	int_big answer=0;
	answer+=find(1)/9;
	answer+=find(2)/99;
	answer+=find(3)/999;
	answer+=find(4)/9999;
	
	int max=10000;
	int i=0,j=0,k=1;
	int cache[16];
	int_big *num=(int_big*)calloc(16,sizeof(int_big));
	
	
	for(cache[0]=0;cache[0]<3&&k<=max;cache[0]++){
		num[0]=cache[0];
	for(cache[1]=0;cache[1]<3&&k<=max;cache[1]++){
		num[1]=num[0]*10+cache[1];
	for(cache[2]=0;cache[2]<3&&k<=max;cache[2]++){
		num[2]=num[1]*10+cache[2];
	for(cache[3]=0;cache[3]<3&&k<=max;cache[3]++){
		num[3]=num[2]*10+cache[3];
	for(cache[4]=0;cache[4]<3&&k<=max;cache[4]++){
		num[4]=num[3]*10+cache[4];
	for(cache[5]=0;cache[5]<3&&k<=max;cache[5]++){
		num[5]=num[4]*10+cache[5];
	for(cache[6]=0;cache[6]<3&&k<=max;cache[6]++){
		num[6]=num[5]*10+cache[6];
	for(cache[7]=0;cache[7]<3&&k<=max;cache[7]++){
		num[7]=num[6]*10+cache[7];
	for(cache[8]=0;cache[8]<3&&k<=max;cache[8]++){
		num[8]=num[7]*10+cache[8];
	for(cache[9]=0;cache[9]<3&&k<=max;cache[9]++){
		num[9]=num[8]*10+cache[9];
	for(cache[10]=0;cache[10]<3&&k<=max;cache[10]++){
		num[10]=num[9]*10+cache[10];
	for(cache[11]=0;cache[11]<3&&k<=max;cache[11]++){
		num[11]=num[10]*10+cache[11];
	for(cache[12]=0;cache[12]<3&&k<=max;cache[12]++){
		num[12]=num[11]*10+cache[12];
	for(cache[13]=0;cache[13]<3&&k<=max;cache[13]++){
		num[13]=num[12]*10+cache[13];
	for(cache[14]=0;cache[14]<3&&k<=max;cache[14]++){
		num[14]=num[13]*10+cache[14];
	for(cache[15]=0;cache[15]<3&&k<=max;cache[15]++)
	{
		num[15]=num[14]*10+cache[15];
		
		if(k==9||k==99||k==999||k==9999) 
		{
			k++;
		}
       if(num[15]%k==0&&num[15]>0)
       {
       	    i=0;
       	    answer+=num[15]/k;
       	    while(i<16)
       	    {
       	    	cache[i]=0;
       	    	num[i]=0;
       	    	i++;
			}
			k++; 
	   }
	}}}}}}}}}}}}}}}}
	
	printf("%llu\n",answer);
	
}
