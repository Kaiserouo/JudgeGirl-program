#include <stdio.h>
#include <stdlib.h>
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
    if(time->second > 60)   time->second -= 60, time->minute += 1;
    if(time->minute > 60)   time->minute -= 60, time->hour += 1;
    if(time->hour > 24)   time->hour -= 24;
}

void printTime24(Time *time){
    if(time->hour >= 0 && time->hour <= 9)    printf("0%d", time->hour);
    else printf("%d", time->hour);
    putchar(':');
    if(time->minute >= 0 && time->minute <= 9)    printf("0%d", time->minute);
    else printf("%d", time->minute);
    putchar(':');
    if(time->second >= 0 && time->second <= 9)    printf("0%d", time->second);
    else printf("%d", time->second);
    putchar('\n');
}
void printTime(Time *time){
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


}
#endif


int main() {
	int ch;
	int n, i, h, m, s;
	scanf("%d", &n);
	Time *t = (Time*) malloc(sizeof(Time)*n);
	while ((ch = getchar()) != EOF) {
		switch(ch) {
			case 'i':
				scanf("%d", &i);
				initTime(&t[i]);
				break;
			case 's':
				scanf("%d%d%d%d", &i, &h, &m, &s);
				setTime(&t[i], h, m, s);
				break;
			case 'a':
				scanf("%d%d%d%d", &i, &h, &m, &s);
				addTime(&t[i], h, m, s);
				break;
			case 'p':
				scanf("%d", &i);
				printTime(&t[i]);
				printTime24(&t[i]);
				break;
			default:
				break;
		}
	}
	free(t);
	return 0;
}
