#include <bits/stdc++.h>
using namespace std;

void printarr(vector<vector<char>> board) {
    for( int i=0 ; i < 9 ; i++ ) {
        for( int j=0 ; j < 9 ; j++) printf("%c ",board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool check( vector<vector<char>>& board, int x, int y, char cmp ) {
    for( int i=0 ; i < 9 ; i++ ) if( ( board[x][i] == cmp && i != y ) || ( board[i][y] == cmp && i != x ) ) return 0;
    x=x/3*3, y=y/3*3;
    for( int i=0 ; i < 3 ; i++ ) for( int j=0 ; j < 3 ; j++ ) if( board[i+x][j+y] == cmp ) return 0;
    return 1;
}

bool solveSudoku( vector<vector<char>>& board ) {
    for( int i=0 ; i < 9 ; i++ ) for( int j=0 ; j < 9 ; j++ )
        if( board[i][j] == '.' ) {
            for( char c='1' ; c <= '9' ; c++ ) {
                if( check(board,i,j,c) ) {
                    board[i][j]=c;
                    if( solveSudoku(board) ) return 1;
                    board[i][j]='.';
                }
            }
            return 0;
        }
    return 1;
}

int main()
{
    vector<vector<char>> board= {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    printarr(board);
    solveSudoku(board);
    printarr(board);
}