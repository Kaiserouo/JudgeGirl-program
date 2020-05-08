#include <stdio.h>
#include <math.h>

int main(){

    int year = 2010,isLeap,month = 7,dayOfMonth,iniDay = 5,currentDay,counter;

    // scanf("%d%d%d",&year,&month,&iniDay);

    if((month<1 || month>12) || (iniDay<0 || iniDay>6)) {
        printf("invalid\n");        //invalid condition
        return 0;
    }

    isLeap= (year%400==0 || (year%4==0 && year%100!=0))?1:0;    //determine if leap year

    switch (month){     //initializing day of month
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        dayOfMonth=31;
        break;
    case 2:
        dayOfMonth=(isLeap)?29:28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dayOfMonth=30;
        break;
    }

    printf(" Su Mo Tu We Th Fr Sa\n=====================\n"); //starting
    counter=1;  //counter of days
    currentDay=iniDay;

    for(int i=0;i<iniDay;i++)printf("   ");



    while(counter<=dayOfMonth){ //run until print second last day, last day be dealt with later
        printf("%3d",counter);
        currentDay++;
        counter++;

        if(currentDay==7){  //reach end of row
            printf("\n");
            currentDay=0;
            continue;
        }
        if(counter==dayOfMonth+1){
            printf("\n");
            break;
        }
    }

    printf("=====================\n");

}








