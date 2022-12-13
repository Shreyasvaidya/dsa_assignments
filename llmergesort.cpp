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
        
};
MyLinkedList* combined(MyLinkedList* arr1c,int len1,MyLinkedList* arr2c, int len2){
        int arr1_index=1,arr2_index=1,new_array_index= 1;
        MyLinkedList *output = new MyLinkedList(len1+len2);
        while(new_array_index<=len1+len2){
            if(arr1_index<=len1 &&(arr2_index==len2+1|| (arr1c->pointer_to_postition(arr1_index)->data)<(arr2c->pointer_to_postition(arr2_index)->data))){
                
                output->pointer_to_postition(new_array_index)->data= arr1c->pointer_to_postition(arr1_index)->data;
                arr1_index++;
                new_array_index++;

            }
            else{
                output->pointer_to_postition(new_array_index)->data= arr2c->pointer_to_postition(arr2_index)->data;
                arr2_index++;
                new_array_index++;
            }
        }
        
        return output;
    }
MyLinkedList* merge_sort(MyLinkedList* array,int len){//end exclusive
   if (len==1){
        
        return array;
    }
    
    if(len%2){
        MyLinkedList* arr1= new MyLinkedList(len/2 + 1);
        MyLinkedList* arr2 = new MyLinkedList(len/2);
        for(int i=1;i<len+1;i++){
            
            if(i<=len/2+1){
                arr1->pointer_to_postition(i)->data = array->pointer_to_postition(i)->data;
            }
            else{
                arr2 ->pointer_to_postition(i-len/2-1)->data= array->pointer_to_postition (i)->data;
            }
        }
        return combined(merge_sort(arr1,len/2+1),len/2+1,merge_sort(arr2,len/2),len/2);
    }




    
    else{
        MyLinkedList* arr1= new MyLinkedList(len/2);
        MyLinkedList* arr2 = new MyLinkedList(len/2);
        for(int i=1;i<=len;i++){
            
            if(i<=len/2){
                arr1->pointer_to_postition(i)->data = array->pointer_to_postition(i)->data;
            }
            else{
                arr2 ->pointer_to_postition(i-len/2)->data= array->pointer_to_postition (i)->data;            }
        }
        return combined(merge_sort(arr1,len/2),len/2,merge_sort(arr2,len/2),len/2);
    }

}
int main(){
    int len;
    cin>>len;
    MyLinkedList* given = new MyLinkedList(len);
    for(int i=0;i<len;i++){
        cin>>(given->pointer_to_postition(i+1)->data);

    }
    given = merge_sort(given,len);
    given->print();
    return 0;
    
}