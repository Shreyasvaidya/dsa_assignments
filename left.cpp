#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
};
template<class T>
class Stack{
	private:
		T array[200000];//Random large number, INT_MAX giving segfault
		int head = -1;
		
		
	public:
        bool empty(){
			if (head ==-1){
				return true;
			}
			else{
				return false;
			}
        }
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
};
int main(){
    int n_nodes;
    std::cin>>n_nodes;
    
    int * elements = new int[n_nodes];
    for(int i = 0;i<n_nodes;i++){
        std::cin>>elements[i];

    }
    
    
    
    node* root  = new node;
    
    root ->left = NULL;
    root ->right = NULL;
    node * current_node = NULL;
    node * previous_node = NULL;
    
    /*
    for i in array:
     current = root
     while(current not null)
     if arrayi>current
     current = current ->right
     else 
     current = current ->left
     outside while 
     new node current points to it  
     */
    root ->data = elements[0];
    
    for(int i = 1;i<n_nodes;i++){
        current_node = root;
        previous_node = NULL;
        while(current_node != NULL){
            if (elements[i]>(current_node ->data)){
                
                previous_node = current_node;
                current_node = current_node ->right;
                
            }
            else{
                previous_node =current_node;
                current_node = current_node->left;
            }

        }
        node * tree_node = new node;
        tree_node ->data = elements[i];
        tree_node ->left = NULL;
        tree_node ->right = NULL;
        if(elements[i]>previous_node ->data){
            previous_node ->right = tree_node;

        }
        else{
            previous_node ->left = tree_node;
            
            
        }
        
        
    }
    
    
    
    delete[] elements;
    int traversed = 0;
   node* treenode = root;
   node* parent = NULL;
   Stack<node *> stack;//code taken from iterative preorder traversal
   int suml =0;
   while(traversed<n_nodes){
        while(treenode!=NULL){
            if(treenode ->left == NULL && treenode->right == NULL && parent != NULL && parent ->left == treenode){
                suml+=treenode ->data;
                //cout<<traversed<<"parent "<<parent ->data<<treenode->data<<endl;
            }
            traversed++;
            stack.Push(treenode->right);
            parent = treenode;
            treenode =treenode->left;
            

        }
        if(!stack.empty()){
            treenode = stack.peek();
            stack.Pop();
        }

   }
    cout<<suml<<endl;

    return 0;
}