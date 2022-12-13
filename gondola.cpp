#include<iostream>
using namespace std;
void swap_position(int* arr,int index1,int index2){
    int x=arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = x;
}
int partition(int* array,int start,int end){//end exclusive
    int pivot = array[end-1];
    int index = start;
    while(index<end-1 && array[index]<pivot){
        index++;
    }
    int last_smaller_elem_at = index-1;
    while(index<end -1){
        if(array[index]>=pivot){//= doesnt make any difference but ok
            index++;
        }
        else{
            //swap so that smaller one comes to left
            swap_position(array,last_smaller_elem_at+1,index);
            last_smaller_elem_at++;
        }
    }
    swap_position(array,end-1,last_smaller_elem_at+1);
    return last_smaller_elem_at+1;

}

void quicksort(int * array,int start,int end){
    
    if(start>=end){
        return;
    }
    int correct_position_of_pivot = partition(array,start,end);
    quicksort(array,start,correct_position_of_pivot);//as end is exclusive;
    quicksort(array,correct_position_of_pivot+1,end);
    return;

}
//minimum number of gondola when each has as many elements as possible
int main(){
    int num_children,max_weight,n_gondolas = 0;
    cin>>num_children>>max_weight;
    int *weights = new int[num_children];
    for(int i=0;i<num_children;i++){
        cin>>weights[i];

    }
    quicksort(weights,0,num_children);
    int index = num_children-1;
    while(weights[index]>max_weight ){
        index--;
        n_gondolas++;
    }
    int index_from_start = 0;
    int index_from_back = index;
    while (index_from_start<index_from_back){
        if(weights[index_from_back]+weights[index_from_start]>max_weight){
            n_gondolas++;
            index_from_back--;
        }
        else{
            
            n_gondolas++;
            index_from_start++;
            index_from_back--;
        }
        

        
    }
    if(index_from_back==index_from_start){
            n_gondolas++;
    }
    cout<<n_gondolas<<endl;
    

}