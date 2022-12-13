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
    int size,sum;
    cin>>size>>sum;
    int* array = new int [size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    array = merge_sort(array,size);
    int pos_from_beginning = 0;
    int pos_from_end =size-1;
    bool possible = false;
    while(pos_from_beginning<=pos_from_end){
        int currsum = array[pos_from_beginning]+array[pos_from_end];
        if(currsum>sum){
            pos_from_end --;
        }
        else if(currsum<sum){
            pos_from_beginning++;
        }
        else{
            possible=true;
            break;

        }
    }
    if(possible){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}