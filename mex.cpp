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
    int* given = new int[len];
    for(int i=0;i<len;i++){
        cin>>given[i];
    }
    int zero_is_present_at = -1;
    int repeating_no=0;
    int* sorted = merge_sort(given,len);
    int i=0;
    while(i<len){
        //cout<<i<<endl;
        if (sorted[i]<0){
            i++;
            continue;
            
        }
        else if(sorted[i]>=0 && zero_is_present_at==-1 && sorted[i]!=0){
            cout<<0<<endl;
            
            break;
        }
        else if(sorted[i]==0 && (sorted[i-1]!=0 || i== 0)){
            zero_is_present_at= i;
            i++;
            continue;
        }
        if(sorted[i]==sorted[i-1]){
            repeating_no++;
            i++;
            continue;
        }
        if((sorted[i])!=(i-zero_is_present_at-repeating_no)){
          
            cout<<(i-zero_is_present_at-repeating_no)<<endl;
            break;

        }
        else{
            i++;
        }




    }
    if(i==len){
        cout<<i-zero_is_present_at-repeating_no<<endl;
    }

}
