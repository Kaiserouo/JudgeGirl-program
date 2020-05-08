#include <stdio.h>
#include <math.h>

/*
        set new struct for all parking lot and store in array, keeping record
    of x, y axis, remaining # and already parked #.
        run bicycle one by one by the use of 2 var: current parking# and its distance.
        use for to output all already parked #
*/

typedef struct{
    int x;
    int y;
    int remaining;
    int already;
} Parking;
int abs(int a){
    return a<0?-a:a;
}
int distance(Parking P,int b_x,int b_y){
    return abs(P.x-b_x)+abs(P.y-b_y);
}

void main(){
    
    int parking_n,bicycle_n,cur_par_n,cur_par_dis,bike_x,bike_y,marker; //marker: to see if have arranged a place for it 
    Parking P[11];
    
    scanf("%d",&parking_n);
    
    for(int i=0;i<parking_n;i++){       //input of parking lot data
        scanf("%d %d %d",&P[i].x,&P[i].y,&P[i].remaining);
        P[i].already=0;
    }
    
    scanf("%d",&bicycle_n);
    
    for(int i=0;i<bicycle_n;i++){       //start parking process bicycle#i
        marker=0;//initialization
        scanf("%d %d",&bike_x,&bike_y);     //input #i
        
        for(int j=0;j<parking_n;j++){
            if(P[j].remaining<=0)continue;
            else if(marker==0){
                cur_par_dis=distance(P[j],bike_x,bike_y);   //initialization of first
                cur_par_n=j;
                marker=1;
            }
            
            
            if((cur_par_dis<distance(P[j],bike_x,bike_y))||(P[j].remaining<=0))continue;    //distance bigger or no vacant
            else if(cur_par_dis>distance(P[j],bike_x,bike_y)){  //distance smaller
                cur_par_dis=distance(P[j],bike_x,bike_y);   //
                cur_par_n=j;                                //changing current found smallest  
                                                            //to new parking lot
                continue;                                   //
            }
            else if(cur_par_dis==distance(P[j],bike_x,bike_y)){//distance same, start comparing axis
                if(P[cur_par_n].x<P[j].x)continue;                  //x:
                else if(P[cur_par_n].x>P[j].x){                       
                    cur_par_dis=distance(P[j],bike_x,bike_y);       
                    cur_par_n=j;
                                                                    //change
                    continue;
                }
                else if(P[cur_par_n].x==P[j].x){                    //same x, compare y:
                    if(P[cur_par_n].y<P[j].y)continue;
                    else if(P[cur_par_n].y>P[j].y){
                        cur_par_dis=distance(P[j],bike_x,bike_y);       
                        cur_par_n=j;
                                                                   //change
                        continue;
                    }
                }
            }
        }
        
        P[cur_par_n].remaining--;P[cur_par_n].already++;    //put bike in
        
    }
    
    
    for(int i=0;i<parking_n;i++){   //print all remaining
        printf("%d",P[i].already);
        if(i!=parking_n-1)printf("\n");
    }
    
   
}


