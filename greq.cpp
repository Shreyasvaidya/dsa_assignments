#include<iostream>
class node{
    public:
        int data;
        node* left;
        node* right;
};
/*void print(node * root1){
    if (root1 == NULL){
        return;
    } 
    else{
        print(root1 ->left);
        std::cout<<root1 ->data<<" ";
        print(root1 ->right);
    }
    std::cout<<std::endl;
}*/
//debug
/*void print(int * arr,int len){
    for(int i =0;i<len;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}*/
int * ascending_array;
int get_ascending_order(node* node,int index_counter ){//int return value just to return the index counter
    if(node ==NULL){
        return index_counter;
    }
    index_counter = get_ascending_order(node->left,index_counter);
    ascending_array[index_counter] = node->data;
    index_counter++;
    index_counter = get_ascending_order(node->right,index_counter);
    return index_counter;
}

int main(){
    int n_nodes,n_queries;
    std::cin>>n_nodes;
    std::cin>>n_queries;
    
    int * elements = new int[n_nodes];
    int * queries = new int[n_queries];
    for(int i = 0;i<n_nodes;i++){
        std::cin>>elements[i];

    }
    
    for(int i = 0;i<n_queries;i++){
        std::cin>>queries[i];
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
        //std::cout<<"Entered element no. "<<i<<std::endl;
        
    }
    
    
    delete elements;
    ascending_array = new int[n_nodes];
    get_ascending_order(root,0);
    for(int i =0;i<n_queries;i++){
        
        int found_element = -1;
        for(int j=0;j<n_nodes;j++){
            if (ascending_array[j]>=queries[i]){
                found_element = ascending_array[j];
                
                break;
                }
            }
        std::cout<<found_element<<std::endl;
    }
}