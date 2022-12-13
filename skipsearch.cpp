#include <iostream>
using namespace std;
int skip_search(int* array, int len , int skip,int elem){//return 0-index
    int i;
    for(i=0;i<len-skip;i+=skip){
        if(array[i]==elem )
            return i;
        else if (array[i+skip]==elem){
            return i+skip;
        
        }
        else if (array[i]<elem && array[i+skip]>elem){
            break;
        }
    }
    for(int j=1;j<skip;j++){
        if(array[i+j]==elem){
            return i+j;
        }
    }
    return -2;
}
int main(){
    int len;
    cin>>len;
    int * array = new int[len];
    int elem;
    for(int i=0;i<len;i++){
        cin>>array[i];
    }
    cin>>elem;
    cout<<skip_search(array,len,2,elem)<<endl;
}