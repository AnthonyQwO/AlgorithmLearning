#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int m,n,speed;
int dx[]={-2,2,0,0}, dy[]={0,0,-2,2};

void shuffle( int arr[], int n );
void dfs( vector<vector<int>> &maze, int x, int y, int lx, int ly );
void print_maze( vector<vector<int>> &maze );
void print_path( vector<vector<pair<int,int>>> &vis,  vector<vector<int>> &maze, int x, int y );
void goto_xy( short int x, short int y );
int bfs( vector<vector<int>> maze, vector<int>& entrance );

int main()
{
    system("chcp 65001 & cls"); //if you want to use printf to print colored text must active chcp 65001
    printf("\033[?25l"); //hidden cursor
    srand(time(NULL));    
    //a maze's size is m rows n column
    //m,n should be odd number
    m=47, n=93; //m=47, n=93; FULL SCREEN
    speed=1; //the maze solver's speed. lower value has higher speed
    vector<vector<pair<int,int>>> vis;
    while(1) {
        vector<vector<int>> maze(m,vector<int>(n,1));
        vector<int> entrance={m-2,n-1};
        dfs(maze,1,1,1,1);
        maze[0][1]=maze[m-2][n-1]=0;
        print_maze(maze);
        printf(" %d steps\n",bfs(maze,entrance));
        system("PAUSE");
        system("cls");
    }    
}

void shuffle( int arr[], int n ) {
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
                    printf("\033[0m #"); //default color
                else if( maze[i][j] == 2 )
                    printf("\033[1;31;40m ."); //red
                else
                    printf("  ");
            }
            printf("\n");
        } 
}

int bfs( vector<vector<int>> maze, vector<int>& entrance ) {
    int res=0, m=maze.size(), n=maze[0].size();
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{entrance[0],entrance[1]},{entrance[0],entrance[1]}});
    vector<vector<pair<int,int>>> vis(n,vector<pair<int,int>>(n,{-1,-1}));
    vector<vector<int>> ormaze=maze;
    
    while( !q.empty() ) {
        int s=q.size();
        res++;
        for( int i=0 ; i < s ; i++ ) {
            int x=q.front().first.first, y=q.front().first.second;
            vis[x][y]=q.front().second;
            q.pop();
            if( maze[x][y] == 0 ) {
                maze[x][y] = 1;
                if( !( x == entrance[0] && y == entrance[1] ) && ( !x || !y || x >= m-1 || y >= n-1 ) ) {
                    print_path(vis,ormaze,0,1); //print_path(vis,ormaze,Exit x,Exit y)
                    return res;
                }
                for( int j=0 ; j < 4 ; j++ ) {
                    int newx=x+dx[j], newy=y+dy[j];
                    if( newx >= 0 && newy >= 0 && newx < m && newy < n && maze[newx][newy] == 0 ) q.push({{newx,newy},{x,y}});
                }
            }
        }
    }
    return -1;
}

void print_path( vector<vector<pair<int,int>>> &vis,  vector<vector<int>> &maze, int x, int y ) {
    if( x != m-2  || y != n-1 ) { //Entrance x and y
        goto_xy(y*2+1,x); //we print the space so y should be *2 and add one
        printf("\033[1;32;40m@"); //green
        Sleep(speed);
        goto_xy(y*2+1,x);
        printf("\033[1;32;40m.");
        maze[x][y]=2;
        print_path(vis,maze,vis[x][y].first,vis[x][y].second);
    }
    else {
        maze[x][y]=2;
        system("cls");
        print_maze(maze);
    }      
}

void goto_xy( short int x, short int y ) { //the fuction would move the cursor go to the coordinate on the screen
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={x,y};
    SetConsoleCursorPosition(hOut,pos);
}
