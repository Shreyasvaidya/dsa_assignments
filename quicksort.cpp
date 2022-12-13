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
int main(){
    int len;
    cin>>len;
    int * given = new int[len];
    for(int i=0;i<len;i++){
        cin>>given[i];
    }
    quicksort(given,0,len);
    int * sorted_given = given;
    for(int i=0;i<len;i++){
        cout<<sorted_given[i]<<" ";
    }
    cout<<endl;
    delete[] given;
    return 0;
}