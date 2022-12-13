/*
input n,k
make array of length n+1 initialised to 0(its ith element has the number of edges connencted to ith vertex)
do the next line n-1 times
input u,v array[u]++, array[v]++
sort the array using counting sort,as maximum element is n so o(n)
output is the number of vertices with k+1 or more connections

*/
#include<iostream>
using namespace std;
int* counting_sort(int* array, int len,int max_elem){//has elements btwn 0 and max element
    int* frequency_array = new int[max_elem+1];
    for(int i=0;i<max_elem+1;i++){
        frequency_array[i]=0;
    }
    for(int i=0;i<len;i++){
        frequency_array[array[i]]++;

    }
    int* cumulative_frequency_array= frequency_array;
    for(int i=1;i<max_elem+1;i++){
        cumulative_frequency_array[i]+=cumulative_frequency_array[i-1];
    }
    int *output_array = new int[len];
    for(int i=len-1;i>=0;i--){
        output_array[frequency_array[array[i]]-1]=array[i];
        frequency_array[array[i]]--;

    }
    return output_array;
} 

int main(){
    int n,k;
    cin>>n>>k;
    if(n<=2 && k>0){
        cout<<0<<"\n";
    }
    else{
        int * edge_count = new int[n];
        for(int i=0;i<n;i++){
            edge_count[i]=0;
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            edge_count[u-1]++;
            edge_count[v-1]++;
        }   
        int * sorted_edge_count =counting_sort(edge_count,n,n);
        delete[ ] edge_count;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(sorted_edge_count[i]>k){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
