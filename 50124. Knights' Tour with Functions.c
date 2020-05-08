#include <stdio.h>

#define MAXN 100
#define DEBUG 1
int visited[MAXN][MAXN]={0};
int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
#if DEBUG == 1
int validMoveNum(int r, int c, int n, int visited[100][100])
{
        //int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        if( !(r<n && r>=0 && c<n && c>=0) )
            return -1;
        int VMN=0;    //< number to return
        for(int i=0;i<8;i++){
            if( !(r+move[i][0]<n && r+move[i][0]>=0 && c+move[i][1]<n && c+move[i][1]>=0 ))
                continue;
           else if((visited[ r+move[i][0] ][ c+move[i][1] ]) == 0)
                VMN++;
        }
        return VMN;
}
int nextMove(int r, int c, int n, int visited[100][100]){
    //int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int leastMove=99, leastIndex=-1;
    int hasLogged=0;
    if(validMoveNum(r, c, n, visited) <= 0)return -1;
    for(int i=0;i<8;i++){
        if((r+move[i][0]<n && r+move[i][0]>=0 && c+move[i][1]<n && c+move[i][1]>=0 ) && visited[r+move[i][0]][c+move[i][1]] == 0 && !hasLogged){
            leastMove=validMoveNum(r+move[i][0], c+move[i][1], n, visited);
            leastIndex=i; hasLogged=1;
            continue;
        }
        else if(visited[r+move[i][0]][c+move[i][1]] == 0){
            int tmp=validMoveNum(r+move[i][0], c+move[i][1], n, visited);
            if(tmp != -1 && tmp < leastMove){
                leastIndex=i; leastMove=tmp;
            }
        }
    }
    return leastIndex;
}
#endif
int main(){
    int n,  //< board size
        m;  //< number of knights
    scanf("%d",&n);
    scanf("%d",&m);
    int pos[m][2];
    for(int i=0; i<m; i++){
        scanf("%d%d", &pos[i][0], &pos[i][1]);
        visited[ pos[i][0] ][ pos[i][1] ] = 10000*(i+1);
    }

    int stopFlag = 0;
    int stop[m];
    for(int i=0; i<m; i++)stop[i]=0;
    int time=0;

    while(stopFlag < m){    //< run until all knights cannot move
        time++;

        for(int i=0; i<m; i++){    //< all m knights
            if(stop[i])continue;
            int tmp=nextMove(pos[i][0], pos[i][1], n, visited);
            if(tmp == -1){
                stopFlag++;
                stop[i] = 1;
            }
            else{
                pos[i][0] += move[tmp][0];
                pos[i][1] += move[tmp][1];
                visited[ pos[i][0] ][ pos[i][1] ] = 10000*(i+1) + time;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d",visited[i][j]);
            if(j!=n-1)printf(" ");
        }
        printf("\n");
    }
    
    
}