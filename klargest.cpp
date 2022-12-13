#include<iostream>
using namespace std;
void swap_position(int* arr,int index1,int index2){
    int x=arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = x;
}

void heapify(int* array,int start_pos,int len){
    
    if(start_pos>=len){
        return;
    }
    if(2*start_pos+2<len){
        int max_child = max(array[2*start_pos+1],array[2*start_pos+2]);
        if(max_child>array[start_pos]){
            if(max_child==array[2*start_pos+1]){
                swap_position(array,start_pos,2*start_pos+1);
                heapify(array,2*start_pos+1,len);
                return;
                }
            else if (max_child==array[2*start_pos+2]){
                swap_position(array,start_pos,2*start_pos+2);
                heapify(array,2*start_pos+2,len);
                return;
            }
            else{
                return;
            }
            
        }
        
    }
    if(2*start_pos+2==len && array[start_pos]<array[2*start_pos+1] ){

            swap_position(array,start_pos,2*start_pos+1);
            return ;
    }
    
}
    


void create_heap(int * array,int len){
    
    for(int i=(len-1)/2;i>=0;i--){   //2n + 1>=len n>=(len-1)/2
        
        
        heapify(array,i,len);
    }
}
int main(){
    int n;
    cin>>n;
    int* given = new int[n];
    for(int i=0;i<n;i++){
        cin>>given[i];

    }

    int k;
    cin>>k;
    create_heap(given,n);
    
    for(int i=0;i<k;i++){//not heapsort as not repeated for the entire array length
        cout<<given[0]<<" ";
        swap_position(given,0,n-i-1);
        
        if(i!=k-1){
            heapify(given,0,n-i-1);
        }
    }
    cout<<endl;
    
    








}