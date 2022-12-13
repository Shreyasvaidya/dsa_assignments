#include<iostream>
using namespace std;
/*Driver code starts*/
typedef struct Node{
    int data;
    struct Node *next;

    Node (int x){
        data = x;
        next = NULL;
    }
}Node;
/*Driver code ends*/

Node *solve(Node *head1, Node *head2, int n, int m){
  //your code goes here
    int min_nodes = (n>m)?(m):(n);
    int max_nodes = (n>m)?(n):(m);
    Node * less_nodes_container = (min_nodes==m)?(head2):(head1);
    Node * more_nodes_container = (min_nodes==m)?(head1):(head2);
    Node** uncommon_nodes_from_larger = new Node*[max_nodes];
    Node * curr_smaller = less_nodes_container;
    Node* prev_smaller = NULL;
    Node * curr_larger = more_nodes_container;
    Node* prev_larger = NULL;
    int len_larger = 0;//of uncommon list
    

    int i =0;
    int steps_taken =0;
    bool common_found;
    //while (i<=len){
    while (curr_larger!= NULL){
        steps_taken=0;
        while(curr_smaller != NULL && curr_smaller!=curr_larger){
            
            curr_smaller= curr_smaller->next;
            steps_taken++;
        }
        if(curr_smaller==NULL){
            uncommon_nodes_from_larger[i]= curr_larger;
            curr_larger = curr_larger->next;
            curr_smaller = less_nodes_container;
            i++;
            len_larger++;
        }
        else{
            Node** uncommon_nodes_from_smaller = new Node*[steps_taken];
            curr_smaller = less_nodes_container;
            for(int j=0;j<steps_taken;j++){
                uncommon_nodes_from_smaller[j] = curr_smaller;
                curr_smaller= curr_smaller->next;

            }
            break;
        }


        
    }
    uncommon_nodes_from_larger[len_larger-1] ->next =  less_nodes_container;
    Node*curr = more_nodes_container;
    while( curr  !=NULL){
        cout<<curr ->data<<" ";
        curr =curr ->next;
    }
    cout<<endl;
    return  more_nodes_container;
    

}

/*Driver code starts*/
Node *insertAtEnd(Node *end,int x){
    Node *n=new Node(x);
    end->next=n;
    return n;
}
int main(){
    int n,m;cin>>n>>m;
    int commonElements;cin>>commonElements;

    Node *head1=NULL;
    Node *end1=NULL;

    int temp;cin>>temp;
    head1=new Node(temp);
    end1=head1;
    for(int i=1;i<n-commonElements;i++){
        cin>>temp;
        end1=insertAtEnd(end1,temp);
    }
    cin>>temp;
   
    Node *head2=NULL;
    Node *end2=NULL;
    head2=new Node(temp);
    end2=head2;

    for(int i=1;i<m-commonElements;i++){
        cin>>temp;
        end2=insertAtEnd(end2,temp);
    }


    for(int i=0;i<commonElements;i++){
        cin>>temp;
        Node *temp1=new Node(temp);
        end1->next=temp1;
        end1=temp1;
        end2->next=temp1;
        end2=temp1;
    }

    Node *head=solve(head1,head2,n,m);
    
    return 0;
}
/*Driver code ends*/
