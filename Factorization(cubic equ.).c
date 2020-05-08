#include <stdio.h>
#include <math.h>

//Disclaimer:not promised if fac[] would be overflown by that a*a
//ex:if w/o c==0&b==0 and enter "100000 0 0"=> fac[1],[2] overflow.

int abs(int a){
    return (a<0)?-a:a;
}
int check(int a,int b,int c,int d,int e,int f)
{
    return ((d+e+f==a)&&(d*e+e*f+d*f==b)&&(d*e*f==c))?1:0;
}

int main(){

    int a,b,c,fac[3],div[5000],divCount=0,secDiv,found=0,swap;

    scanf("%d %d %d",&a,&b,&c);

    if(c==0){
        fac[0]=0;
        if(b==0){
            fac[1]=0;
            fac[2]=a;
        }
        else{
            fac[1]=-(-a+sqrt(a*a-4*1*b))/(2*1);
            fac[2]=-(-a-sqrt(a*a-4*1*b))/(2*1);
        }

    }
    else{
    for(int i=1;i<=abs(c);i++){
        if(abs(c)%i==0){             //find all c's divisor to simplify...?
            div[divCount]=i;    //n is divCount, max array# is divCount-1
            divCount++;
        }
    }

    for(int i=0;i<divCount;i++){
        fac[0]=div[i];

       // printf("\nfac[0]=%d",div[i]);

        secDiv=abs(c)/div[i];

       // printf("\nsecDiv=%d",secDiv);

        for(int j=0;j<divCount;j++){
           // printf("\nstart sec loop");
           // printf("\nsecDiv percent div[j]=%d",secDiv%div[j]);
            if((secDiv%div[j])!=0)continue;

                fac[1]=div[j];
                fac[2]=secDiv/div[j];

               // printf("\nfac[1]=%d",fac[1]);
              //  printf("\nfac[2]=%d",fac[2]);

                //see if fits
                if(check(a,b,c,fac[0],fac[1],fac[2])){
                    found=1;
                    break;
                }
                if(check(a,b,c,-fac[0],fac[1],fac[2])){
                    fac[0]=-fac[0];
                    found=1;
                    break;
                }
                if(check(a,b,c,-fac[0],-fac[1],fac[2])){
                    fac[0]=-fac[0];fac[1]=-fac[1];
                    found=1;
                    break;
                }
                if(check(a,b,c,-fac[0],-fac[1],-fac[2])){
                    fac[0]=-fac[0];fac[1]=-fac[1];fac[2]=-fac[2];
                    found=1;
                    break;
                }
                //printf("\nfailed");
        }
        if(found){/*printf("\nsuccessed,fac[0]=%d,fac[1]=%d,fac[2]=%d\n",fac[0],fac[1],fac[2]);*/break;}
    }
    }


    //sort

    if(fac[0]>fac[1]){swap=fac[0];fac[0]=fac[1];fac[1]=swap;}
    if(fac[1]>fac[2]){swap=fac[1];fac[1]=fac[2];fac[2]=swap;}
    if(fac[0]>fac[1]){swap=fac[0];fac[0]=fac[1];fac[1]=swap;}

    //printf("\nsorted\n");

    printf("%d %d %d",fac[0],fac[1],fac[2]);

    /*printf("\nPrint all array:\n");
    for(int i=0;i<divCount;i++){
        printf("#%d : %d\n",i,div[i]);
    }
    printf("\nabs(c) = %d",abs(c));
    printf("\nc = %d",c);*/
    return 0;
}


