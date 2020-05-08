#include <stdio.h>

int D[3], E[3], F[3], avail[3], value[11][11][11] = {0};
int N;
void callFunc(){
    if(!N--)return;
    scanf("%d%d%d", avail,avail+1,avail+2); printf("%s\n", value[avail[0]][avail[1]][avail[2]]?"yes":"no");
    callFunc();
}
void build(int d, int e, int f){
    int needA = d*D[0]+e*E[0]+f*F[0];
    int needB = d*D[1]+e*E[1]+f*F[1];
    int needC = d*D[2]+e*E[2]+f*F[2];
    if(needA > 10 ||
       needB > 10 ||
       needC > 10)
            return;
    value[needA][needB][needC]++;
    //printf("%d %d %d : %d %d %d\n", d,e,f,needA, needB, needC);
    build(d+1, e, f);
    build(d, e+1, f);
    build(d, e, f+1);
}

int main(){
    scanf("%d%d%d%d%d%d%d%d%d", D,D+1,D+2,E,E+1,E+2,F,F+1,F+2);
    scanf("%d", &N);
    build(0,0,0);
    callFunc();
}