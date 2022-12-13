#include<iostream>
using namespace std;
#define ll long long int
ll maxelem(ll* arr,int len){
    ll ans =-1;
    for(int i=0;i<len;i++){
        if(arr[i]>ans){
            ans = arr[i];
        }
    }
    return ans;
}
int lis(ll* arr , int len){
    ll* lisarr = new ll[len];
    for(int i=0;i<len;i++){
        lisarr[i]=1;
    }
    int i=1,j;
    while(i<len){
        int maxlis = 0,maxlisat=-1;
        j=0;
        while(j<i){
            if(arr[j]<arr[i]){
                if(lisarr[j]>maxlis){
                    maxlis = lisarr[j];
                    maxlisat = j;
                    
                }
            }
            j++;
        }
        if(maxlisat+1){
            lisarr[i]= 1+ lisarr[maxlisat];
        }
        i++;
    }
    
    return maxelem(lisarr,len);
}
int main(){
    int len;
    cin>>len;
    ll* arr = new ll[len];
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }

    cout<<lis(arr,len)<<endl;
}