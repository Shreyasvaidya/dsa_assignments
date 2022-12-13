#include<iostream>
using namespace std;
int lcs(string s1,string s2,int m,int n){
    if(m==0 || n==0){
        return 0;
    }
    else if (s1[m-1]==s2[n-1]){
        return 1 + lcs(s1,s2,m-1,n-1);
    }
    else 
        return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    
}
string reverse(string s){
    string ans = "";
    for(int i=0;i<s.length();i++){
        ans = s[i]+ans;
    }
    return ans;
}
int main(){
    string given;
    cin>>given;
    cout<<lcs(given,reverse(given),given.length(),given.length())<<endl;
}