
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define LIMIT 100000000

unsigned int *T=(unsigned int*)calloc(LIMIT,sizeof(unsigned int));
unsigned int i,j;



int main (){


for(i = 0; i < LIMIT ; i++)
   T[i] = 1;

//Le Crible d'Ératosthène
for(i = 2; i < sqrt(LIMIT) ; i++){
    if (T[i]){
        j = i;
        while (j * i < LIMIT){
            T[j * i] = 0;
            j++;
        }
    }
}


/*-----------------------------------*/
unsigned int k = 0;
for (i = 2 ; i <sqrt(LIMIT); i++){
    if(T[i]){
            k++;
        for(j = i + 1 ; j < LIMIT; j++){
            if(T[j]){
                if(i * j < LIMIT)k++;
                else break;
            }
        }
    }
}
printf("\nk = %u",k);

return 0;
}
