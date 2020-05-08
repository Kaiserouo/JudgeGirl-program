#define DEBUG 0


#if DEBUG==1
#include <stdio.h>
#endif // DEBUG
int value(int type, int width, int height, int length){
    //return if type incorrect
    int typeValue;
    switch(type){
    case 79:
        typeValue=30;break;
    case 47:
        typeValue=10;break;
    case 29:
        typeValue=4;break;
    case 82:
        typeValue=5;break;
    case 26:
        typeValue=3;break;
    case 22:
        typeValue=9;break;
    default:
        return -1;
    }
    //return if length incorrect
    if((width<=0) || (height<=0) || (length<=0))return -2;


    //find max of length
    int max;//actually min bc. searching for minimum value. Well.
    max=(width<height?width:height);
    max=(max<length?max:length);

    //determine how many blocks can be cut
    int blockCount=(width/max)*(height/max)*(length/max);
    int blockValue=blockCount*(max*max*max*max*max*max)*(typeValue);

    //a,b,c:remainder of 3 sides
    int a=width-(width/max)*max,
        b=height-(height/max)*max,
        c=length-(length/max)*max;

    //calculate block value
    //if can devide into cubes w/ no remainder, return its total value
    if(a==0 && b==0 && c==0)return blockValue;
    //if 2 sides can be devided, then whats left is a rectangular block
    else if((a==0&&b==0)||(b==0&&c==0)||(c==0&&a==0)){
        if(c!=0)return blockValue+value(typeValue,c,width,height);
        if(b!=0)return blockValue+value(typeValue,b,width,length);
        if(a!=0)return blockValue+value(typeValue,a,length,height);
    }
    //if only 1 side can be devided, then find all 2 possibility of calculating the total value of the rest of block
    //and return the bigger one
    else{

        //set another var. to store two sides that are not devided
        //side 3 is for the side that is devided by max (which is the max length of 3)
        int side1,side2,r1,r2,side3;
        if(a==0){side1=height;r1=b;side2=length;side2=c;side3=width;}
        if(b==0){side1=width;r1=a;side2=length;side2=c;side3=height;}
        if(c==0){side1=height;r1=b;side2=width;side2=a;side3=length;}

        //set var. to store total value of two possibility in order to prevent unnecessary calculation
        int p1=value(typeValue,side3,r1,side2)+value(typeValue,side3,(side1-r1),r2),
            p2=value(typeValue,side3,r2,side1)+value(typeValue,side3,(side2-r2),r1);

        //output the higher one
        return p1>p2 ? p1+blockValue : p2+blockValue;
    }

}

#if DEBUG==1
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d",value(a,b,c,d));
}
#endif // DEBUG

