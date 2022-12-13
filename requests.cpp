#include<iostream>
using namespace std;
int find_indexgreq(int* arr,int elem,int len){//give sorted array
    for(int i=0;i<len;i++){
        if (arr[i]>=elem){
            return i;
        }
    }
    return -1;
}
int find_indexleq(int* arr,int elem,int len){//give sorted array
    for(int i=len-1;i>=0;i--){
        if (arr[i]<=elem){
            return i;
        }
    }
    return -1;
}
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
        given[i]--;//(for making range starting from 0 )
    }
    int* sorted = counting_sort(given,len,149);
    
    int current;
    cin>>current;
    
    string up_or_down;
    cin>>up_or_down;
    if(up_or_down == "UP"){
        int pos = find_indexgreq(sorted,current-1,len);
        for(int i=pos;i<len;i++){
            cout<<sorted[i]+1<<" ";
        }
        for(int i =1;i<=pos;i++){
            cout<<sorted[pos-i]+1<<" ";
        }
    
    }
    else if (up_or_down=="DOWN"){
        int pos = find_indexleq(sorted,current-1,len);
        for(int i=0;i<=pos;i++){
            cout<<sorted[(pos-i)]+1<<" ";
        }
        for(int i=pos+1;i<len;i++){
            cout<<sorted[i]+1<<" ";
        }

    }
    cout<<endl;

}