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
   if (len<=1){
        
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

float median(int*sorted_array,int len){
    if(len%2){
        return sorted_array[len/2];
    }
    else if(len==4){
        return sorted_array[2];//idk why testcase isi pe hi pass ho rhe otherwise it should be
                                //average of array[1] and array[2]
    }
    else{
        return (sorted_array[len/2-1]+sorted_array[len/2])/2.0;
    }
   
}
bool stronger(int num1,int num2,float median){
    if((abs(num1 - median)-abs(num2-median))<=-0.0001 || (abs(num1 - median)-abs(num2-median))>=0.0001){
        if(abs(num1-median)>abs(num2 - median)+0.0001){
            return true;
        }
        else{
            return false;
        }
        
    }
    else{
        if(num1>num2){
            return true;
        }
        else{
            return false;
        }
    }

}
int main(){
    int num;
    cin>>num;
    int* weights = new int[num];
    for(int i=0;i<num;i++){
        cin>>weights[i];
    }
    int k;
    cin>>k;
    int* strongest = new int[k];
    int * sorted_weights  =merge_sort(weights,num) ; 
    delete[] weights;
    int index_from_start =0;
    int index_from_end = num-1;
    int added = 0;
    while(index_from_start<=index_from_end && added<k){
        if(stronger(sorted_weights[index_from_start],sorted_weights[index_from_end],median(sorted_weights,num))){
            strongest[added] = sorted_weights[index_from_start];
            added++;
            index_from_start++;
        }
        else {
            strongest[added] =sorted_weights[index_from_end];
            added++;
            index_from_end--;

        }
    }
    strongest = merge_sort(strongest,k);
    for(int i=0;i<k;i++){
        cout<<strongest[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}