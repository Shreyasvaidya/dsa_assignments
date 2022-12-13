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
    int len;
    cin>>len;
    int * given = new int[len];
    for(int i=0;i<len;i++){
        cin>>given[i];
        given[i]+=500;
    }
    int* ans = counting_sort(given,len,1000);
    for(int i=0;i<len;i++){
        cout<<(ans[i]-500)<<" ";
    }
    cout<<endl;

}