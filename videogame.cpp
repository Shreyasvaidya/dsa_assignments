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

int binary_searchleq(int* array,int low,int high ,int elem,int len){//sorted
    if(high>=low){
        int mid = low + (high -low)/2;
        if( (mid == len-1 || array[mid+1]>elem )&& array[mid]<=elem){
            return mid+1;
        }
        else if(array[mid]<=elem){
            return binary_searchleq(array,mid+1,high,elem,len);
        }
        else{
            return binary_searchleq(array,low,mid-1,elem,len);
        }
        
    }
    return 0;//414

}

    

int main(){
    int n_prices,n_friends;
    cin>>n_prices>>n_friends;
    int* prices = new int[n_prices];
    int* budgets = new int[n_friends];
     
     
    for(int i=0;i<n_prices;i++){
        cin>>prices[i];

    }
    for(int i=1;i<n_prices;i++){
        prices[i]+=prices[i-1];//cumulative
    }
    for(int i=0;i<n_friends;i++){
       cin>>budgets[i];
      
    }
    for(int i=0;i<n_friends;i++){
        cout<<binary_searchleq(prices,0,n_prices-1,budgets[i],n_prices)<<" ";
    }
    cout<<endl;
   
    
    
    return 0;
}
