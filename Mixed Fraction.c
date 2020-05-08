#include <stdio.h>

int gcd(int a,int b)
{
    int temp;
    if(a<0)a=-a;if(b<0)b=-b;
    if(a<b)temp=a;a=b;b=temp;
    for(int i=b;i>=1;i--)
    {
        if((a%i==0)&&(b%i==0))return i;
    }
    return 1;
}

void main()
{
    int a,b,c,d,e,f,g,nu1,de1,nu2,de2,nu=0,de=1,in=0,temp;
    
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    
    if(a<0)nu1=a*c-b;
    else nu1=a*c+b;
    
    if(e<0)nu2=e*g-f;
    else nu2=e*g+f;
    
    de1=c;de2=g;
    
    switch(d)
    {
        case 0:
            nu=nu1*de2+nu2*de1;
            de=de1*de2;
            break;
        case 1:
            nu=nu1*de2-nu2*de1;
            de=de1*de2;
            break;
        case 2:
            nu=nu1*nu2;
            de=de1*de2;
            break;
        case 3:
            nu=nu1*de2;
            de=de1*nu2;
            break;
        default:break;
        
    }
   // printf("Temporary output:%d %d\n",nu,de);
    
    if(de<0){
        nu=-nu;de=-de;
    }
    
    if(nu<0)
    {
        in=-((-nu)/de);
        nu-=in*de;
        nu=-nu;
    }
    else
    {
        in=nu/de;
        nu-=in*de;
    }
    
    if(nu==0)de=1;
    
    if(nu!=0)
    {
        temp=gcd(nu,de);
        nu/=temp;de/=temp;
    }
    
    
    
    printf("%d\n%d\n%d",in,nu,de);
    
    
}