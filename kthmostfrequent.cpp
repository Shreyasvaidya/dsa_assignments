#include<iostream>
#include<unordered_map>//using because in this question, had to,and we were allowed 
#include<string>
using namespace std;
void swap_position(string* arr,int index1,int index2){
    string x=arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = x;
}

/*void heapify(int *array,int start_pos,int len){
    
    if(start_pos>=len){
        return;
    }
    if(2*start_pos+2<len){
        int max_child = max(array[2*start_pos+1],array[2*start_pos+2]);
        if(max_child>array[start_pos]){
            if(max_child==array[2*start_pos+1]){
                swap_position(array,start_pos,2*start_pos+1);
                heapify(array,2*start_pos+1,len);
                return;
                }
            else if (max_child==array[2*start_pos+2]){
                swap_position(array,start_pos,2*start_pos+2);
                heapify(array,2*start_pos+2,len);
                return;
            }
            else{
                return;
            }
            
        }
        
    }
    if(2*start_pos+2==len && array[start_pos]<array[2*start_pos+1] ){

            swap_position(array,start_pos,2*start_pos+1);
            return ;
    }
    
}
    


void create_heap(int * array,int len){
    
    for(int i=(len-1)/2;i>=0;i--){   //2n + 1>=len n>=(len-1)/2
        
        
        heapify(array,i,len);
    }
}
*/
bool greater_than(string s1,string s2,unordered_map<string,int> map){
    if(map[s1]>map[s2]){
        return true;
    }
    else if(map[s1]<map[s2]){
        return false;
    }
    else if(s1>s2){
        return true;
    }
    else{
        return false;
    }
}
void heapify(string* array,int start_pos,int len,unordered_map<string,int> map){
    if(start_pos>=len){
        return;
    }
    if(2*start_pos+2<len){
        string minchild = (greater_than(array[2*start_pos+2],array[2*start_pos+1],map))?(array[2*start_pos+1]):(array[2*start_pos+2]);
        if(greater_than(array[start_pos],minchild,map)){
                if(minchild==array[2*start_pos+1]){
                    swap_position(array,start_pos,2*start_pos+1);
                    heapify(array,2*start_pos+1,len,map);
                    return;
                    }
                else if (minchild==array[2*start_pos+2]){
                    swap_position(array,start_pos,2*start_pos+2);
                    heapify(array,2*start_pos+2,len,map);
                    return;
                }
                else{
                    return;
                }
                
            }
            
        }
        if(2*start_pos+2==len && greater_than(array[start_pos],array[2*start_pos+1],map) ){

            swap_position(array,start_pos,2*start_pos+1);
            return ;
        }
}

void create_heap(string * array,int len,unordered_map<string,int> map){
    
    for(int i=(len-1)/2;i>=0;i--){   //2n + 1>=len n>=(len-1)/2
        
        
        heapify(array,i,len,map);
    }
}

int main(){
    unordered_map<string,int> frequency;
    
    int count_num=0;
    string s;
    /*while(cin>>s){
        frequency[s]++;  
        count_num++;      
    }*/
    
  
    getline(cin, s);
    
    string part ="";
    
    for(int i=0;s[i]!='\0';i++){
        //cout<<i<<endl;
        if(s[i]!=' '){
            part+=s[i];
        }
        
        
        else{
            frequency[part]++;
            count_num++;

            part = "";
        }
    }
    //getline(cin,extra);
    int k;
    cin>>k;
    string * given = new string[count_num];
    int index=0;
    for(auto i:frequency){
        given[index]= i.first;
        index++;
    }
    
    create_heap(given,k,frequency);
    
    for(int i=k;i<index;i++){
        
        if(greater_than(given[i],given[0],frequency)){
            swap_position(given,0,i);
            heapify(given,0,k,frequency);


        }
        
    }
    cout<<given[0]<<endl;



}
