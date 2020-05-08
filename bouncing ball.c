#include <stdio.h>
#include <math.h>

typedef struct{

    int x,y,dx,dy;

} Ball;

int main(){
    int mapX,mapY,time,tempX,tempY;
    Ball b[2];

    scanf("%d%d",&mapX,&mapY);
    for(int i=0;i<2;i++){
        scanf("%d%d",&b[i].x,&b[i].y);
    }
    for(int i=0;i<2;i++){
        scanf("%d%d",&b[i].dx,&b[i].dy); //input
    }
    scanf("%d",&time);

   // printf("Ini: b[0]:( %d , %d ),speed ( %d , %d )\nb[1]:( %d , %d ),speed ( %d , %d )\n",b[0].x,b[0].y,b[0].dx,b[0].dy,b[1].x,b[1].y,b[1].dx,b[1].dy);
    for(int i=0;i<time;i++){    //simulate times
        for(int j=0;j<2;j++){
            b[j].x+=b[j].dx;    //walk 1 step
            b[j].y+=b[j].dy;
            //printf("b[%d]:( %d , %d ), speed ( %d , %d )\n",j,b[i].x,b[i].y,b[i].dx,b[i].dy);
        }

        if(b[0].x==b[1].x && b[0].y==b[1].y){   //if(collide)
            tempX=b[0].dx;tempY=b[0].dy;
            b[0].dx=b[1].dx;b[0].dy=b[1].dy;    //swap velocity
            b[1].dx=tempX;b[1].dy=tempY;
        }

        for(int j=0;j<2;j++){
            if(b[j].x==1){
                b[j].dx=1;
            }
            if(b[j].x==mapX){   //if(hit side)
                b[j].dx=-1;     //velocity turn
            }
            if(b[j].y==1){
                b[j].dy=1;
            }
            if(b[j].y==mapY){
                b[j].dy=-1;
            }
        }
        //printf("Turn to: b[0]:speed ( %d , %d )\nb[1]:speed ( %d , %d )\n",b[0].dx,b[0].dy,b[1].dx,b[1].dy);
        //printf("====\n");
    }

    printf("%d\n%d\n%d\n%d",b[0].x,b[0].y,b[1].x,b[1].y);


}








