#include <bits/stdc++.h>
using namespace std;

const int N=8; //size of the chess board

bool check( vector<string>& board, int x, int y, int n ) {
    for( int i=x-1 ; i >= 0 ; i-- ) if( board[i][y] == 'Q' ) return 0;
    for( int i=x-1, j=y-1 ; i >= 0 && j >= 0 ; i--, j-- ) if( board[i][j] == 'Q' ) return 0;
    for( int i=x-1, j=y+1 ; i >= 0 && j < n ; i--, j++ ) if( board[i][j] == 'Q' ) return 0;
    return 1;
}

void Nqueen( vector<vector<string>>& res, vector<string>& board, int step, int n ) {
    if( step < n ) {
        for( int i=0 ; i < n ; i++ ) {
            if( check(board,step,i,n) ) {
                board[step][i]='Q';
                Nqueen(res,board,step+1,n);
                board[step][i]='.';
            }
        }
    }
    else res.push_back(board);
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n,string(n,'.'));
    Nqueen(res,board,0,n);
    return res;
}

void printallresult( vector<vector<string>> res ) {
    for( int i=0 ; i < res.size() ; i++ ) {
        for( int j=0 ; j < N ; j++ ) {
            for( int k=0 ; k < N ; k++ ) 
                printf("%c ",res[i][j][k]);
            printf("\n");
        }                
        printf("\n");
    }
}

int main()
{
    vector<vector<string>> res=solveNQueens(N);
    printallresult(res);
}