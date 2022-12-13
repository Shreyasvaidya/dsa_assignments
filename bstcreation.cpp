#include<iostream>
using namespace std;
class node{
    public:
        int data=0;
        node* parent = NULL;
        node* left = NULL;
        node* right = NULL;
};
int get_lca(int* elements,int n_nodes,int p,int q){
        int lower_index = min(p,q);
        int greater_index = max(p,q);
        int previous_parent_at = 0;
        int lca_at;
        for(int i=0;i<=lower_index;i++){
            if((elements[lower_index]>elements[previous_parent_at] && elements[greater_index]<elements[previous_parent_at]) || (elements[lower_index]<elements[previous_parent_at] && elements[greater_index]>elements[previous_parent_at])){
                lca_at = previous_parent_at;
                
                break;

            }
            else if((elements[i]-elements[previous_parent_at])*(elements[lower_index]-elements[previous_parent_at])<0){
                continue;
            }
            else{
                previous_parent_at=i;
                
            }


        }
        lca_at=previous_parent_at;
        return elements[lca_at];
}
node* find_in_tree(node* root,int givendata){
    node* curr = root;
    while(curr!=NULL && curr->data!=givendata  ){
        if(givendata>curr->data){
            curr = curr->right;
        }
        else if(givendata<curr->data){
            curr = curr->left;
        }
        
    }
    return curr;
}
int main(){

    int n;
    cin>>n;
    int* array = new int[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int q; 
    cin>>q;
    node * root = new node();
    node *current_node,*previous_node;
    root->data= array[0];
    for(int i=1;i<n;i++){
        current_node = root;

        previous_node = NULL;
        while(current_node != NULL){
            if (array[i]>(current_node ->data)){
                
                previous_node = current_node;
                current_node = current_node ->right;
                
            }
            else{
                previous_node =current_node;
                current_node = current_node->left;
            }

        }
        node * tree_node = new node;
        tree_node ->data = array[i];
        tree_node->parent =previous_node ;
        if(array[i]>previous_node ->data){
            previous_node ->right = tree_node;

        }
        else{
            previous_node ->left = tree_node;
        }
        //std::cout<<"Entered element no. "<<i<<std::endl;
        
    }
    for(int _=0;_<q;_++){
        int i,j;
        cin>>i>>j;
        int lca = get_lca(array,n,i,j);
        long long xorAns = array[i];
        node* curr_node = find_in_tree(root,array[i]);
        while(curr_node->data!=lca){
            curr_node=curr_node->parent;
            xorAns = xorAns^(curr_node->data);
        }
        while (curr_node->data!=array[j])
        {
            if(array[j]>curr_node->data){
                curr_node=curr_node->right;
                xorAns = xorAns^(curr_node->data);
            }
            else{
                curr_node=curr_node->left;
                xorAns = xorAns^(curr_node->data);
            }
        }

        cout<<(xorAns^lca)<<endl;
        

    } 

}