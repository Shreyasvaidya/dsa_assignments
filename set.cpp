#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* left ;    
    node* right;
    bool black;//false if red
    node* parent;
    
};
class setclass{
    private:
        vector<int>traversal;
        int size=0;
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
        

    public:

        node* get_root(){
            return root;
        }
        int getsize(){
            return size;
        }
        int empty(){
            
            return (size==0);
        }
        setclass(int rootvalue){
            size=1;
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
                if (position(data) !=sentinel){
                    return ;
                }
                if(root == sentinel){
                    root->data=data;
                    size++;
                    root->left=sentinel;
                    root->right=sentinel;
                }
                size++;
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
            traversal.push_back(given->data);       
            inorder(given->right);
        }
        int upper_bound(int x){
            
            
          inorder(root);
            
            for(auto it:traversal){
                if(it >x){
                    traversal.clear();
                    return it ;
                }
            }
            traversal.clear();
            return -1;
        }
        int lower_bound(int x){
             
          inorder(root);
            
            for(auto it:traversal){
                if(it >=x){
                    traversal.clear();
                    return it ;
                }
            }
            traversal.clear();
            return -1;



        }
        int check(int x){
            return (position(x)!= sentinel);
        }
        void deleteFromTree(int x){
            if (position(x)==sentinel){
                return;
            }
            size --;
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
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    long long sum=0;
    int tc;
    cin>>tc;
    int insertcount=0;
    setclass* ourset;

    while(tc--){
        int q;
        cin>>q;
        int x;

        if(q==1){
            
                
            cin>>x;
            if(insertcount==0 ){
                ourset = new setclass(x);
                insertcount++;
            }
            else{
                ourset->insert(x);
            }
                
        }      
        else if(q==2){
                    
                cin>>x;
                if (insertcount!=0)
                    ourset->deleteFromTree(x);

                
        }
        else if(q==3){
                if (insertcount!=0){
                    sum+= ourset->getsize();
                }
        }
        else if(q==4){       
                if (insertcount==0){
                    sum+=1;
                }
                else
                    sum+=ourset->empty();
        }
        else if(q==5) {              
            cin>>x;
            
            sum +=ourset->lower_bound(x);
        }

        else if(q==6){
            cin>>x;
            sum +=ourset->upper_bound(x);
        }
        else if(q==7){
                cin>>x;
                sum+=ourset->check(x);
        }

        

    }
    cout<<sum<<endl;

}