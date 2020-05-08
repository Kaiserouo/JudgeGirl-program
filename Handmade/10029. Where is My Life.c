/*
**  Note that this program is a little bit different compared to last program:
**  
**  1, data in int, use floor(d+0.5) to do the rounding
**  2, overdetermined system dealt with, but specified that constant only one line
**  
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXD 200
#define OVERDETERMINED 0
int width = 2;
int precision = 1;
int space_between_line = 0;
char symbol[] = {'-', '-', '-', '-', '|'};
enum Symbol {TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT, MIDDLE};
enum {ROW, COLUMN};
typedef double Variable;    //< in scanf and printf, still use %f.

void input(int *row, int *column, Variable matrix[MAXD][MAXD]);
void process_matrix(int row, int column, Variable matrix[MAXD][MAXD]);
void output_matrix(int row, int column, Variable matrix[MAXD][MAXD]);
void setting();
void m_swap(int src, int dest, int row, int column, Variable matrix[MAXD][MAXD]);
void m_sub(int src, int dest, Variable mul, int row, int column, Variable matrix[MAXD][MAXD]);
void m_div(int src, Variable divider, int row, int column, Variable matrix[MAXD][MAXD]);

/* main */
int main(){
    int row, column;
    char c;
    Variable matrix[MAXD][MAXD] = {0.0};
    int status[MAXD];
    Variable num[MAXD];
    while(scanf("%d%d", &row, &column) != EOF){
        column++;
        int output = 0;
        input(&row, &column, matrix);
        for(int i=0; i<MAXD; i++)status[i] = num[i] = 0;
        process_matrix(row, column, matrix);  
        //output_matrix(row, column, matrix);  
        for(int i=0; i<row; i++){
            int flag = 0;
            int record;
            for(int j=0; j<column-1; j++)
                if(floor(matrix[i][j] + 0.5) != 0)flag++, record = j;
            if(flag == 0)
                if(floor(matrix[i][column-1] + 0.5) != 0.0){printf("contradictory\n"); output = 1; break;}
            if(flag == 1){
                status[record] = 1; num[record] = matrix[i][column-1];
            }
        }
        int sum = 0;
        for(int i=0; i<column-1; i++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp && status[i])sum += floor(num[i]+0.5);
            if(tmp && !status[i] && output!=2 && output!=1){printf("not sure\n"); output = 2;}
        }
        if(!output)printf("%d\n", sum);
    }
    
    return 0;
}

/* function */

void input(int *row, int *column, Variable matrix[MAXD][MAXD]){
    for(int i=0; i<*row; i++)
        for(int j=0; j<*column; j++)
            scanf("%lf", &matrix[i][j]);
}
void process_matrix(int row, int column, Variable matrix[MAXD][MAXD]){
    int pivot[2] = {0, 0};
    while(pivot[ROW] < row && pivot[COLUMN] < column-1){  //< in range
        if(matrix[pivot[ROW]][pivot[COLUMN]] == 0.0){ //< if element = 0
            int flag = 0;
            for(int r=pivot[ROW]; r<row; r++)
                if(matrix[r][pivot[COLUMN]] != 0.0){
                    m_swap(r, pivot[ROW], row, column, matrix);
                    flag++;
                    break;
                }
            if(flag == 0)pivot[COLUMN]++;
            continue;
        }

        /* element != 0 */
        for(int r=pivot[ROW]; r<row; r++)
            if(matrix[r][pivot[COLUMN]] == 1.0){
                m_swap(r, pivot[ROW], row, column, matrix);
                break;
        }
        m_div(pivot[ROW], matrix[pivot[ROW]][pivot[COLUMN]], row, column, matrix);
        for(int i=0; i<row; i++)
            if(i!=pivot[ROW])m_sub(pivot[ROW], i, matrix[i][pivot[COLUMN]], row, column, matrix);
        pivot[ROW]++; pivot[COLUMN]++;

        
    }
    for(int i=0; i<row; i++){
        if(matrix[i][column-1] == 0)matrix[i][column-1] = 0;
    }

}
void output_matrix(int row, int column, Variable matrix[MAXD][MAXD]){
    for(int i=-1; i<row+1; i++){
        printf("%-*c ", width, 
            i==-1?symbol[TOPLEFT]:
            i==row?symbol[BOTTOMLEFT]:
            symbol[MIDDLE]
        );

        for(int j=0; j<column; j++){
            if(i==-1 || i==row)printf("%*c ", width, ' ');
            else printf("%*.*lf ", width, precision, matrix[i][j]);
        }

        printf("%*c\n", width, 
            i==-1?symbol[TOPLEFT]:
            i==row?symbol[BOTTOMLEFT]:
            symbol[MIDDLE]
        );

        if(space_between_line && i!=-1 && i!=row-1 && i!=row){
            printf("%-*c ", width, symbol[MIDDLE]);
            for(int j=0; j<column; j++)printf("%-*c ", width, ' ');
            printf("%*c\n", width, symbol[MIDDLE]);
        }
    }
}
void setting(){

}
void m_swap(int src, int dest, int row, int column, Variable matrix[MAXD][MAXD]){
    Variable tmp = 0;
    for(int i=0; i<column; i++)
        tmp=matrix[src][i], matrix[src][i]=matrix[dest][i], matrix[dest][i]=tmp;
}
void m_sub(int src, int dest, Variable mul, int row, int column, Variable matrix[MAXD][MAXD]){
    for(int i=0; i<column; i++){
        matrix[dest][i] -= matrix[src][i]*mul;
        if(matrix[dest][i] == 0.0)matrix[dest][i] = 0;
    }
        
}
void m_div(int src, Variable divider, int row, int column, Variable matrix[MAXD][MAXD]){
    for(int i=0; i<column; i++){
        matrix[src][i] /= divider;
        if(matrix[src][i] == 0.0)matrix[src][i] = 0;
    }
        
}
/*3.1: 45 92 80 84 6 58 80 42 80 82 51 90 50 82 0 63 81 88 42 4 15 16 70 76 2 95 39 75 92 46 28 9 76 83 69 77 39 39 48 37 4 89 53 40 5 10 47 48 8 97 78 86 20 97 74 42 99 49 37 91 51 91 83 58 44 64 57 45 14 94 77 28 76 19 0*/

