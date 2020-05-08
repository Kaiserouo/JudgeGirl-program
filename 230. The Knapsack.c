#include <stdio.h>

int numItem, weightBag, itemWeight[30], itemValue[30];
int max = 0;

void bag(int curWeight, int curValue, int curNum){
    if(curWeight < 0)return;
    
    max = max<curValue ? curValue : max;
    if(curNum < numItem)bag(curWeight - itemWeight[curNum], curValue + itemValue[curNum], curNum + 1), bag(curWeight, curValue, curNum + 1);
}

int main(){
    scanf("%d%d", &numItem, &weightBag);
    for(int i=0; i<numItem; i++)scanf("%d%d", &itemWeight[i], &itemValue[i]);

    bag(weightBag, 0, 0);
    printf("%d", max);
}