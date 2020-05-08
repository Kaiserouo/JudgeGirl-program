#include <stdio.h>
#include <math.h>

int direction;// 1:up 2:right 3:down 4:left

void changeDir(){
    switch (direction){
    case 1:
        direction=2;
        break;
    case 2:
        direction=1;
        break;
    case 3:
        direction=4;
        break;
    case 4:
        direction=3;
        break;

    }
}
typedef struct{
    int w;
    int d;
} Point;

int main(){

    int map[102][102],width,depth,num,correspond[400];
    Point process,curLoc;   //processing:point at side; curLoc:point currently walking

    scanf("%d%d",&width,&depth);

    for(int d=1;d<=depth;d++)       //input map
    for(int w=1;w<=width;w++){
        scanf("%d",&map[w][d]);
    }

 ///   printf("Scan successfully\n");

    num=2*(width+depth);    //initialization
    for(int i=0;i<num;i++)correspond[i]=-1; //-1=no correspondence

    for(int i=1;i<=width;i++)map[i][depth+1]=i-1+100;
    for(int i=depth;i>=1;i--)map[width+1][i]=width+depth-i+100;   //100:distinguish from mirror
    for(int i=width;i>=1;i--)map[i][0]=2*width+depth-i+100;       //every mark is original + 100
    for(int i=1;i<=depth;i++)map[0][i]=2*width+depth+i-1+100;
    map[0][depth+1]=map[width+1][0]=map[0][0]=map[width+1][depth+1]=9999;  //margin, wahtever, no one cares

  /*  printf("Setting map successfully, map is:\n\n");
    for(int d=0;d<=depth+1;d++){
        for(int w=0;w<=width+1;w++){
            printf("%d ",map[w][d]);
        }
        printf("\n");
    }
    printf("Start processing all side points:\n");*/

    for(process.d=0;process.d<=depth+1;process.d++)     //process all point
    for(process.w=0;process.w<=width+1;process.w++){
            ///printf("Point:( %d , %d ) , map: %d :\n",process.w,process.d,map[process.w][process.d]);
        if(!(map[process.w][process.d]>99 && map[process.w][process.d]<9999) ){

            /*printf("Dont meet condition, let go.\n");*/continue;   //not in margin,dont bother to process
        }
///printf("Meet condition\n");
    curLoc.w=process.w;curLoc.d=process.d;  //initialize walking point


        /*switch(process.w){
        case 0:
            direction=2;break;
        case width+1:
            direction=4;break;  //initialize walking direction
        default:break;
        }
        switch(process.d){      //FAIL DUE TO SYNTEX ERROR (no var in case)
        case 0:
            direction=3;break;
        case depth+1:
            direction=1;break;
        default:break;
        }*/
///printf("Set ini direction\n");
        if(process.w==0)direction=2;
        if(process.w==width+1)direction=4;//initialize walking direction
        if(process.d==0)direction=3;
        if(process.d==depth+1)direction=1;
///printf("Ini direction set! Now into loop\n");
        while(1){   //LOOP: walk until meet side point
            /*switch(direction){
            case 1:
                curLoc.d--;break;
            case 2:
                curLoc.w++;break;   //walk one step toward direction indicated
            case 3:
                curLoc.d++;break;
            case 4:
                curLoc.w--;break;

            }*////printf("Moving\n");
            if(direction==1)curLoc.d--;
            if(direction==2)curLoc.w++;
            if(direction==3)curLoc.d++;
            if(direction==4)curLoc.w--;
///printf("Complete moving! At point ( %d , %d )\n",curLoc.w,curLoc.d);
            if(map[curLoc.w][curLoc.d]==1){ //mirror
                changeDir();///printf("ChangeDir\n");
            }
            if(map[curLoc.w][curLoc.d]>99){     //touch side => record correspondence
                    ///printf("Touched side\n");
                correspond[map[process.w][process.d]-100]=map[curLoc.w][curLoc.d];break;
            }
        }


    }

    for(int k=0;k<num;k++){
        printf("%d",correspond[k]-100);
        if(k!=num-1)printf("\n");
    }

}








