#include <stdio.h>
typedef struct{
    int x;
    int y;
} Point;

int ip(Point a,Point b,Point c)
{
    return (c.x-b.x)*(b.x-a.x)+(c.y-b.y)*(b.y-a.y);
}
int le(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int op(Point a,Point b,Point c)
{
    return (c.y-b.y)*(b.x-a.x)-(c.x-b.x)*(b.y-a.y);
}




//sequence list as follow:1234.1243.1324.1342.1423.1432

void main()
{
    int t,x1,y1,x2,y2,x3,y3,x4,y4,l1,l2,l3,l4,i1,i2,i3,i4,con1,con2;
    Point a,b,c,d,p1,p2,p3,p4;
    
    scanf("%d",&t);
    
    for(int i=0;i<t;i++)
    {
        scanf("%d%d%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        
        p1=a;p2=b;p3=c;p4=d;
        if((op(p1,p2,p3)>0)&&(op(p2,p3,p4)>0)&&(op(p3,p4,p1)>0)&&(op(p4,p1,p2)>0))goto Mark;
        p1=a;p2=b;p3=d;p4=c;
        if((op(p1,p2,p3)>0)&&(op(p2,p3,p4)>0)&&(op(p3,p4,p1)>0)&&(op(p4,p1,p2)>0))goto Mark;
        p1=a;p2=c;p3=b;p4=d;
        if((op(p1,p2,p3)>0)&&(op(p2,p3,p4)>0)&&(op(p3,p4,p1)>0)&&(op(p4,p1,p2)>0))goto Mark;
        p1=a;p2=c;;p3=d;p4=b;
        if((op(p1,p2,p3)>0)&&(op(p2,p3,p4)>0)&&(op(p3,p4,p1)>0)&&(op(p4,p1,p2)>0))goto Mark;
        p1=a;p2=d;p3=c;p4=b;
        if((op(p1,p2,p3)>0)&&(op(p2,p3,p4)>0)&&(op(p3,p4,p1)>0)&&(op(p4,p1,p2)>0))goto Mark;
        p1=a;p2=d;p3=b;p4=c;
        if((op(p1,p2,p3)>0)&&(op(p2,p3,p4)>0)&&(op(p3,p4,p1)>0)&&(op(p4,p1,p2)>0))goto Mark;
        
        Mark:
        
        l1=le(p1,p2);l2=le(p2,p3);l3=le(p3,p4);l4=le(p4,p1);
        i1=ip(p1,p2,p3);i2=ip(p2,p3,p4);i3=ip(p3,p4,p1);i4=ip(p4,p1,p2);
        
        con1=((l1==l2)&&(l2==l3)&&(l3==l4)&&(l4==l1))?0:1;
        con2=((i1==0)&&(i2==0)&&(i3==0)&&(i4==0))?0:1;
        
        if((con1==0)&&(con2==0))printf("square");
        else if((con1==0)&&(con2!=0))printf("diamond");
        else if((con1!=0)&&(con2==0))printf("rectangle");
        else printf("other");
        
        
        
        
        if(i!=t-1)printf("\n");
    }
    
}