#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD 1
#define SPACE -1

void output(char word[][200], int wordCount, int sumLength, int maxChar);

int main(){
    char word[200][200],
        str[200];
    int sumLength = 0;
    int maxChar;
    int wordCount = 0;
    
    scanf("%d", &maxChar);
    while(scanf("%s", str) != EOF){
        int length = strlen(str);
        if(wordCount + sumLength + length <= maxChar){
            sumLength += length;
            strcpy(word[wordCount++], str);
        }
        else{   //exceed length
            output(word, wordCount, sumLength, maxChar);
            strcpy(word[0], str);
            wordCount = 1;
            sumLength = length;
        }
    }
    output(word, wordCount, sumLength, maxChar);
}

void output(char word[][200], int wordCount, int sumLength, int maxChar){
    int numSpace = maxChar - sumLength;
    int numBetween = wordCount==1? wordCount : wordCount-1;

    int quotient = numSpace / numBetween;
    int remainder = numSpace % numBetween;

    int flag = WORD;
    for(int i=0; i<(wordCount+numBetween); i++){
        switch(flag){
        case WORD:
            printf("%s", word[i/2]);
            break;
        case SPACE:
            for(int j = 0; j < quotient; j++)printf(" ");
            if(remainder>0){
                printf(" "); remainder--;
            }
        }
        flag *= -1;
    }
    printf("\n");

}