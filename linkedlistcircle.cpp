/*
array[0] = head
test node = head->next
while true :
{
if testnode == null:
return

while i<=last
if array[i] == testnode{
    node * previousinlooop = array[last]
    

    for(j=i,j<=last;j++){
        node * nextinloop = new Node;
        nextinloop ->data = array[j]->data
        previousinloop ->next = nextinloop
        previousinloop = nextinloop
        delete nextinloop

            
    }
    previousinloop->next = null
    return head;

    else{i++}
    

last ++
testnode = testnode ->next
array[last] = testnode;

}
*/
#include<iostream>
using namespace std;
/*Driver code starts*/
typedef struct Node{
  int data;
  Node *next;
  
}Node;

Node *insert(Node* end, int val){
  Node *n= new Node;
  n->data=val;
  n->next=NULL;
  end->next=n;
  return n;
}

void loopHere(Node *head, Node *tail, int position){
  if(position==0) return;
  Node *walk=head;
  int i=0;
  while(i<position-1){
    walk=walk->next;
    i++;
  }
  // cout<<walk->data<<'\n';
  tail->next=walk;
}
/*Driver code ends*/


Node *solve(Node *head){
  //your code goes here
  Node * array_of_pointers[100];
  array_of_pointers[0] = head;
  
  Node* testnode = new Node;
  testnode = head -> next;
  int tail_of_array= 0;
  int i ;
  while (true){
    if (testnode == NULL){
        return head;
    }
    i = 0;
    while(i<=tail_of_array){
        if (array_of_pointers[i]==testnode){
            Node* previousInLoop = array_of_pointers[tail_of_array];
            
            for(int j=i;j<=tail_of_array;j++){
                
                Node *NextInLoop = new Node ;
                NextInLoop ->data = (array_of_pointers[j]) ->data;
                previousInLoop ->next = NextInLoop;
                previousInLoop = NextInLoop;
                
            }
            previousInLoop -> next = NULL;
            return head;
        }
        i++;
    }
    tail_of_array ++;
    
    array_of_pointers[tail_of_array] = testnode;
    testnode = testnode ->next;
  }



  
  
}


/*Driver code starts*/
int main(){
  int n;cin>>n;
  Node *head= new Node;
  int temp;cin>>temp;
  head->data=temp;
  head->next=NULL;
  Node *end=head;
  for(int i=1;i<n;i++){
    cin>>temp;
    end=insert(end,temp);
  }

  int position;cin>>position;
  loopHere(head,end,position);

  head=solve(head);
  Node *ptr=head;
  
  while(ptr){
    cout<<ptr->data<<' ';
    ptr=ptr->next;
  }
  
}
/*Driver code ends*/