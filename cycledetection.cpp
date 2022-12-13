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
bool cycle_detected = false;
int prevnode;
void dfs_visit(int n,int m,int i){
    if(cycle_detected)
        return;
    visited[i] = true;
    
    for(int j=0;j<n;j++){
        if(!visited[j] && input[i][j]==1 ){
            prevnode= i;
            dfs_visit(n,m,j);
        }
        else if(input[i][j]==1 && j!=prevnode){

            cycle_detected = true;
            return;
        }


    }

}
void getsolution(int n,int m){
    visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){

            dfs_visit(n,m,i);
            if(cycle_detected)
                break;
        }   
    }

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
            input[i][j] = -1;//-1 means disconnected
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        input[a-1][b-1]=1;
        input[b-1][a-1]=1;
    }
    getsolution(n,m);
    string ans = cycle_detected ? ("Yes"):"No";
    cout<<ans<<endl;
    
}