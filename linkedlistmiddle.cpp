#include<iostream>

using namespace std;
class node{
    public:
        int data;
        
        node* next;
        node(int x){
           data = x;
           next = NULL; 
        }
};
class MyLinkedList{
    
    private:
        node * head;node* curr; 
    public:
        int lenlist;

        MyLinkedList(int len,int* arr){

            lenlist = len;
            
            head = new node(arr[0]);
            curr = head;
            for(int i = 1;i<len;i++){
                
                
                node* next_node = new node(arr[i]);
                curr ->next = next_node;
                
                curr = next_node;
            }
            //curr -> next = NULL; not needed now because of definition of node
        }
        node* pointer_to_postition(int pos){
                node *current_node = this ->head;
                for(int i =1;i<pos;i++){
                    current_node = current_node ->next;
                }
                
                return current_node;
        }
};
int main(){
    int n,*given_array;
    cin>>n;
    given_array = new int[n];
    for(int i=0;i<n;i++){
        cin>>given_array[i];
    }
    MyLinkedList* linked_list = new MyLinkedList(n,given_array);
    cout<<(linked_list->pointer_to_postition(n/2+1))->data<<endl;
}