#include <stdio.h>

int findnum(unsigned int data[], int cur);

int main(){
    unsigned int data[1030];
    int row, column;
    char charone, charzero;

    scanf("%d %d\n", &column, &row);
    scanf("%c ", &charone);
    scanf("%c", &charzero);
    int size = sizeof(unsigned int)*8;
    int readNumCount = ((row*column)/size) + ((row*column)%size==0?0:1);
    int tmp = 0;
    for(int i=0; i<readNumCount; i++){
        scanf("%u", &data[i]);
    }
    int cur = 1;
    for(int r=0; r<row; r++){
        for(int c=0; c<column; c++){
            printf("%c", findnum(data, cur++) ? charone : charzero);
        }
        printf("\n");
    }
}

int findnum(unsigned int data[], int cur){
    int size = sizeof(unsigned int)*8;
    return data[(cur-1) / size] & ( 1 << ( cur%size == 0 ? 0 : size-(cur%size) ) ); 
}