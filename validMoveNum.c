int validMoveNum(int r, int c, int n, int visited[100][100])
{
          int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        if( !(r<n && r>=0 && c<n && c>=0) )
            return -1;
        int VMN=0;    //< number to return
        for(int i=0;i<8;i++){
            if( !(r+move[i][0]<n && r+move[i][0]>=0 && c+move[i][1]<n && c+move[i][1]>=0 ))
                continue;
            if((visited[ r+move[i][0] ][ c+move[i][1] ]) == 0)
                VMN++;
        }
        return VMN;
}