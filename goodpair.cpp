#include<iostream>
using namespace std;
void print(long long int* arr,long long int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    long long  int n;
    cin>>n;
    long long int k;
    
    cin>>k;
    k%=n;
    long long int num=0;
    long long int* given = new long long int[n];
    for(long long int i=0;i<n;i++){
        cin>>given[i];
    }
    long long int * rems = new long long int[n];
    
    for(long long int i=0;i<n;i++){
        rems[given[i]%n]++;
    }
    

    num+= rems[0]*rems[0];//rem 0 first
   
    
    if(k==0){//divisible by n
                num= n*rems[0] ;
           }
    else{
        for(long long int i=1;i<n;i++){
            if((k*i)%n!=0){
                num+=rems[i]*rems[n-((k*i)%n)];
            }
            else{
                num+=rems[i]*rems[0];
            }
        }
    }
    cout<<num<<endl;
}