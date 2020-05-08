#include <stdio.h>
#include <math.h>

void main(){
    
    int A,B,a[5],b[5],temp=1,Cor=0,Dis=0;
    scanf("%d %d",&A,&B);
    
    for(int i=0;i<4;i++){
        temp=1;
        for(int j=0;j<i;j++)temp*=10;
        a[i]=A/temp-(A/(temp*10))*10;
        b[i]=B/temp-(B/(temp*10))*10;
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if((a[i]==b[j])&&(i==j))Cor++;
            if((a[i]==b[j])&&(i!=j))Dis++;
        }
    }
    
    printf("%dA%dB",Cor,Dis);
}