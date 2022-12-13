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
void initialise(int* arr,int len){
    for(int i=0;i<len;i++){
        arr[i] = INT_MAX;
    }
}

int getmincost_if_givensEdgeIsHalved(int n,int n_nodes){
    int* output = new int[n_nodes];
    int ans = INT_MAX;
    initialise(output,n_nodes);
    for(int i=n+1;i<n_nodes;i++){
        if(input[n][i]<INT_MAX){
            if(n>0) djakstra(0,output,n_nodes);
            int dist1 = (n>0)?(output[n]):0;
            initialise(output,n_nodes);
            
            if (i<n_nodes-1) djakstra(i,output,n_nodes);
            int dist2 = (i+1<n_nodes)?(output[n_nodes-1]):0;
            int sumour = dist1+(input[n][i])/2 + dist2;
            if(sumour <ans)
                ans =  sumour;
            
        }
    }
    return ans;
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
            if (i!=j)
                input[i][j] = INT_MAX;
            else
                input[i][j]=0;
        }

        
    }
    for(int i=0;i<n_edges;i++){
        int n1,n2,weight;
        cin>>n1>>n2>>weight;
        input[n1-1][n2-1] = weight;
        
        
    }
    int mincost = INT_MAX;
    for(int i=0;i<n_nodes-1;i++){
        int mincurr = getmincost_if_givensEdgeIsHalved(i,n_nodes) ;
        if(mincurr<mincost)
            mincost = mincurr;
    }

    cout<<mincost<<endl;
}