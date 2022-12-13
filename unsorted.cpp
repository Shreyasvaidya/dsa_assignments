#include <iostream>
using namespace std;

int* combined(int* arr1c,int len1,int* arr2c, int len2){
        int arr1_index=0,arr2_index=0,new_array_index= 0;
        int *output = new int[len1+len2];
        while(new_array_index<len1+len2){
            if(arr1_index<len1 &&(arr2_index==len2|| arr1c[arr1_index]<arr2c[arr2_index])){
                
                output[new_array_index] = arr1c[arr1_index];
                arr1_index++;
                new_array_index++;

            }
            else{
                output[new_array_index]= arr2c[arr2_index];
                arr2_index++;
                new_array_index++;
            }
        }
        
        return output;
    }
int* merge_sort(int* array,int len){//end exclusive
   if (len==1){
        
        return array;
    }
    
    if(len%2){
        int* arr1= new int[len/2+1];
        int* arr2 = new int[len/2];
        for(int i=0;i<len;i++){
            
            if(i<len/2+1){
                arr1[i] = array[i];
            }
            else{
                arr2[i-len/2-1]= array[i];
            }
        }
        return combined(merge_sort(arr1,len/2+1),len/2+1,merge_sort(arr2,len/2),len/2);
    }




    
    else{
        int* arr1= new int[len/2];
        int* arr2 = new int[len/2];
        for(int i=0;i<len;i++){
            
            if(i<len/2){
                arr1[i] = array[i];
            }
            else{
                arr2[i-len/2]= array[i];
            }
        }
        return combined(merge_sort(arr1,len/2),len/2,merge_sort(arr2,len/2),len/2);
    }

}
int main(){
    int len;
    cin>>len;
    int *given = new int[len];
    for(int i=0;i<len;i++){
        cin>>given[i];
    
    }
    int *sorted = merge_sort(given,len);
   
    int first_unsorted_index=len;
    int last_unsorted_index=-1;
    for(int i=0;i<len;i++){
        if(given[i]!=sorted[i]){
            first_unsorted_index = i;
            break;
        }
    }
    for(int i=0;i<len;i++){
        if(given[len-i-1]!=sorted[len-i-1]){
            last_unsorted_index = len-i-1;
            break;
        }
    }
    if(last_unsorted_index==-1 && first_unsorted_index == len){
        cout<<0<<endl;
    }
    else{
        cout<<max(last_unsorted_index,first_unsorted_index)-min(first_unsorted_index,last_unsorted_index)+1<<endl;
    }
}