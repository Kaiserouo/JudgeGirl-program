/*
**  This is a program to perform gaussian elimination.
**  
**  Todo list : ways to use fraction as input (may be easier if used C++)
**              overdetermined system (current: warn user that input invalid)
**              setting page (thought unnecessary, can be added)
**              
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXD 100
#define OVERDETERMINED 0
int width = 5;
int precision = 2;
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
    Variable matrix[MAXD][MAXD] = {0};
    Start:
    input(&row, &column, matrix);
    output_matrix(row, column, matrix);
    process_matrix(row, column, matrix);
    output_matrix(row, column, matrix);
    printf("Press enter to continue.\n");
    c=getchar();
    c=getchar();
    if(c == '\n')goto Start;
    return 0;
}

/* function */

void input(int *row, int *column, Variable matrix[MAXD][MAXD]){
    int flag = 0;
    do{
        printf("Enter matrix size ( row x column ) :\n");
        scanf("%d", row);
        if(*row <= 0){
            setting();continue;
        }
        scanf("%d", column);
        if(*column <= 0 || (!OVERDETERMINED && (*row>*column)))
            printf("Invalid input.\n"), flag = 1;
        else flag = 0;
    }while(flag == 1);
    
    printf("Enter matrix element :\n");
    for(int i=0; i<*row; i++)
        for(int j=0; j<*column; j++)
            scanf("%lf", &matrix[i][j]);
}
void process_matrix(int row, int column, Variable matrix[MAXD][MAXD]){
    int pivot[2] = {0, 0};
    while(pivot[ROW] < row && pivot[COLUMN] < column){  //< in range
        if(matrix[pivot[ROW]][pivot[COLUMN]] == 0){ //< if element = 0
            int flag = 0;
            for(int r=pivot[ROW]; r<row; r++)
                if(matrix[r][pivot[COLUMN]] != 0){
                    m_swap(r, pivot[ROW], row, column, matrix);
                    flag++;
                    break;
                }
            if(flag == 0)pivot[COLUMN]++;
            continue;
        }

        /* element != 0 */
        m_div(pivot[ROW], matrix[pivot[ROW]][pivot[COLUMN]], row, column, matrix);
        for(int i=0; i<row; i++)
            if(i!=pivot[ROW])m_sub(pivot[ROW], i, matrix[i][pivot[COLUMN]], row, column, matrix);
        pivot[ROW]++; pivot[COLUMN]++;
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
            else printf("%*.*f ", width, precision, matrix[i][j]);
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
        if(matrix[dest][i] == 0)matrix[dest][i] = 0;
    }
        
}
void m_div(int src, Variable divider, int row, int column, Variable matrix[MAXD][MAXD]){
    for(int i=0; i<column; i++){
        matrix[src][i] /= divider;
        if(matrix[src][i] == 0)matrix[src][i] = 0;
    }
        
}
