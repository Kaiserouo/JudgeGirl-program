#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* structure */
typedef struct{
    char name[80],
        ingredient[10][80];
    int numIngr;
} Food;

/* function header */
void compare(Food food[], int numFood, char str[][80]);
int diccmp(const void *str1, const void *str2){
    return strcmp((char *)str1, (char *)str2);
}

int main(){
    Food food[120];
    int numFood = 0;
    scanf("%d", &numFood);
    // input
    for(int i=0; i<numFood; i++){
        scanf("%s%d", food[i].name, &food[i].numIngr);
        for(int j=0; j<food[i].numIngr; j++){
            scanf("%s", food[i].ingredient[j]);
        }
    }
    char str[2][80];    //< 2 food to compare
    int numCmp = 0;
    scanf("%d", &numCmp);
    for(int i=0; i<numCmp; i++){
        scanf("%s%s", str[0], str[1]);
        compare(food, numFood, str);
    }
    return 0;
}

/* function */
void compare(Food food[], int numFood, char str[][80]){
    int index[2];   //< to store food index

    for(int i=0; i<numFood; i++){//< find food index
        for(int j=0; j<2; j++){
            if(!strcmp(food[i].name, str[j])){
                index[j] = i;
            }
        }
    }

    //find common
    char commonIngr[12][80];
    int numCommon = 0;
    for(int i=0; i<food[index[0]].numIngr; i++){
    for(int j=0; j<food[index[1]].numIngr; j++)
        if(!strcmp(food[index[0]].ingredient[i], food[index[1]].ingredient[j])){    //< find common
            strcpy(commonIngr[numCommon], food[index[0]].ingredient[i]);
            numCommon++;
        }
    }

    //if dont have common, return
    if(numCommon == 0){
        printf("nothing\n");
        return;
    }

    //if have common, sort and print
    int tmp = numCommon;
    qsort(commonIngr, tmp, 80*sizeof(char), diccmp);

    for(int i=0; i<numCommon; i++){
        printf("%s", commonIngr[i]);
        if(i!=numCommon-1)printf(" ");
    }
    printf("\n");

}
