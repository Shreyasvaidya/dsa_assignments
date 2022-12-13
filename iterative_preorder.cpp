#include<iostream>
using namespace std;
template<class T>
class Stack{
	private:
		T array[200000];//Random large number, INT_MAX giving segfault
		int head = -1;
		bool empty(){
			if (head ==-1){
				return true;
			}
			else{
				return false;
			}
		}
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
};
class node{
    public:
        int data;
        node* left;
        node* right;
};


int main(){
    int n_nodes,n_queries;
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
        //std::cout<<"Entered element no. "<<i<<std::endl;
        
    }
    
    
    delete elements;
    /*
    values printed = 0
    while(values_printed<n)
    while(node->left not null){

        print data
        value_printed=0;
        stack.push(node->right)
        node = node->left
    }
    node = stack.pop()
    */
   int values_printed = 0;
   node* treenode = root;
   Stack<node *> stack;
   while(values_printed<n_nodes){
        while(treenode!=NULL){
            cout<<treenode ->data<<" ";
            values_printed++;
            stack.Push(treenode->right);
            treenode =treenode->left;

        }
        treenode = stack.peek();
        stack.Pop();

   }
    cout<<endl;
    
}