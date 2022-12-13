#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int len;
    cin>>len;
    int * freqarr = new int[n];
    for(int i=0;i<n;i++){
        freqarr[i]=-1;//means empty
    }
    for(int i=0;i<len;i++){
        int given;
        cin>>given;
        freqarr[given%n]++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(freqarr[i]>0)
            ans+=freqarr[i];
    }
    cout<<ans<<endl;
}