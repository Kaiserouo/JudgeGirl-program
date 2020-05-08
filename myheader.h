#include <stdio.h>
#include <stdlib.h>
#define MAXD 100
typedef double Variable;    //< in scanf and printf, still use %f.

void input(int *row, int *column, Variable matrix[MAXD][MAXD]);
void process_matrix(int row, int column, Variable matrix[MAXD][MAXD]);
void output_matrix(int row, int column, Variable matrix[MAXD][MAXD]);
void setting();
void m_swap(int src, int dest, int row, int column, Variable matrix[MAXD][MAXD]);
void m_sub(int src, int dest, Variable mul, int row, int column, Variable matrix[MAXD][MAXD]);
void m_div(int src, Variable divider, int row, int column, Variable matrix[MAXD][MAXD]);
