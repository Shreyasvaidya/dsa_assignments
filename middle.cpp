#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
#include<iostream>
using namespace std;
template<class T>
class Stack{
	private:
		T array[200000];//Random large number, INT_MAX giving segfault
		int head = -1;
		
	public:
		void Push(T elem){
			head++;
			array[head] = elem;
		}
		
		void Pop(){
			if ( empty()){
				cout<<"stack is empty"<<endl;
			}
			else{
				head --;
			}
		}
		T peek(){
			return array[head];
		}
		void size(){
			cout<<head+1<<endl;
		}
		void isempty(){
			if (this -> empty()){
				cout << 1<<endl;
			}
			else{
				cout <<0<<endl;
			}
            
		}
        bool empty(){
			if (head ==-1){
				return true;
			}
			else{
				return false;
			}
		}
};
class MyLinkedList{
    
    private:
        node * head=NULL;
        node* curr; 
        int lenlist;
    public:
        
        
        MyLinkedList(int len){//extra constructor,wont be used in this question as we dont have length

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
            int i=1;
            while(pointer_to_postition(i)!=NULL){
                cout<<pointer_to_postition(i) ->data<<" ";
                i++;
            }
            cout<<endl;
            
        }
        

};
node** get_reversed(MyLinkedList* list){ //returns an array with data in reversed order ,ok for our purpose
            Stack<node*> stack;
            node* curr = list ->pointer_to_postition(1);
            node** array = new node *[10000];
            
            while(curr !=NULL){
                stack.Push(curr);
                curr= curr->next;
            }
            int arr_index = 0;
            while(!stack.empty()){
                array[arr_index]= stack.peek();
                stack.Pop();
                arr_index++;
            }
            array[arr_index] = NULL;//to show that remining spaces are useless
            return array;
        }
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int len;
        cin>>len;
        MyLinkedList* givenlist = new MyLinkedList(len);
        for(int i=1;i<=len;i++){
            cin>>givenlist->pointer_to_postition(i)->data ;
        }
        //finding middle node
        node** reversed_array = get_reversed(givenlist);
        node* curr_node = givenlist->pointer_to_postition(1);
        int index=0;
        node* middle = NULL;
        while(curr_node!=NULL){
            if(curr_node==reversed_array[index] || reversed_array[index]->next==curr_node){
                middle = curr_node;
                break;
            }
            curr_node = curr_node->next;
            index++;
        }
        
        //deleting
        if(givenlist->pointer_to_postition(1)==middle){
            delete middle;
            continue;
        }
        else{
            curr_node= givenlist->pointer_to_postition(1);
            while(curr_node->next!= middle){
                curr_node=curr_node->next;
            }
            curr_node->next = middle->next;
            delete middle;
            givenlist->print();

        }

    }


}