#include <stdio.h>
#include <stdlib.h>
 
void print(int *tmp, int num){
    for(int i = 0; i < num; i++){
        printf("%d%s", tmp[i], i==num-1?"\n":" ");
    }
}
int permutation(int i, int num, int *data, int *tmp){
    if(i == num){
        print(tmp, num);
    }
    else{
        for(int j = 0; j < num; j++){   //< number currently considering
            // see if exist before
            int flag = 0;
            for(int k = 0; k < i; k++){
                if(data[j] == tmp[k])flag = 1;
            }
            if(flag == 1)continue;
 
            tmp[i] = data[j];
            permutation(i+1, num, data, tmp); 
        }
    }
}
int compare(const void *a, const void *b){
    return *((int *)a) - *((int *)b);    
}
 
int main(){
    int num;
    scanf("%d", &num);
    int *data = malloc(num * sizeof(int));
    for(int i = 0; i < num; i++){
        scanf("%d", data + i);
    }
    qsort(data, num, sizeof(int), compare);
    int *tmp = malloc(num * sizeof(int));
    permutation(0, num, data, tmp);
}