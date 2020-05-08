#include <stdio.h>

int isValid(int number[], int sum, int num, int curSum, int curIndex);

int main(){
    int number[100],
        num;
    
    scanf("%d", &num);
    for(int i=0; i<num; i++)scanf("%d", &number[i]);

    int sum;
    while(scanf("%d", &sum) != EOF){
        printf("%d\n", isValid(number, sum, num, 0, 0));
    }
}

int isValid(int number[], int sum, int num, int curSum, int curIndex){
    if(sum == curSum && curIndex == num)
        return 1;
    else if(sum != curSum && curIndex == num)
        return 0;
    else return isValid(number, sum, num, curSum, curIndex+1) + isValid(number, sum, num, curSum+number[curIndex], curIndex+1);
}