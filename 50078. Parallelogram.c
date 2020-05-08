#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct{
    int x, y;
} Point;

int main(){
    Point A, B, C;
    scanf("%d%d%d%d%d%d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
    printf("%d\n%d\n", B.x + C.x - A.x, B.y + C.y - A.y);   // D = B + C - A;
    printf("%d\n%d\n", A.x + C.x - B.x, A.y + C.y - B.y);   // E = A + C - B;
    printf("%d\n%d\n", A.x + B.x - C.x, A.y + B.y - C.y);   // F = A + B - C;
}