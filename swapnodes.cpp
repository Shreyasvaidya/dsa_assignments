#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
class MyLinkedList{
    
    private:
        node * head;node* curr; 
    public:
        int lenlist;

        MyLinkedList(int len){

            lenlist = len;
            
            head = new node;
            curr = head;
            for(int i = 1;i<len;i++){
                
                
                node* next_node = new node;
                curr ->next = next_node;
                
                curr = next_node;
            }
            curr -> next = NULL;
        }
        node* pointer_to_postition(int pos){ //note the typo
                node *current_node = head;
                for(int i =1;i<pos;i++){
                    current_node = current_node ->next;
                }
                
                return current_node;
        }
        void print(){
            for(int i =1;i<=lenlist;i++){
                cout<<pointer_to_postition(i) ->data<<" ";
            }
            cout<<endl;
            
        }
        bool swap_if_possible(int pos1,int pos2){//returns false if not possible
            int greater = (pos1>pos2)?(pos1):(pos2);
            int smaller = (pos1>pos2)?(pos2):(pos1);
            if(greater>lenlist){
                return false;
            }
            else if(smaller<1){
                return false;
            }
            else if(greater-smaller -1) {
                node *smallernext = pointer_to_postition(smaller+1) ;
                node *greaterprev = pointer_to_postition(greater-1);
                node* greaternode = pointer_to_postition(greater);
                node* smallernode= pointer_to_postition(smaller);
                node *smallerprev;//will use only if accessible
                node* greaternext;//will use only if accessible
                if(smaller !=1){
                    smallerprev = pointer_to_postition(smaller-1);
                    
                    
                }
                 
                if(greater !=lenlist){
                    greaternext = pointer_to_postition(greater+1);
                }
                
                if(smaller !=1){
                    
                    smallerprev->next = greaternode;
                    
                }
                 else{
                    head = greaternode;
                }
                if(greater !=lenlist){
                  
                  smallernode->next = greaternext;
                  
                }
                else{
                    smallernode ->next = NULL;
                }
                
                greaternode->next = smallernext;
                greaterprev->next = smallernode;
                
               

                
                return true;
            }
            else{
                node * smallerprev ,*greaternext;
                node* greaternode = pointer_to_postition(greater);
                node* smallernode= pointer_to_postition(smaller);
                if(smaller !=1){
                    smallerprev = pointer_to_postition(smaller-1);
                }
                 
                if(greater !=lenlist){
                    greaternext = pointer_to_postition(greater+1);
                }
                if(smaller !=1){
                    
                    smallerprev->next = greaternode;
                    
                }
                 else{
                    head = greaternode;
                }
                if(greater !=lenlist){
                  
                  smallernode->next = greaternext;
                  
                }
                else{
                    smallernode ->next = NULL;
                }
                greaternode->next = smallernode;
                return true;

            }
        }
};
int main(){
    int len;
    cin>>len;
   
    
        MyLinkedList* list = new MyLinkedList(len);
        if(len){
        for(int i=1;i<=len;i++){
            cin>>(list->pointer_to_postition(i)->data);
        }
        }
        int index1,index2;
        cin>>index1;
        cin>>index2;
        list ->print();
        cout<<endl;
        if(len == 0 ){
            cout<<-1<<endl;
        }
        else if(len==1){
            list->print();
        }
        else if(list ->swap_if_possible(index1,index2)){
            list ->print();
        }
        else{
            cout<<-1<<endl;
        }





        return 0;
    
}