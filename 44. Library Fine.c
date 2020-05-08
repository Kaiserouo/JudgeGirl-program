#include <stdio.h>
//< header given
#ifndef BOOK_H
#define BOOK_H
 
enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};
 
#endif
#ifndef DATE_H
#define DATE_H
 
struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};
 
#endif

/* function */
#define year(i) ((i%400==0||(i%4==0&&i%100!=0))?(366):(365))
unsigned int count_day(struct Date date)
{
    unsigned int mon_day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(year(date.year) == 366)mon_day[2]++;
    unsigned int sum = 0;
    for(int i = 0; i < date.month; i++){
        sum += mon_day[i];
    }
    return sum + date.day;
}
unsigned int period(struct Date date_borrowed, struct Date date_returned)
{
    
    unsigned int delta_year = 0;   
    unsigned int delta_borrowed = 0; 
    unsigned int delta_returned = 0;

    // delta year
    for(int i = date_borrowed.year; i < date_returned.year; i++){
        delta_year += year(i);
    } 

    // delta day from 1/1
    delta_borrowed = count_day(date_borrowed);
    delta_returned = count_day(date_returned);

    return delta_year + delta_returned - delta_borrowed + 1;
}
unsigned int type(enum Type type)
{
    switch (type)
    {
    case NOVEL:
        return 90;
        break;
    case COMICS:
        return 10;
        break;
    case MANUAL:
        return 100;
        break;
    case TEXTBOOK:
        return 5;
        break;

    }
}
unsigned int calc_imp(unsigned int i)
{
    int flag = 0;
    int counter = 0;
    for(int j = 0; j < sizeof(unsigned int)*8; j++){
        if(!(i & 1<<j) && flag){
            counter++;
        }else if(i & 1<<j){
            if(flag == 0)flag++;
            else return counter;
        }
    }
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
    int due_day = period(date_borrowed, date_returned) - type(book.type);
    unsigned int important = calc_imp(book.importance);
    printf("%d %u\n", due_day, important);
    if(due_day <= 0)return 0;
    else return due_day * important;
}

int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2004;
    date_borrowed.month = 2;
    date_borrowed.day   = 21;
    date_returned.year  = 2004;
    date_returned.month = 3;
    date_returned.day   = 1;
    printf("The fine is $%d %ld.\n", library_fine(book, date_borrowed, date_returned), sizeof(unsigned int));
    return 0;
    __builtin_
}