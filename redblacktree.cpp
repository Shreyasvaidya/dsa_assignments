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
        void redblackfix(node* curr){

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

                redblackfix(curr);
                
                
        }
        void inorder(node* given){
            if (!given || ((given->data)==-1))return;
            
            inorder(given->left);
            cout<<given->data<<endl;
            
            inorder(given->right);
        }
        node* position(int x){
            node* curr=root;
            while(curr!=sentinel){
                if(curr->data>x){
                    curr=curr->left;
                }
                else if(curr->data<x){
                    curr=curr->right;

                }
                else{
                    
                    return curr;
                }
            }
            return sentinel;
        }
        void deleteFromTree(int x){
            if (position(x)==sentinel){
                return;
            }
            node *pos = position(x);
            if(pos->left==sentinel && pos->right==sentinel){
                if(pos->parent->right==pos){
                    pos->parent->right=sentinel;
                }
                else if(pos->parent->left==pos){
                    pos->parent->left=sentinel;
                }
                if (pos==root)
                    root = sentinel;
                delete pos;
                return;
            }
            else if (pos->left==sentinel || pos->right==sentinel){
                node* singleChild = (pos->left==sentinel)?(pos->right):(pos->left);
                if(pos->parent->right==pos){
                    pos->parent->right=singleChild;
                }
                else if(pos->parent->left==pos){
                    pos->parent->left=singleChild;
                }  
                singleChild->parent=pos->parent;
                if (pos==root)
                    root = singleChild;
                delete pos;
                return;
            }
            else{
                node* curr;
                curr = pos->right;
                while(curr->left!=sentinel){
                    curr = curr->left;
                }

                int temp = pos->data;
                pos->data=curr->data;
                curr->data=temp;
                if(curr->parent!=pos){
                    curr->parent->left=curr->right;
                    curr->right->parent=curr->parent;
                }
                else{ 
                    curr->parent->right=curr->right;
                    curr->right->parent=curr->parent;
                }

                delete curr;

                

            }
            

        }




};


int main(){
        RedBlackTree* tree = new RedBlackTree(5);
        

        tree->insert(8);

        tree->insert(20);
        tree->inorder(tree->get_root());
        tree->deleteFromTree(8);
        tree->inorder(tree->get_root());
        
       
}




