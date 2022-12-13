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
#include <limits.h>
using namespace std;



int **input;
bool *visited; 

void dfs_visit(int n,int m,int i){
    visited[i] = true;
    for(int j=0;j<n;j++){
        if(!visited[j] && input[i][j]<INT_MAX )
            dfs_visit(n,m,j);

    }

}
int solution(int n,int m){
    visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs_visit(n,m,i);
            count++;
        }   
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    input = new int*[n];
    for(int i=0;i<n;i++){
        input[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i!=j)
                input[i][j]=INT_MAX;
            else
                input[i][i]=0;
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        input[a-1][b-1]=1;
        input[b-1][a-1]=1;
    }
    cout<<solution(n,m)<<endl; 
}