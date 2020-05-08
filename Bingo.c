#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define DEBUG 0

int main(){

    int numPlayer,m;

    scanf("%d%d",&numPlayer,&m);

    int status[numPlayer][m*m][2];  //numPlayer,num for num on board, num for row&column
                                    //->input num and show row&column!! 0:r,1:c
    int colume[numPlayer][m],row[numPlayer][m],slant[numPlayer][2];  // 0:\ 1:/
    char c[numPlayer][64];
    int win[m],numWin=0;    //store who win in that step
#if DEBUG==1
printf("\nInput numPlayer & m successful");
#endif // DEBUG
    //initialization
    for(int i=0;i<numPlayer;i++){
        for(int j=0;j<m;j++){
            colume[i][j]=row[i][j]=0;
        }
        slant[i][1]=slant[i][0]=0;
    }
#if DEBUG==1
printf("\ninitialization successful");
#endif // DEBUG

    //input
    for(int i=0;i<numPlayer;i++){
        scanf("%s",c[i]);
        for(int r=0;r<m;r++)
        for(int c=0;c<m;c++){
            int temp;
            scanf("%d",&temp);
            status[i][temp][0]=r;
            status[i][temp][1]=c;
        }
    }
#if DEBUG==1
printf("\nAll input of bingo map successful");
printf("\nStart playing...\n");
#endif // DEBUG
    //run bingo
    int temp;
    for(int i=0;i<(m*m);i++){ //for every number
        scanf("%d",&temp);
#if DEBUG==1
printf("\nInput bingo number successful");
#endif // DEBUG
        for(int n=0;n<numPlayer;n++){   //for every person
            //add row/column count
            colume[n][status[n][temp][1]]++;
            row[n][status[n][temp][0]]++;
#if DEBUG==1
printf("\nRow/column added");
printf("\n%s:Add %d, which is in (%d,%d)",c[n],temp,status[n][temp][0],status[n][temp][1]);
printf("\n  currently row %d:%d,column %d:%d",status[n][temp][0],row[n][status[n][temp][0]],status[n][temp][1],colume[n][status[n][temp][1]]);
#endif // DEBUG
            //if valid, add slant count
            if(status[n][temp][1]==status[n][temp][0])
                slant[n][0]++;
            if(status[n][temp][1]+status[n][temp][0]==m-1)
                slant[n][1]++;

            //determine if win after added
            for(int k=0;k<m;k++){
                if(colume[n][status[n][temp][1]]==m || row[n][status[n][temp][0]]==m
                    || slant[n][0]==m || slant[n][1]==m){
                    //win, add to win list
                    win[numWin]=n;
                    numWin++;
                    break;
                }
            }

        }

        //if someone wins, jump out of game
        if(numWin>0){
                #if DEBUG==1
printf("\nWins, out of loop");
#endif // DEBUG
            printf("%d ",temp);
            break;
        }
    }
#if DEBUG==1
printf("\nOutputting\n");
#endif // DEBUG
    //game finished, output
    for(int i=0;i<numWin;i++){
        printf("%s",c[win[i]]);
        if(i!=numWin-1)printf(" ");
    }
}
