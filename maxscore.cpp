#include<iostream>
using namespace std;
#define ll long long int
ll get_cost(ll * arr , int len){
    ll** costa = new ll*[len];
    for(int i=0;i<len;i++){
        costa[i] = new ll[len];
    }
    int** dcsnbya = new int*[len];
    for(int i=0;i<len;i++){
        dcsnbya[i] = new int[len];
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            costa[i][j]=0;
        }
    }
    for(int i=0;i<len;i++){
        costa[i][i] = arr[i];
        dcsnbya[i][i] = i;
        if(i+1<len){
            costa[i][i+1] =max(arr[i],arr[i+1]);
            dcsnbya[i][i+1] = (costa[i][i+1] == arr[i])?(i):(i+1);
        }
    }
    ll** costb = new ll*[len];
    for(int i=0;i<len;i++){
        costb[i] = new ll[len];
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            costb[i][j]=0;
        }
    }
    int** dcsnbyb = new int*[len];
    for(int i=0;i<len;i++){
        dcsnbyb[i] = new int[len];
    }
    for(int i=0;i<len;i++){
        costb[i][i] = arr[i];
        dcsnbyb[i][i] = i;

        if(i+1<len){
            costb[i][i+1] =max(arr[i],arr[i+1]);
            dcsnbyb[i][i+1] = (costb[i][i+1] == arr[i])?(i):(i+1);
        }
    }
    int i=0;
    int k =2;//(we will provide cost for cost[i][i+k])
    while(k<len){
        while(i+k<len){
            int cost1,cost2,costb1,costb2;
            //case 1 a chooses arri
            if(dcsnbyb[i+1][i+k]==i+1){
                cost1 = arr[i]+ costa[i+2][i+k];
            }
            else{
                cost1 = arr[i]+ costa[i+1][i+k-1];
                 
            }
            //a chooses arr i+k
            if(dcsnbyb[i][i+k-1]==i){
                cost2 = arr[i+k]+ costa[i+1][i+k-1];
            }
            else{
                cost2 = arr[i+k]+ costa[i][i+k-2];
                 
            }
            dcsnbya[i][i+k] = (cost1>cost2)?(i):(i+k);
            costa[i][i+k] = max(cost1,cost2);
            //b chooses arr i
            if(dcsnbya[i+1][i+k]==i+1){
                costb1 = arr[i]+ costb[i+2][i+k];
            }
            else{
                costb1 = arr[i]+ costb[i+1][i+k-1];
                 
            }
            //b chooses arr i+k
            if(dcsnbya[i][i+k-1]==i){
                costb2 = arr[i+k]+ costb[i+1][i+k-1];
            }
            else{
                costb2 = arr[i+k]+ costb[i][i+k-2];
                 
            }
            dcsnbyb[i][i+k] = (costb1>costb2)?(i):(i+k);
            costb[i][i+k] = max(costb1,costb2);
            i++;
        }
        i=0;
        k++;
    }
    

    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout<<costa[i][j]<<" ";
        }
        cout<<endl;
    }
    return costa[0][len-1];
}
int main(){
    int n;
    cin>>n;
    ll * arr = new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans = get_cost(arr,n);
    cout<<ans<<endl;
}