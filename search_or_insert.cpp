#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left ;    
    node* right;
    bool black;//false if red
    node* parent;
};

class RedBlackTree{
    private:
        
        node* sentinel ; 
        node* root ;
        void right_rotate(node* givennode){
            node* a = givennode->left;
            if(givennode==root){root=a;}
            if(givennode==givennode->parent->right)
                givennode->parent->right=a;
            else if (givennode==givennode->parent->left)
                givennode->parent->left=a;
            a->parent=givennode->parent;
            givennode->parent=a;
            givennode->left=a->right;
            a->right=givennode;
        }
        void left_rotate(node* givennode){
            
            node* b= givennode->right;
            if(givennode==root){root=b;}
             
            if(givennode==givennode->parent->right)
                givennode->parent->right=b;
            else if (givennode==givennode->parent->left)
                givennode->parent->left=b;
            b->parent=givennode->parent;
            givennode->parent=b;
            givennode->right=b->left;
            b->left=givennode;
        }

    public:
        node* get_root(){
            return root;
        }
        RedBlackTree(int rootvalue){
            sentinel = new node;
            root = new node;
            sentinel->data = -1;
            sentinel->black= true;
            root->data = rootvalue;
            root->black=true;
            root->left = sentinel;
            root->right=sentinel;
            root->parent=sentinel;
        }
        void insert(int data){
                
                node* curr = root;
                node* prev = sentinel;
                while(curr!=sentinel){
                    if(curr->data<data){
                        prev= curr;
                        curr = curr->right;
                    }
                    else{
                        prev = curr;
                        curr = curr->left;
                    }
                }
                curr = prev;
                

                node* newnode = new node;
                newnode->data = data;
                newnode->parent = curr;
                if(data<curr->data){
                    curr->left=newnode;
                }
                else{
                    curr->right=newnode;
                }
                newnode->left=sentinel;
                newnode->right=sentinel;
                newnode->black = false;
                curr = newnode;
                node* uncle;
                while(!(curr->parent->black)){
                    if(curr->parent==curr->parent->parent->right){
                        uncle=curr->parent->parent->left;
                        
                        if(!uncle->black){
                            curr->parent->black=true;
                            uncle->black=true;
                            curr->parent->parent->black=false;

                        }
                        else{
                            if(curr->parent->left==curr){

                            curr=curr->parent;
                            right_rotate(curr);

                            }

                            curr->parent->black=true;
                            curr->parent->parent->black=false;
                            left_rotate(curr->parent->parent);
                        }
                    }
                    else{
                        uncle=curr->parent->parent->right;
                        
                        if(!uncle->black){
                            curr->parent->black=true;
                            uncle->black=true;
                            curr->parent->parent->black=false;

                        }
                        else{
                            if(curr->parent->right==curr){
                            curr=curr->parent;
                            left_rotate(curr);
                            }

                            curr->parent->black=true;
                            curr->parent->parent->black=false;
                            right_rotate(curr->parent->parent);
                        }

                    }
                }
                root->black=true;
                
                
        }
        void inorder(node* given){
            if (!given || ((given->data)==-1))return;
            
            inorder(given->left);
            cout<<given->data<<endl;
            
            inorder(given->right);
        }
        int search_or_insert(int x){
            int index=0;
            node* curr=root;
            while(curr->left!=sentinel){
                curr = curr->left;
            }
            node* prev =sentinel;
            while(curr!=sentinel){
                if(curr->data==x)
                    return index;
                else if (curr->data>x && prev ->data<x)
                    return index;
                else {
                    prev= curr;
                    if(curr == curr->parent->left){
                        prev = curr;
                        curr =curr->parent;
                        index++;
                    }
                    else{
                        prev = curr;
                        curr = curr->right;
                        index++;
                    }
                }
            }
            return index;
        }




};


int main(){
        int len;
        cin>>len;
        int first;
        cin>>first;
        RedBlackTree* tree = new RedBlackTree(first);
        for(int i=1;i<len;i++){
            int elem;
            cin>>elem;
            tree->insert(elem);
        }
        int given;
        cin>>given;
        cout<<tree->search_or_insert(given)<<endl;
       
}



