/*
visited i j matrix
DFS_visit(i,j)

count=0
for(i):
    for(j):
    if(i j not 0 and not visited ij)
    DFSvisit(i,j)
    count++
*/
#include<iostream>
using namespace std;


class coord{
    public:
        int x;
        int y;
};
int **input;
bool **visited; 
coord* adjacent = new coord[8];
void get_adjacent(int i,int j){
    adjacent[0].x= i+1;
    adjacent[0].y=j+1;
    adjacent[1].x= i+1;
    adjacent[1].y=j;
    adjacent[2].x= i;
    adjacent[2].y=j+1;
    adjacent[4].x= i;
    adjacent[4].y=j-1;
    adjacent[5].x= i-1;
    adjacent[5].y=j-1;
    adjacent[6].x= i-1;
    adjacent[6].y=j;
    adjacent[7].x= i+1;
    adjacent[7].y=j-1;    
    adjacent[3].x= i-1;
    adjacent[3].y=j+1;
}
bool ingrid(int i,int j,int n,int m){
    return (i<n && i>=0 && j>=0 && j<m);
}
void dfs_visit(int n,int m,int i, int j){
    visited[i][j]=true;
    get_adjacent(i,j);
    for(int a=0;a<8;a++){
        if(ingrid(adjacent[a].x,adjacent[a].y,n,m)  && !(visited[adjacent[a].x][adjacent[a].y]))
            dfs_visit(n,m,adjacent[a].x,adjacent[a].y);
    }

}
int solution(int n,int m){
    visited = new bool*[n];

    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(input[i][j] && !visited[i][j]){
                dfs_visit(n,m,i,j);

                count++;
            }


        }
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    input = new int*[n];
    for(int i=0;i<n;i++){
        input[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }  
    cout<<solution(n,m)<<endl; 
}