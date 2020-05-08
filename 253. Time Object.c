#ifndef MWTIME
#define MWTIME

#include <stdio.h>
typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
 
void initTime(Time *time){
    *time = (Time){0, 0, 0};
}
void setTime(Time *time, int hour, int minute, int second){
    time->hour = hour;
    time->minute = minute;
    time->second = second;
}
void addTime(Time *time, int hour, int minute, int second){
    time->hour += hour;
    time->minute += minute;
    time->second += second;
    if(time->second >= 60)   time->second -= 60, time->minute += 1;
    if(time->minute >= 60)   time->minute -= 60, time->hour += 1;
    if(time->hour >= 24)   time->hour -= 24;
}

void printTime(Time *time){
    
#ifdef H24
    if(time->hour >= 0 && time->hour <= 9)    printf("0%d", time->hour);
    else printf("%d", time->hour);
    putchar(':');
    if(time->minute >= 0 && time->minute <= 9)    printf("0%d", time->minute);
    else printf("%d", time->minute);
    putchar(':');
    if(time->second >= 0 && time->second <= 9)    printf("0%d", time->second);
    else printf("%d", time->second);
    putchar('\n');
#else
    int is_pm = time->hour < 12 ? 0 : 1;
    int hour_12 = time->hour % 12;
    if(hour_12 == 0)    hour_12 = 12;
    
    if(hour_12 >= 0 && hour_12 <= 9)    printf("0%d", hour_12);
    else printf("%d", hour_12);
    printf("%s", is_pm ? "pm" : "am");
    putchar(':');
    if(time->minute >= 0 && time->minute <= 9)    printf("0%d", time->minute);
    else printf("%d", time->minute);
    putchar(':');
    if(time->second >= 0 && time->second <= 9)    printf("0%d", time->second);
    else printf("%d", time->second);
    putchar('\n');

#endif
}
#endif

int main(){
    int c;
    int tmp;
    int h,m,s;
    Time t;
    while((c = getchar()) != EOF){
        switch (c)
        {
        case 'i':
            scanf("%d", &tmp);
            initTime(&t); 
            break;
        case 'a':
            scanf("%d%d%d%d", &tmp, &h, &m, &s);
            addTime(&t, h, m, s); 
            break;
        case 's':
            scanf("%d%d%d%d", &tmp, &h, &m, &s);
            setTime(&t, h, m, s); 
            break;
        case 'p':
            scanf("%d", &tmp);
            printTime(&t);
            break;
        default:
            break;
        }
    }
}

gcc -std=c99 -O2 -c '.\main (1).c' -o main.o
gcc -std=c99 -O2 -c '.\253. Time Object.c' -o h12.o
gcc -std=c99 -O2 -c '.\253. Time Object.c' -o h24.o -DH24 -DinitTime=initTime24 -DsetTime=setTime24 -DaddTime=addTime24 -DprintTime=printTime24
gcc -std=c99 -O2 main.o h12.o h24.o -o 2533
