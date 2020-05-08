#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

void calc_gpa(int *score_100, double *score_gpa, char str[]){
    char gpa[10][3] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F"};
    int score[10] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50};
    double gpa_score[10] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 0};
    switch(*score_100){
    case 90 ... 100	:
        *score_100 = score[0];
        *score_gpa = gpa_score[0];
        strcpy(str, gpa[0]);
        break;
    case 85 ... 89	:
        *score_100 = score[1];
        *score_gpa = gpa_score[1];
        strcpy(str, gpa[1]);
        break;
    case 80 ... 84	:
        *score_100 = score[2];
        *score_gpa = gpa_score[2];
        strcpy(str, gpa[2]);
        break;
    case 77 ... 79	:
        *score_100 = score[3];
        *score_gpa = gpa_score[3];
        strcpy(str, gpa[3]);
        break;
    case 73 ... 76	:
        *score_100 = score[4];
        *score_gpa = gpa_score[4];
        strcpy(str, gpa[4]);
        break;
    case 70 ... 72	:
        *score_100 = score[5];
        *score_gpa = gpa_score[5];
        strcpy(str, gpa[5]);
        break;
    case 67 ... 69	:
        *score_100 = score[6];
        *score_gpa = gpa_score[6];
        strcpy(str, gpa[6]);
        break;
    case 63 ... 66	:
        *score_100 = score[7];
        *score_gpa = gpa_score[7];
        strcpy(str, gpa[7]);
        break;
    case 60 ... 62	:
        *score_100 = score[8];
        *score_gpa = gpa_score[8];
        strcpy(str, gpa[8]);
        break;
    case 0 ... 59	:
        *score_100 = score[9];
        *score_gpa = gpa_score[9];
        strcpy(str, gpa[9]);
        break;
    }
}

void print(int *score_100, double *score_gpa){
    #ifdef HUNDRED

    printf("%d ", *score_100);

    #else
    #ifdef APLUS

    char str[10];
    calc_gpa(score_100, score_gpa, str);
    printf("%s ", str);
    
    #endif
    #endif
}

void print_avg(int sum_100, double sum_gpa, double num){
    #ifdef HUNDRED

    printf("%.1f\n", sum_100 / num);

    #else
    #ifdef APLUS

    printf("%.1f ", sum_gpa / num);
    printf("%.1f\n", sum_100 / num);
    
    #endif
    #endif
}


int main(){
    double sum_100 = 0;
    double sum_gpa = 0;
    double num = 0;
    int score_100 = 0;
    double score_gpa = 0;
    while(scanf("%d", &score_100) != EOF){
        print(&score_100, &score_gpa);
        sum_100 += score_100;
        sum_gpa += score_gpa;
        num++;
    }
    print_avg(sum_100, sum_gpa, num);
}