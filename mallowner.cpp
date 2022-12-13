#include <iostream>
#define INITIALISE 0;
using namespace std;
int my_max(int* array,int len){
    int max_elem = -1;
    
    for(int i=0;i<len;i++){
        
        if (array[i]>max_elem){
            max_elem = array[i];
        }

    }
    return max_elem;
}
int main(){
    int n;
    cin>>n;

    int footfall_at_time[1001];
    for(int i = 0;i<1001;i++){
            footfall_at_time[i]=INITIALISE;
        }
    for(int _ =0;_<n;_++){
        int in_time,out_time,size;
        cin>>in_time>>out_time>>size;
        for(int i = in_time;i<out_time;i++){
            
            footfall_at_time[i]+=size;
            
        }

    }
    cout<<my_max(footfall_at_time,1001)<<endl;
    
    return 0;
}