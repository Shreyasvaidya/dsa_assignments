#include <iostream>
#include <limits.h>
using namespace std;
int ** input;
int get_min(int* givenarr,bool* visited,int n){
    int mindist=INT_MAX;
    int ans;
    for(int i=0;i<n;i++){
        if(givenarr[i]<mindist && !visited[i]){
            mindist = givenarr[i];
            ans = i;
        }
    }
    return ans;
}
void update(int node,int* givenarr,int n_nodes){
    for(int i=0;i<n_nodes;i++){
        if(input[node][i]<INT_MAX){
            if(givenarr[node]+input[node][i]<givenarr[i])
                givenarr[i] = givenarr[node]+input[node][i];
        }
    }
}
void djakstra(int start,int* givenarr,int n_nodes){
    bool * visited = new bool[n_nodes];
    for(int i=0;i<n_nodes;i++){
        visited[i]=false;
    }
    visited[start] = true;
    givenarr[start]=0;
    int curr=start ;
    for(int _=0;_<n_nodes-1;_++){
        update(curr,givenarr,n_nodes);

        curr = get_min(givenarr,visited,n_nodes);
        visited[curr]= true;
        

    }
    
}
int main(){
    int n_nodes,n_edges;
    cin>>n_nodes>>n_edges;
    input = new int*[n_nodes];
    for(int i=0;i<n_nodes;i++){
        input[i]= new int[n_nodes];
    }
    for(int i=0;i<n_nodes;i++){
        for(int j=0;j<n_nodes;j++){
            input[i][j] = (i-j)*(i-j);
        }

        
    }
    for(int i=0;i<n_edges;i++){
        int n1,n2;
        cin>>n1>>n2;
        input[n1-1][n2-1] = 0;
        input[n2-1][n1-1] = 0;
        
    }
    int * output = new int[n_nodes];
    for(int i=0 ;i<n_nodes;i++){
        output[i]=INT_MAX;
    }
    djakstra(0,output,n_nodes);
    cout<<output[n_nodes-1]<<endl;
    
}