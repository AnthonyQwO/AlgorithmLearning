#include <bits/stdc++.h>
using namespace std;

int m,n;
int dx[]={-2,2,0,0}, dy[]={0,0,-2,2};

void shuffle( int arr[] , int n );
void dfs( vector<vector<int>> &maze, int x, int y, int lx, int ly );
void print_maze( vector<vector<int>> &maze );

int main()
{
    srand(time(NULL));
    //a maze's size is m rows n column
    //m,n should be odd number
    m=29, n=29;//m=47, n=93; FULL SCREEN
    while(1) {
        vector<vector<int>> maze(m,vector<int>(n,1));
        dfs(maze,1,1,1,1);
        maze[0][1]=maze[m-2][n-1]=0;
        print_maze(maze);
        system("PAUSE");
        system("cls");
    }    
}

void shuffle( int arr[] , int n ) {
    for( int i=0 ; i < n ; i++ ) {
        int t=rand()%n;
        swap(arr[i],arr[t]);
    }
}

void dfs( vector<vector<int>> &maze, int x, int y, int lx, int ly ) {
    if( x < 0 || y < 0 || x >= m || y >= n || !maze[x][y] )
        return;
    maze[x][y]=maze[(x+lx)/2][(y+ly)/2]=0;
    int rand_dir[]={0,1,2,3};
    shuffle(rand_dir,4);
    for( int i=0 ; i < 4 ; i++ ) {        
        int newx=x+dx[rand_dir[i]], newy=y+dy[rand_dir[i]];
        if( x >= 0 && y >= 0 && x < m && y < n )
            dfs(maze,newx,newy,x,y);
    }
}

void print_maze( vector<vector<int>> &maze ) {
   for( int i=0 ; i < m ; i++ ) {
            for( int j=0 ; j < n ; j++ ) {
                if( maze[i][j] == 1 )
                    printf(" #");
                else
                    printf("  ");
            }
            printf("\n");
        } 
}