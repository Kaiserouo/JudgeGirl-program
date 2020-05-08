#include <stdio.h>
#include <stdbool.h>

#define DEBUG 0

typedef struct{
    int n;//store input
    int numPal;// store num of palindrome starting at this input
    int palLength[100];//store length of all palindrome starting here
} Number;

//check if this input and length is a palindrome
bool check(int inputNum,int length,int num,Number c[100]){
    for(int i=0;i<(length+1)/2;i++){
        if(c[inputNum+i].n != c[inputNum+length-1-i].n)return 0;
    }
    return 1;
}

int main(){

    Number a[100];  //store input and
    int num=0;     //number of input

    //input:number
    int temp;
#if DEBUG==0
    while(scanf("%d",&temp) != EOF){
        a[num].n=temp;
        num++;
    }
#endif // DEBUG
#if DEBUG==1
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&temp);
        a[i].n=temp;
    }
#endif

    //initialization: all numPal start at 0
    for(int i=0;i<num;i++){
        a[i].numPal=0;
    }

    //search all palindrome possible
    for(int i=0;i<num;i++){ //for every input i
        for(int j=1;j<=num-i;j++){  //for every possible length of palindrome j
            if(check(i,j,num,a)){   //if is a palindrome
                //add to palindrome list
                a[i].palLength[ a[i].numPal ]=j;
                a[i].numPal++;
            }
        }
    }

    //search all possible double palindrome
    int currentBiggestCount=0;
    int currentBiggestStartLoc=0;

    for(int i=0;i<num-1;i++){   //for every input
        for(int j=0;j<a[i].numPal;j++){  //for all palindrome on this input
            /*currently deal w/ a[i].palLength[j]*/
            if(i+a[i].palLength[j]==num)continue;//if already at max num, then its impossible to have 2nd one


            for(int k=0;k<a[ i+a[i].palLength[j] ].numPal;k++){//for all palindrome after first palindrome
                /*currently dealing with a[ i+a[i].palLength[j] ].palLength[k]*/
                int wordCount=a[i].palLength[j] + a[ i+a[i].palLength[j] ].palLength[k];

                //see if length can anew(bigger or equal)
                //if can, anew current recorded input and length
                if(wordCount<currentBiggestCount)continue;  //not big enough, cont.
                else{
                    currentBiggestCount=wordCount;
                    currentBiggestStartLoc=i;
                }
            }
        }
    }

    //output double palindrome by 1&2's recorded place & length
    for(int i=currentBiggestStartLoc;i<currentBiggestStartLoc+currentBiggestCount;i++){
        printf("%d",a[i].n);
        if(i!=currentBiggestStartLoc+currentBiggestCount-1)printf(" ");
    }


}
