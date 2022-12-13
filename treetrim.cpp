#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
class MyLinkedList{
    
    private:
        node * head;node* curr; 
    public:
        int lenlist=0;

        MyLinkedList(int len){
            cout<<"hmmmmm"<<endl;
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
            for(int i =1;i<=lenlist;i++){
                cout<<pointer_to_postition(i) ->data<<" ";
            }
            cout<<endl;
            
        }
        void deleteFromList(int elem){//deletes the first instance of an element in the list
            if(head->data==elem){
                node* temp = head;
                if(lenlist-1){
                    head = head->next;
                    delete head;
                    lenlist--;
                    return;
                }
                else{
                    node* temp  = head;
                    head = NULL;
                    delete temp;

                    lenlist--;
                    return;
                }

            }

            for(int i=1;i<lenlist;i++){
                if (pointer_to_postition(i+1)->data == elem){
                    node* temp = pointer_to_postition(i+1);
                    if(i<lenlist-1) pointer_to_postition(i)->next = pointer_to_postition(i+2);
                    else pointer_to_postition(i)->next= NULL;
                    delete temp;
                }
            }
        }
        
};
class Graph{
    private:
        int size;
        MyLinkedList** array_of_lists;
    public:
        Graph(int n){
            size=n;
            array_of_lists = new MyLinkedList*[n];

        }
        int num_edges(){
            int sum=0;
            for(int i=0;i<size;i++){
                sum+=array_of_lists[i]->lenlist;
            }
            return sum;
        }
        int num_vertices_adjacent_to(int vertex){
            return (array_of_lists[vertex-1]->lenlist);
        }
        void add_edge(int a,int b){//vertex can be anything between 1 and n
            if(!(array_of_lists[a-1]->lenlist)){

                MyLinkedList* list = new MyLinkedList(1);
                cout<<"hmm"<<endl;
                list->pointer_to_postition(1)->data= b-1;
                array_of_lists[a-1]= list;


            }
            else{
                cout<<"len  not 0 wtf so seeing"<<endl;
                MyLinkedList* list = new MyLinkedList((array_of_lists[a-1]->lenlist)+1);
                list->pointer_to_postition(1)->data= b-1;
                for(int i=2;i<((array_of_lists[a-1]->lenlist)+1);i++){
                    list->pointer_to_postition(i)->data=array_of_lists[a-1]->pointer_to_postition(i-1)->data;

                }
                array_of_lists[a-1]= list;
            }
            if(!(array_of_lists[b-1])->lenlist){

                MyLinkedList* list = new MyLinkedList(1);
                list->pointer_to_postition(1)->data= a-1;
                array_of_lists[b-1]= list;


            }
            else{
                MyLinkedList* list = new MyLinkedList((array_of_lists[b-1]->lenlist)+1);
                list->pointer_to_postition(1)->data= a-1;
                for(int i=2;i<((array_of_lists[b-1]->lenlist)+1);i++){
                    list->pointer_to_postition(i)->data=array_of_lists[b-1]->pointer_to_postition(i-1)->data;

                }
                array_of_lists[b-1]= list;
            }
        }
        void delete_edge(int a,int b){
            array_of_lists[a-1]->deleteFromList(b-1);
            array_of_lists[b-1]->deleteFromList(a-1);
        }
        void delete_vertex(int a){//assumes one connenction ,ok for here
            int b = array_of_lists[a-1]->pointer_to_postition(1)->data+1;
            array_of_lists[a-1]->deleteFromList(b-1);
            array_of_lists[b-1]->deleteFromList(a-1);

            
        }

};
int main(){
    int n,k;
    cin>>n>>k;
    if(n<=2 && k>0){
        cout<<0<<"\n";
    }
    else{
        Graph* graph = new Graph(n);
        cout<<"graph made"<<endl;
        for(int i=1;i<=n;i++){
            
            int u,v;
            cin>>u>>v;
            graph->add_edge(u,v);
        }
        

        for(int _=0;_<k;_++){
            for(int i=1;i<=n;i++){
                if(graph->num_vertices_adjacent_to(i)<=1){
                    graph->delete_vertex(i);
                }
            }
        }
        cout<<graph->num_edges()<<"\n";
    }

}