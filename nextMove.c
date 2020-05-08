int nextMove(int r, int c, int n, int visited[100][100]){
      int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int leastMove=99, leastIndex=-1;
    for(int i=0;i<8;i++){
        int tmp=validMoveNum(r+move[i][0], c+move[i][1], n, visited);
        if(tmp >= 0 && tmp < leastMove){
            leastIndex=i; leastMove=tmp;
        }
    }
    return leastIndex;
}