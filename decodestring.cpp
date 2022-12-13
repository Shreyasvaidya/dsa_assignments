#include<iostream>
using namespace std;
int main(){
    string given;
    cin>>given;
    int index=0;
    string ans ="";
    while(index<given.length()){
        int num=0;
        while(given[index]!='['){
            num = num*10 + (given[index]-'0');
            index++;
        }
        index++;
        string strTobeConcated = "";
        while(given[index]!=']'){
            strTobeConcated+= given[index];
            index++;
        }
        index++;
        for(int i=0;i<num;i++){
            ans = ans + strTobeConcated;
        }
    }
    cout<<ans<<endl;
}