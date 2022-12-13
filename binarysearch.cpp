#include<iostream>
using namespace std;
int binary_search(int* array,int low,int high ,int elem,int len){//sorted
    if(high>=low){
        int mid = low + (high -low)/2;
        if (array[mid]==elem){
            return mid;
        }
        else if(array[mid]<elem){
            return binary_search(array,mid+1,high,elem,len);
        }
        else{
            return binary_search(array,low,mid-1,elem,len);
        }
        
    }
    return -1;//414

}
int main(){
    int len;
    cin>>len;
    int* given = new int[len];
    for(int i=0;i<len;i++){
        cin>>given[i];
    }
    int elemt;
    cin>>elemt;
    int pos = binary_search(given,0,len-1,elemt,len);
    cout<<pos<<endl;

}